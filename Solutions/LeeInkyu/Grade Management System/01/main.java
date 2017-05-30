/**
 * Created by Inkyu Lee on 2017-05-20.
 */
import java.util.Scanner;

public class main {
    final static int STD_ARR_MAX = 5; //최대 학생 수

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        Byte[] inputTmp = new Byte[3]; //국영수 점수 입력값 임시 배열
        String nameTmp; //이름 입력값 임시 문자열

        Student std[]; //학생 정보를 담은 객체
        std = new Student[STD_ARR_MAX];

        StudentHandler handler = new StudentHandler();

        for(int i=0; i<STD_ARR_MAX; i++)
        {
            System.out.println("이름을 입력하세요. ");
            nameTmp = sc.nextLine();
            for(int j=0; j<3; j++)
            {
                System.out.println("점수를 입력하세요. ");
                inputTmp[j] = sc.nextByte();
            }
            std[i]=new Student(nameTmp, inputTmp[0], inputTmp[1], inputTmp[2]);
            //Student 객체 생성
            sc.nextLine(); //버퍼 비우기
        }

        handler.GetRank(std); //학생들 순위 매기기
        handler.PrintStudentInfo(std); //정보 출력하기

    }
}
