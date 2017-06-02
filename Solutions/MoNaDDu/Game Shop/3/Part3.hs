module Part2 where

import Control.Monad

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

main :: IO ()
main = do
    printMenu
    input <- getLine
    play $ read input
    Control.Monad.unless (read input == 3) main

printMenu :: IO ()
printMenu = do
    putStrLn "- Shop Select -"
    putStrLn "   1. Weapon/Armor Shop"
    putStrLn "   2. Potion Shop"
    putStrLn "   3. Exit\n"
    putStr "Select : "
    return ()

play :: Int -> IO ()
play n
    | n == 1 = showItemList weaponAndArmorShop
    | n == 2 = showItemList potionShop
    | n == 3 = return ()
    | otherwise = putStrLn "\nInvalid number! Try again.\n"



testCase1 = describe items

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

showItemList :: Shop -> IO ()
showItemList shop = do
    putStrLn $ "Welcom to " ++ shopName shop ++ "!\n"
    describe $ shopItems shop
    putStrLn "\n"

items = [
    Weapon { name = "Excalibur", description = "The legendary sword of King Arthur", weight = 12, value = 1024, damage = 24 },
    Armor { name = "Steel Armor", description = "Protective covering made by steel", weight = 15, value = 805, defense = 18}
    ]

weaponAndArmorShop = Shop { shopName = "Weapon/Armor", shopItems = [
    Weapon { name = "Sword", description = "Medium DMG", weight = 3, value = 10, damage = 10 },
    Armor { name = "Cap", description = "Light Armor", weight = 1, value = 5, defense = 5 },
    Armor { name = "Gloves", description = "Light Armor", weight = 1, value = 5, defense = 5 },
    Weapon { name = "Axe", description = "High Dmg", weight = 5, value = 15, damage = 15 },
    Armor { name = "Boots", description = "Light Armor", weight = 1, value = 5, defense = 5 }
    ] }

potionShop = Shop { shopName = "Potion", shopItems = [
    Potion { name = "Small Health Potion", description = "Recovery 100 HP", weight = 2, value = 5, potionType = HP, capacity = 100 },
    Potion { name = "Small Mana Potion", description = "Recovery 50 MP", weight = 1, value = 30, potionType = MP, capacity = 50 },
    Potion { name = "Medium Health Potion", description = "Recovery 200 HP", weight = 4, value = 120, potionType = HP, capacity = 200 },
    Potion { name = "Medium Mana Potion", description = "Recovery 100 MP", weight = 2, value = 75, potionType = MP, capacity = 100 },
    Potion { name = "Large Health Potion", description = "Recovery 300 HP", weight = 6, value = 200, potionType = HP, capacity = 300 }
    ] }