## 과제 설명

상점은 만들었는데 판매할 아이템이 너무 없다. (영양실조 걸린 상점도 아니고...)

지금은 아이템이 각각 5개 밖에 없지만, 이후에 더 많은 아이템이 생길 것이다.

수많은 아이템 정보를 코드에 하나씩 넣는 작업은 너무 노가다(?)스럽다.

그래서 기획자랑 협의를 통해 아이템 정보를 텍스트 파일에 저장한 뒤, 불러오기로 결정했다.

기획자는 두 개의 텍스트 파일에 각각 5개의 아이템 정보를 저장해 우리에게 전달해줬다.

이제 우리 차례다. 텍스트 파일로부터 아이템 정보를 불러올 수 있도록 코드를 변경해 보자.

## 명세

- 기획자가 전달한 텍스트 파일은 다음과 같이 구성되어 있다.
   - equip_item.txt : 장비 아이템에 대한 정보가 들어 있는 텍스트 파일
      - 파일 내용 구성 : 아이템 타입 / 이름 / 설명 / 무게 / 가격 / 공격력(무기) 또는 방어력(방어구)
      ```
      "Weapon", "Sword", "Medium DMG", 3, 10, 10
      "Armor", "Cap", "Light Armor", 1, 5, 5
      "Armor", "Gloves", "Light Armor", 1, 5, 5
      "Weapon", "Axe", "High DMG", 5, 15, 15
      "Armor", "Boots", "Light Armor", 1, 5, 5
      ```
   - potion_item.txt : 포션 아이템에 대한 정보가 들어 있는 텍스트 파일
      - 파일 내용 구성 : 아이템 타입 / 이름 / 설명 / 무게 / 가격 / 포션 타입 / 회복량
      ```
      "Potion", "Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100
      "Potion", "Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50
      "Potion", "Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200
      "Potion", "Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100
      "Potion", "Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300
      ```
- `Shop` 클래스에 파일 이름과 입력 파일 스트림을 위한 변수를 추가한다.
- `Shop` 클래스에 파일 이름을 매개 변수로 받는 생성자를 추가하고, 소멸자를 변경한다.
   - 생성자 `Shop(name, fileName);`를 추가한다.
   - 위 생성자에서 파일을 열고, 열리지 않았을 경우 예외를 던진다.
   - 소멸자에서는 열여뒀던 파일 스트림을 닫는다.
- `Shop` 클래스에 파일로부터 데이터를 읽어오는 함수를 추가한다.
   - 함수 `ReadDataFromFile()`를 추가한다.
   - 파일 스트림에서 한 줄씩 읽은 뒤, 공백을 제거하고 `,`을 기준으로 분리한다.
   - 아이템 타입에 따라 내용이 다르므로, 데이터를 받을 때 주의해야 한다.
   - 읽은 한 줄의 데이터를 모두 분리했다면, 아이템 타입에 따라 알맞게 저장한다.
   - 아이템 타입이 `Weapon` / `Armor` / `Potion` 중 하나가 아니라면, 예외를 던진다.

## 실행 결과

```
- Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 1

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Exit

Select : 1

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

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Exit

Select : 2

- Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 3
```