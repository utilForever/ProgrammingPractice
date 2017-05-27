/**
 * Created by Inkyu Lee on 2017-05-20.
 */

//#define STD_ARR_MAX 5

public class StudentHandler {
    final static int STD_ARR_MAX = 5;

    short Ksum=0,Msum=0,Esum=0;

    public void StudentSort(Student[] stdPm) //각 학생별 순위 구하기
    {
        short cnt;

        for(int i=0;i<STD_ARR_MAX;i++)
        {
            cnt=0;
            for(int j=0;j<STD_ARR_MAX;j++)
            {
                if(stdPm[i].average>=stdPm[j].average)
                {
                    cnt++;
                }
                stdPm[i].rank = (short)(6-cnt);
            }
        }
        return;
    }

    public void StudentPrint(Student[] stdPm) //학생들 정보 출력하기
    {
        System.out.printf("%5s %3s %3s %3s %3s %4s %2s\n","이름","국어","수학","영어","합계","평균","석차");
        for(int i=0;i<STD_ARR_MAX;i++)
        {
            stdPm[i].infoPrint();
        }

        for(int i=0;i<STD_ARR_MAX;i++)
        {
            this.Ksum+=stdPm[i].Kscore;
            this.Msum+=stdPm[i].Mscore;
            this.Esum+=stdPm[i].Escore;
        }
        System.out.printf("%5s %3d %3d %3d\n","합계",this.Ksum,this.Msum,this.Esum);
        System.out.printf("%5s %3f %3f %3f\n","평균",this.Ksum/5.0F,this.Msum/5.0F,this.Esum/5.0f);
    }

}
