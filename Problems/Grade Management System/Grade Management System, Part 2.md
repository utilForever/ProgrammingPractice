## 과제 설명

우리는 학생 5명의 성적을 관리하는 프로그램을 만들었다.

하지만 프로그램에 각 학생의 성적을 입력해야 된다는 문제가 있다. 

그리고 반마다 학생수(대개 25-35명)가 다르기 때문에 이에 대한 고려도 해야된다.

기존의 코드를 수정해, 학생 n명의 점수를 입력받아 관리하는 프로그램을 만들어 보자.

배열을 사용해도 좋고, 각 언어에 구현되어 있는 컨테이너를 사용해도 좋다.

배열을 사용할 경우 메모리 동적 할당을 생각하며 작성해 보자.

## 명세

- 학생 n명의 점수를 합산하고 평균과 석차를 구해 출력하는 프로그램을 작성한다.
   - `name` : 이름, `String` 타입
   - `score` : 국어, 영어, 수학 점수, `byte` 타입
   - `sum` : 합계, `short` 타입
   - `average` : 평균, `float` 타입
   - `rank` : 석차, `short` 타입

## 실행 결과

```C++
- Menu Select -
   1. Input Student's grade
   2. Print Student's grade
   3. Exit

Select : 1

> Name : John
> Korean : 96
> English : 92
> Math : 98

> Do you continue to input (Y/N)? Y

> Name : Chris
> Korean : 88
> English : 90
> Math : 68

> Do you continue to input (Y/N)? Y

...

> Name : Jane
> Korean : 80
> English : 88
> Math : 94

> Do you continue to input (Y/N)? N

- Menu Select -
   1. Input Student's grade
   2. Print Student's grade
   3. Exit

Select : 2

Name	Kor	Eng     Math	Sum	Avg	Rank
====================================================
John	96	92	98	286	95.3	1
Chris	88	90	68	246	82.0	4
James	98	80	75	253	84.3	3
Tom	64	70	72	206	68.7	5
Jane	80	88	94	262	87.3	2
====================================================
Sum	426	420	407	1253
Avg	85.2	84.0	81.4	250.6

- Menu Select -
   1. Input Student's grade
   2. Print Student's grade
   3. Exit

Select : 3
```