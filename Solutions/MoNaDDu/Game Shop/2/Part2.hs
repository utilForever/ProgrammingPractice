module Part2 where

data Item = Item { name :: String, description :: String, weight :: Int, value :: Int } |
            Weapon { name :: String, description :: String, weight :: Int, value :: Int, damage :: Int } |
            Armor { name :: String, description :: String, weight :: Int, value :: Int, defense :: Int }
 deriving ( Show )

type Items = [Item]

testCase1 = describe items

describe :: Items -> IO ()
describe = mapM_ (putStrLn . toString)

toString :: Item -> String
toString (Item name description weight value) = baseInfo (Item name description weight value)
toString (Weapon name description weight value damage) = baseInfo (Item name description weight value) ++
                                                         "Damage      = " ++ show damage ++ "\n"
toString (Armor name description weight value defense) = baseInfo (Item name description weight value) ++
                                                         "Defense     = " ++ show defense ++ "\n"

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

items = [
    Weapon { name = "Excalibur", description = "The legendary sword of King Arthur", weight = 12, value = 1024, damage = 24 },
    Armor { name = "Steel Armor", description = "Protective covering made by steel", weight = 15, value = 805, defense = 18}
    ]