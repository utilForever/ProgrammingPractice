module Part1 where

data Item = Item { name :: String, description :: String, weight :: Int, value :: Int }
 deriving ( Show )

type Items = [Item]

testCase1 = describe items

describe :: Items -> IO ()
describe = mapM_ (putStrLn . toString)

toString :: Item -> String
toString item = "Name        = " ++ name item ++ "\n" ++
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

items = [Item { name = "Excalibur", description = "The legendary sword of King Arthur", weight = 12, value = 1024 }, Item { name = "Steel Armor", description = "Protective covering made by steel", weight = 15, value = 805 }]