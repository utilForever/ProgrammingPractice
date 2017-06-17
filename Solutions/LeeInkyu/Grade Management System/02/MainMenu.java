// 메인 메뉴를 출력하기 위한 메소드가 있는 클래스입니다.

import java.util.*;

public class MainMenu {

	public MainMenu() {
	}

	public char showMainMenu() {
		Scanner sc = new Scanner(System.in);
		char cinputTmp;
		System.out.println("- Menu Select -");
		System.out.println("1. Input Student's grade");
		System.out.println("2. Print Student's grade");
		System.out.println("3. Exit");
		System.out.printf("Select: ");
		cinputTmp = sc.next().charAt(0);
		return cinputTmp;
	}

	public void inputGrade(ArrayList<Student> studentList) {
		Scanner sc = new Scanner(System.in);
		Byte[] inputTmp = new Byte[3]; //국영수 점수 입력값 임시 배열
		String nameTmp; //이름 입력값 임시 문자열
		char cTmp; // 메뉴에서 문자 입력 저장 임시 문자

		for ( ; ; ) {
			System.out.printf("Name: ");
			nameTmp = sc.nextLine();
			System.out.printf("Korean: ");
			inputTmp[0] = sc.nextByte();
			System.out.printf("Math: ");
			inputTmp[1] = sc.nextByte();
			System.out.printf("English: ");
			inputTmp[2] = sc.nextByte();
			//이름, 점수 입력

			studentList.add(new Student(nameTmp, inputTmp[0], inputTmp[1], inputTmp[2]));
			//Student 객체 생성
			sc.nextLine(); //버퍼 비우기

			System.out.printf("계속? Y/N ");
			cTmp = sc.next().charAt(0);
			if ( cTmp == 'N' ) break;

			sc.nextLine(); //버퍼 비우기
		}

	}

	public void showStudentInfo(ArrayList<Student> studentList, StudentHandler handler) {
		handler.getRank(studentList); //순위 설정
		handler.printStudentInfo(studentList); //핸들러 이용해서 출력
	}
}
