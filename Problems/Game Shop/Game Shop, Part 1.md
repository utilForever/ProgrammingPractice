## 과제 설명

지금부터 단계별로 진행하며 상점을 구현해 볼 예정이다.

첫 과제로 아이템을 만들어 보기로 한다.

아이템에 관한 정보를 저장하는 Item 클래스를 생성한다.

클래스에 대한 기본 개념, 멤버 변수와 멤버 함수를 생각하며 작성해 보자.

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

## 실행 결과

```
Name        = Excalibur
Description = The legendary sword of King Arthur
Weight      = 12 lbs
Value       = 1024 gold coins

Name        = Steel Armor
Description = Protective covering made by steel
Weight      = 15 lbs
Value       = 805 gold coins
```