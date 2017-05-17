## 과제 설명

지금부터 단계별로 진행하며 상점을 구현해 볼 예정이다.

첫 과제로 아이템을 만들어 보기로 한다.

아이템 클래스를 생성하고, 무기와 방어구를 위한 클래스를 생성한다.

상속과 다형성, 오버라이딩을 생각하며 작성해 보자.

## 명세

- 아이템을 위한 `Item` 클래스를 생성한다.
   - 다음 멤버 변수를 갖는다.
      - `name` : 아이템 이름
      - `description` : 아이템 설명
      - `weight` : 아이템 무게
      - `value` : 아이템 가격
   - 다음 멤버 함수를 갖는다.
      - `Item(name, description, weight, value)` : 매개 변수로 아이템 이름/설명/무게/가격을 받는 생성자
      - `Describe()` : 아이템 정보를 출력하는 함수
- 무기 아이템을 위한 `Weapon` 클래스를 생성한다.
   - `Item` 클래스로부터 상속을 받는다.
   - 다음 멤버 변수를 갖는다.
      - `damage` : 무기 데미지
   - 다음 멤버 함수를 갖는다.
      - `Weapon(name, description, weight, value, damage)` : 매개 변수로 아이템 이름/설명/무게/가격/데미지를 받는 생성자
      - `Describe()` : 아이템 정보를 출력하는 함수
- 방어구 아이템을 위한 `Armor` 클래스를 생성한다.
   - `Item` 클래스로부터 상속을 받는다.
   - 다음 멤버 변수를 갖는다.
      - `defense` : 방어력
   - 다음 멤버 함수를 갖는다.
      - `Armor(name, description, weight, value, defense)` : 매개 변수로 아이템 이름/설명/무게/가격/방어력을 받는 생성자
      - `Describe()` : 아이템 정보를 출력하는 함수

## 실행 결과

```
Name        = Excalibur
Description = The legendary sword of King Arthur
Weight      = 12 lbs
Value       = 1024 gold coins
Damage      = 24

Name        = Steel Armor
Description = Protective covering made by steel
Weight      = 15 lbs
Value       = 805 gold coins
Defense     = 18
```