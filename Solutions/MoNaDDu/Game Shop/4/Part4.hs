module Part4 where

import Control.Monad
import Control.Applicative
import Data.Char

data Item = Item { name :: String, description :: String, weight :: Int, value :: Int } |
            Weapon { name :: String, description :: String, weight :: Int, value :: Int, damage :: Int } |
            Armor { name :: String, description :: String, weight :: Int, value :: Int, defense :: Int } |
            Potion { name :: String, description :: String, weight :: Int, value :: Int, potionType :: PotionType, capacity :: Int }
 deriving ( Show )

data PotionType = HP | MP

instance Show PotionType where
    show HP = "Health"
    show MP = "Mana"

data Shop = Shop { shopName :: String, shopItems :: Items }

type Items = [Item]
type Shops = [Shop]

-- main 함수
main :: IO ()
main = do
    shops <- loadShops shopInformation
    selectShop shops

getInt :: IO Int
getInt = fmap read getLine :: IO Int

selectShop :: Shops -> IO ()
selectShop shops = do
    putStrLn "- Shop Select -"
    putStrLn "   1. Weapon/Armor Shop"
    putStrLn "   2. Potion Shop"
    putStrLn "   3. Exit\n"
    putStr "Select : "
    input <- getInt
    putStrLn ""
    let shopCount = 1 + length shops
    if input == shopCount then return () else do
            if input < shopCount then playShop (shops !! (input - 1)) else putStrLn "Invalid number! Try again.\n"
            selectShop shops

playShop :: Shop -> IO ()
playShop s = do
    let welcomeMessage = "Welcome to " ++ shopName s ++ " Shop!"
    putStrLn welcomeMessage
    replicateM_ (length welcomeMessage) (putStr "-")
    putStrLn ""
    putStrLn "   1. Show Item List"
    putStrLn "   2. Exit\n"
    putStr "Select : "
    input <- getInt
    putStrLn ""
    if input == 2 then return () else do
        case input of
            1 -> showItemList s
            _ -> putStrLn "Invalid number! Try again.\n"
        playShop s

-- Item 관련 함수
describe :: Items -> IO ()
describe = mapM_ (putStrLn . toString)

toString :: Item -> String
toString (Item name description weight value) = baseInfo (Item name description weight value)
toString (Weapon name description weight value damage) = baseInfo (Item name description weight value) ++
                                                         "Damage      = " ++ show damage ++ "\n"
toString (Armor name description weight value defense) = baseInfo (Item name description weight value) ++
                                                         "Defense     = " ++ show defense ++ "\n"
toString (Potion name description weight value potionType capacity) = baseInfo (Item name description weight value) ++
                                                                      "Type         = " ++ show potionType ++ "\n" ++
                                                                      "Capacity     = " ++ show capacity ++ "\n"

baseInfo :: Item -> String
baseInfo item = "Name        = " ++ name item ++ "\n" ++
                "Description = " ++ description item ++ "\n" ++
                "Weight      = " ++ w'' ++ "\n" ++
                "value       = " ++ v'' ++ "\n"
                where 
                w = weight item
                v = value item
                w' = show w
                v' = show v
                w''
                 | w > 1 = w' ++ " lbs"
                 | otherwise = w' ++ " lb"
                v''
                 | v > 1 = v' ++ " gold coins"
                 | otherwise = v' ++ " gold coin"

-- Shop 관련 함수
showItemList :: Shop -> IO ()
showItemList shop = do
    putStrLn $ "Welcom to " ++ shopName shop ++ "!\n"
    describe $ shopItems shop

-- Basic Parser
newtype Parser a = P (String -> [(a, String)])

instance Functor Parser where
    -- fmap :: (a -> b) -> Parser a -> Parser b
    fmap g p = P (\inp -> case parse p inp of
        [] -> []
        [(v, out)] -> [(g v, out)])

instance Applicative Parser where
    -- pure :: a -> Parser a
    pure v = P (\inp -> [(v, inp)])

    -- <*> :: Parser (a -> b) -> Parser a -> Parser b
    pg <*> px = P (\inp -> case parse pg inp of
        [] -> []
        [(g, out)] -> parse (fmap g px) out)

instance Monad Parser where
    -- (>>=) :: Parser a -> (a -> Parser b) -> Parser b
    p >>= f = P (\inp -> case parse p inp of
        [] -> []
        [(v, out)] -> parse (f v) out)        

instance Alternative Parser where
    -- empty :: Parser a
    empty = P (const [])

    -- (<|>) :: Parser a -> Parser a -> Parser a
    p <|> q = P (\inp -> case parse p inp of
        [] -> parse q inp
        [(v, out)] -> [(v, out)])

parse :: Parser a -> String -> [(a, String)]
parse (P p) = p

item :: Parser Char
item = P (\inp -> case inp of
    [] -> []
    (x:xs) -> [(x,xs)])

sat :: (Char -> Bool) -> Parser Char
sat p = do
    x <- item
    if p x then return x else empty

digit :: Parser Char
digit = sat isDigit

char :: Char -> Parser Char
char x = sat (== x)

string :: String -> Parser String
string [] = return []
string (x:xs) = do
    char x
    string xs
    return (x:xs)

nat :: Parser Int
nat = do
    xs <- some digit
    return (read xs)

space :: Parser ()
space = do
    many (sat isSpace)
    return ()

int :: Parser Int
int = do
    char '-'
    n <- nat
    return (-n)
    <|> nat

token :: Parser a -> Parser a
token p = do
    space
    v <- p
    space
    return v

integer :: Parser Int
integer = token int

symbol :: String -> Parser String
symbol xs = token (string xs)

-- Element 데이터 타입 선언
data Element = S String | I Int
    deriving (Eq, Ord, Show, Read)

elementToString :: Element -> String
elementToString (S x) = x
elementToString (I x) = show x

elementToInt :: Element -> Int
elementToInt (I x) = x
elementToInt (S x) = read x

-- CSV Parser
parseCSV :: String -> [Element]
parseCSV xs = case parse csv xs of
    [(n, [])] -> n
    [(_, out)] -> error ("Unused input " ++ out)
    [] -> error "Invalid input"

-- 문법
-- csv ::= factor (, factor | e)
-- factor ::= quotes | int
-- integer ::= ... | -2 | -1 | 0 | 1 | 2 | ...
csv :: Parser [Element]
csv = do
    n <- factor
    ns <- many (do
        symbol ","
        factor)
    return (n:ns)

factor :: Parser Element
factor = do
    xs <- quotes
    return (S xs)
    <|> do
        ns <- integer
        return (I ns)

quotes :: Parser String
quotes = do
    symbol "\""
    xs <- many $ sat (/= '\"')
    symbol "\""
    return xs

-- 파일 입출력
readLines :: FilePath -> IO [String]
readLines = fmap lines . readFile

readCSV :: FilePath -> IO [[Element]]
readCSV fileName = do
    ls <- readLines fileName
    let results = map parseCSV ls
    return results

makeShop :: String -> Items -> Shop
makeShop name items = Shop { shopName = name, shopItems = items }

makeItems :: [[Element]] -> Items
makeItems = map makeItem

makeItem :: [Element] -> Item
makeItem [] = undefined 
makeItem (x:xs)
 | len >= 5 && x == S "Weapon" = Weapon { name = elementToString $ head xs, description = elementToString $ xs !! 1, weight = elementToInt $ xs !! 2, value = elementToInt $ xs !! 3, damage = elementToInt $ xs !! 4 }
 | len >= 5 && x == S "Armor" = Armor  { name = elementToString $ head xs, description = elementToString $ xs !! 1, weight = elementToInt $ xs !! 2, value = elementToInt $ xs !! 3, defense = elementToInt $ xs !! 4 }
 | len >= 6 && x == S "Potion" = Potion  { name = elementToString $ head xs, description = elementToString $ xs !! 1, weight = elementToInt $ xs !! 2, value = elementToInt $ xs !! 3, potionType = makePotionType $ elementToString $ xs !! 4, capacity = elementToInt $ xs !! 5 }
 | otherwise = error "Invalid item"
 where len = length xs

shopInformation = [
    ("Weapon/Armor", "equip_item.txt"),
    ("Potion", "potion_item.txt")
    ]

loadShops :: [(String, FilePath)] -> IO Shops
loadShops = mapM loadShop

loadShop :: (String, FilePath) -> IO Shop
loadShop (shopName, fileName) = do
    elements <- readCSV fileName
    let result = makeShop shopName $ makeItems elements
    return result

makePotionType :: String -> PotionType
makePotionType s
    | s == "Health" = HP
    | s == "Mana" = MP
    | otherwise = error "Invalid string"