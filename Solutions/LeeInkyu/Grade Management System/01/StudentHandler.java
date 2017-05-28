/**
 * Created by Inkyu Lee on 2017-05-20.
 */


public class StudentHandler {

    final static int STD_ARR_MAX = 5;

    short koreanScoreSum=0, mathScoreSum=0, englishScoreSum=0;

    public void GetRank(Student[] stdPm) //각 학생별 순위 구하기
    {
        short cnt;

        for(int i=0; i<STD_ARR_MAX; i++)
        {
            cnt = 0;
            for(int j=0; j<STD_ARR_MAX; j++)
            {
                if(stdPm[i].average >= stdPm[j].average)
                {
                    cnt++;
                }
                stdPm[i].rank = (short)(6-cnt);
            }
        }
        return;
    }

    public void PrintStudentInfo(Student[] stdPm) //학생들 정보 출력하기
    {
        System.out.printf("%5s %3s %3s %3s %3s %4s %2s\n","이름","국어","수학","영어","합계","평균","석차");
        for(int i=0; i<STD_ARR_MAX; i++)
        {
            stdPm[i].PrintInfo();
        }

        for(int i=0; i<STD_ARR_MAX; i++)
        {
            this.koreanScoreSum += stdPm[i].koreanScore;
            this.mathScoreSum += stdPm[i].mathScore;
            this.englishScoreSum += stdPm[i].englishScore;
        }
        System.out.printf("%5s %3d %3d %3d\n","합계", this.koreanScoreSum, this.mathScoreSum, this.englishScoreSum);
        System.out.printf("%5s %3.1f %3.1f %3.1f\n","평균", this.koreanScoreSum/5.0F, this.mathScoreSum/5.0F, this.englishScoreSum/5.0f);
    }

}
