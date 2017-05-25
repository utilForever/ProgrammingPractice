(ns game-shop.core)
(defrecord Item [name description weight value])

(defn Describe [item]
  (printf "Name        = %s%n" (:name item))
  (printf "Description = %s%n" (:description item))
  (printf "Weight      = %s lbs%n" (:weight item))
  (printf "Value       = %s gold coins%n" (:value item)))

(def data [(Item. "Excalibur" "The legendary sword of King Arthur" 12 1024)
           (Item. "Steel Armor" "Protective covering made by steel" 15 805)])

(doseq [item data] (Describe item) (println))

