//학생 한 명의 정보를 담은 클래스입니다.

public class Student {
	String name;
	byte koreanScore, mathScore, englishScore;
	short sum = 0, rank;
	float average;

	public Student(String namePm, byte Kpm, byte Mpm, byte Epm) {
		this.name = namePm;
		this.koreanScore = Kpm;
		this.mathScore = Mpm;
		this.englishScore = Epm;
		//입력부분

		sum += this.koreanScore;
		sum += this.mathScore;
		sum += this.englishScore;

		average = sum / 3.0F;
	}

	public void printInfo() {
		System.out.printf("%5s %3d %3d %3d %3d %3.1f %2d\n", this.name, this.koreanScore, this.mathScore, this.englishScore, this.sum, this.average, this.rank);
	}
}
