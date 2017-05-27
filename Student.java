/**
 * Created by Inkyu Lee on 2017-05-20.
 */
public class Student {
    String name;
    byte Kscore,Mscore,Escore;
    short sum=0,rank;
    float average;

    public Student(String namePm,byte Kpm,byte Mpm,byte Epm)
    {
        this.name=namePm;
        this.Kscore=Kpm;
        this.Mscore=Mpm;
        this.Escore=Epm;
        //입력부분

        sum+=this.Kscore;
        sum+=this.Mscore;
        sum+=this.Escore;

        average=sum/3.0F;
    }

    public void infoPrint()
    {
        System.out.printf("%5s %3d %3d %3d %3d %3.1f %2d\n",this.name,this.Kscore,this.Mscore,this.Escore,this.sum,this.average,this.rank);
    }
}
