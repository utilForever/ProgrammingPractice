## 과제 설명

우리는 첫번째 과제로 아이템 클래스를 만들었다.

하지만 모든 아이템이 똑같지는 않다. 종류에 따라 고유의 특성을 갖는다.

예를 들어, 무기는 종류에 따라 입힐 수 있는 데미지(피해량)을 갖는다.

또한 방어구는 종류에 따라 피해를 줄일 수 있는 방어력을 갖는다.

따라서 Item 클래스를 기반으로 상속을 받는 Weapon 클래스와 Armor 클래스를 만든다.

상속과 다형성, 오버라이딩을 생각하며 작성해 보자.

## 명세

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

### 테스트 코드 예시 (C++)
```C++
int main()
{
	Item* item = new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24);
	item->Describe();

	item = new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18);
	item->Describe();
}
```

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