## 과제 설명

총을 쏘려면 총알이 필요하듯이, 전투를 하려면 아이템이 필요하다.

문제는 아이템은 있는데, 구입할 수 있는 곳이 없다.

맨몸으로 전투에 임할 플레이어가 안타까우니, 상점을 만들어 주도록 하자.

우선 상점에 판매하는 아이템 목록만 보여줄 수 있도록 구현하자.

아 참, 장비만 있으면 아쉬우니 포션도 만들어 보자.

## 명세

- 포션을 위한 `Potion` 클래스를 생성한다.
   - `Item` 클래스로부터 상속을 받는다.
   - 다음 멤버 변수를 갖는다.
      - `type` : 포션 타입 (HP / MP 등)
      - `capacity` : 포션 용량
   - 나머지 부분은 `Weapon`, `Armor` 클래스와 유사하게 작성한다.
- 상점을 위한 `Shop` 클래스를 생성한다.
   - 다음 멤버 변수를 갖는다.
      - `name` : 상점 이름
      - `items` : 상점에서 보유하고 있는 아이템 목록
   - 다음 멤버 함수를 갖는다.
      - `Shop(name, items)` : 매개 변수로 상점 이름과 아이템 목록을 받는 생성자
      - `ShowItemList()` : 아이템 목록을 보여주는 함수

## 실행 결과

```
- Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 1

Welcome to Weapon/Armor Shop!
- Item List -
Name        = Sword
Description = Medium DMG
Weight      = 3 lbs
Value       = 10 gold coins
Damage      = 10

Name        = Cap
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

Name        = Gloves
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

Name        = Axe
Description = High DMG
Weight      = 5 lbs
Value       = 15 gold coins
Damage      = 15

Name        = Boots
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

- Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 2

Welcome to Potion Shop!
- Item List -
Name        = Small Health Potion
Description = Recovery 100 HP
Weight      = 2 lbs
Value       = 5 gold coins
Type        = Health
Capacity    = 100

Name        = Small Mana Potion
Description = Recovery 50 MP
Weight      = 1 lbs
Value       = 30 gold coins
Type        = Mana
Capacity    = 50

Name        = Medium Health Potion
Description = Recovery 200 HP
Weight      = 4 lbs
Value       = 120 gold coins
Type        = Health
Capacity    = 200

Name        = Medium Mana Potion
Description = Recovery 100 MP
Weight      = 2 lbs
Value       = 75 gold coins
Type        = Mana
Capacity    = 100

Name        = Large Health Potion
Description = Recovery 300 HP
Weight      = 6 lbs
Value       = 200 gold coins
Type        = Health
Capacity    = 300

 - Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit
   
Select : 0

Invalid number! Try again.

 - Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 3
```