/**
 * 
 */
package whiteWeed.gradeManage;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * <pre>
 * whiteWeed.gradeManage
 *   |_GradeTest2
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 6. 2.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class GradeTest2 {
	
	private static Scanner sc = new Scanner(System.in);
	private static List<Grade2> gradeArray = new ArrayList<Grade2>();
	private static List<Short> gradeSums = new ArrayList<Short>();
	
	public static void main(String[] args) {
		menuSelect();
		sc.close();
	}
	
	private static void menuSelect(){
		System.out.println(" - Menu select -");
		System.out.println("    1. Input Student's grade");
		System.out.println("    2. Print Student's grade");
		System.out.println("    3. Exit");
		System.out.println();
		System.out.print("Select : ");
		int index = sc.nextInt();
		sc.reset();
		System.out.println();
		switch(index){
		case 1:
			input();
			menuSelect();
			break;
		case 2:
			print();
			menuSelect();
			break;
		case 3:
			break;
		}
	}
	
	private static void input(){
		byte[] score = {0, 0, 0};
		short sum = 0;
		float average;
		System.out.print("> Name : ");
		String name = sc.next();
		sc.reset();
		System.out.print("> Korean : ");
		score[0] = sc.nextByte();
		sc.reset();
		sum += score[0];
		System.out.print("> English : ");
		score[1] = sc.nextByte();
		sc.reset();
		sum += score[1];
		System.out.print("> Math : ");
		score[2] = sc.nextByte();
		sc.reset();
		sum += score[2];
		average = (float)sum/3;
		gradeArray.add(new Grade2(name, score, sum, average));
		System.out.println();
		System.out.print("> Do you continue to input (Y/N)? ");
		String index = sc.next();
		
		switch(index){
		case "Y":
			input();
			break;
		case "N":
			break;
		}
	}
	
	private static void print(){
		int[] sums = {0, 0, 0, 0};
		
		for(Grade2 grade : gradeArray){
			gradeSums.add(grade.getSum());
		}
		gradeSums.toArray();
		
		for(int i = gradeArray.size()-1; i >= 0; i--){
			for(int j = 0; j <= gradeArray.size()-1; j++){
				short sum1 = gradeSums.get(i);
				Grade2 grade1 = gradeArray.get(j);
				if(sum1 == (grade1.getSum())){
					grade1.setRank((short)(i + 1));
				}
			}
		}
		
		System.out.println(String.format("%-10s", "Name") + String.format("%-6s", "Kor") + String.format("%-6s", "Eng")
		 + String.format("%-6s", "Math") + String.format("%-6s", "Sum") + String.format("%-6s", "Avg")
		 + String.format("%-6s", "Rank"));
		System.out.println("============================================");
		for(Grade2 grade : gradeArray){
			System.out.println(grade);
		}
		System.out.println("============================================");
		for(Grade2 grade : gradeArray){
			for(int i = 0; i < 3; i++){
				sums[i] += grade.score[i];
				sums[3] += grade.score[i];
			}
		}
		System.out.println(String.format("%-10s", "Sum") + String.format("%-6d", sums[0]) + String.format("%-6d", sums[1])
		+ String.format("%-6d", sums[2]) + String.format("%-6d", sums[3]));
		System.out.println(String.format("%-10s", "Avg") 
		+ String.format("%-6.1f", (float)sums[0]/Grade2.studentCnt) + String.format("%-6.1f", (float)sums[1]/Grade2.studentCnt)
		+ String.format("%-6.1f", (float)sums[2]/Grade2.studentCnt) + String.format("%-6.1f", (float)sums[3]/Grade2.studentCnt));
	}
}
