//학생 정보를 관리하는 핸들러입니다.

import java.util.*;


public class StudentHandler {

	//int STD_ARR_MAX = 5;

	short koreanScoreSum = 0, mathScoreSum = 0, englishScoreSum = 0;

	public StudentHandler() {}


	public void getRank(Student[] stdPm) //각 학생별 순위 구하기 (배열)
	{
		short cnt;

		for ( int i = 0; i < stdPm.length; i++ ) {
			cnt = 0;
			for ( int j = 0; j < stdPm.length; j++ ) {
				if ( stdPm[i].average >= stdPm[j].average ) {
					cnt++;
				}
				stdPm[i].rank = (short) ((stdPm.length + 1) - cnt);
			}
		}
	}

	public void getRank(ArrayList<Student> stdPm) //각 학생별 순위 구하기 (어레이리스트)
	{
		short cnt;
		for ( int i = 0; i < stdPm.size(); i++ ) {
			cnt = 0;
			for ( int j = 0; j < stdPm.size(); j++ ) {
				if ( stdPm.get(i).average >= stdPm.get(j).average ) {
					cnt++;
				}
				stdPm.get(i).rank = (short) ((stdPm.size() + 1) - cnt);
			}
		}
	}

	public void printStudentInfo(Student[] stdPm) //학생들 정보 출력하기 (배열)
	{
		koreanScoreSum = 0;
		mathScoreSum = 0;
		englishScoreSum = 0;

		System.out.printf("%5s %3s %3s %3s %3s %4s %2s\n", "이름", "국어", "수학", "영어", "합계", "평균", "석차");
		for ( int i = 0; i < stdPm.length; i++ ) {
			stdPm[i].printInfo();
			this.koreanScoreSum += stdPm[i].koreanScore;
			this.mathScoreSum += stdPm[i].mathScore;
			this.englishScoreSum += stdPm[i].englishScore;
		}

		System.out.printf("%5s %3d %3d %3d\n", "합계", this.koreanScoreSum, this.mathScoreSum, this.englishScoreSum);
		System.out.printf("%5s %3.1f %3.1f %3.1f\n", "평균", this.koreanScoreSum / (float) stdPm.length, this.mathScoreSum / (float) stdPm.length, this.englishScoreSum / (float) stdPm.length);
	}

	public void printStudentInfo(ArrayList<Student> stdPm) //학생들 정보 출력하기 (어레이리스트)
	{
		koreanScoreSum = 0;
		mathScoreSum = 0;
		englishScoreSum = 0;

		System.out.printf("%5s %3s %3s %3s %3s %4s %2s\n", "이름", "국어", "수학", "영어", "합계", "평균", "석차");
		for ( int i = 0; i < stdPm.size(); i++ ) {
			stdPm.get(i).printInfo();
			this.koreanScoreSum += stdPm.get(i).koreanScore;
			this.mathScoreSum += stdPm.get(i).mathScore;
			this.englishScoreSum += stdPm.get(i).englishScore;
		}
		System.out.printf("%5s %3d %3d %3d\n", "합계", this.koreanScoreSum, this.mathScoreSum, this.englishScoreSum);
		System.out.printf("%5s %3.1f %3.1f %3.1f\n", "평균", this.koreanScoreSum / (float) stdPm.size(), this.mathScoreSum / (float) stdPm.size(), this.englishScoreSum / (float) stdPm.size());

	}
}
