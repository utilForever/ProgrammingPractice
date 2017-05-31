/**
 * Created by Inkyu Lee on 2017-05-20.
 */

import java.util.*;

public class main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		ArrayList<Student> studentList = new ArrayList<Student>(); //Student 클래스 어레이리스트 생성
		StudentHandler studentHandler = new StudentHandler(); //학생 정보 관리 핸들러
		MenuHandler menuHandler = new MenuHandler(); //메인 메뉴 출력 핸들러

		char cTmp;

		MAIN_MENU:
		for ( ; ; ) {
			cTmp = menuHandler.showMainMenu(); //메인메뉴 출력

			switch ( cTmp ) {
				case '1': //정보 입력
					menuHandler.inputGrade(studentList);
					break;
				case '2': //정보 출력
					menuHandler.showStudentInfo(studentList, studentHandler);
					break;
				case '3': //프로그램 종료
					break MAIN_MENU;
				default: //예외처리
					System.out.println("잘못된 입력입니다.");
			}
		}
	}
}
