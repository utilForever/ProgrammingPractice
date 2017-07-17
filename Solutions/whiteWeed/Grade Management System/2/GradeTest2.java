/**
 * 
 */
package whiteWeed.gradeManage;

import java.util.*;

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
public class GradeTest2 { //ㅁㄴㅇㄹ
	
	private static Scanner sc = new Scanner(System.in);
	private static List<Grade2> gradeArray = new ArrayList<Grade2>();
	private static Map<Integer, Short> gradeSums = new HashMap<Integer, Short>();
	
	public static void main(String[] args) {
		boolean end = true;
		while(end){
			end = menuSelect();
		}
		sc.close();
	}
	
	private static boolean menuSelect(){
		System.out.println(" - Menu select -");
		System.out.println("    1. Input Student's grade");
		System.out.println("    2. Print Student's grade");
		System.out.println("    3. Exit");
		System.out.println();
		System.out.print("Select : ");
		int index = sc.nextInt();
		sc.reset();
		System.out.println();
		
		boolean end = true;
		
		switch(index){
		case 1:
			while(end){
				end = input();
			}
			return true;
		case 2:
			print();
			return true;
		case 3:
			return false;
		default:
			return true;
		}
	}
	
	private static boolean input(){
		byte[] score = {0, 0, 0};
		short sum = 0;
		float average;
		String[] subs = {"> Name : ", "> Korean : ", "> English : ", "> Math : "}, args = {null, null, null, null};
		
		for(int i = 0; i < 4; i++){
			System.out.print(subs[i]);
			args[i] = sc.next();
			sc.reset();
		}
		
		for(int i = 0; i < 3; i++){
			score[i] = Byte.parseByte(args[i + 1]);
			sum += score[i];
		}
		
		average = (float)sum/3;
		gradeArray.add(new Grade2(args[0], score, sum, average));
		System.out.println();
		System.out.print("> Do you continue to input (Y/N)? ");
		String index = sc.next();
		sc.reset();
		
		switch(index){
		case "Y":
			return true;
		case "N":
			return false;
		default:
			return false;
		}
	}
	
	private static void print(){
		for(int i = 0; i < Grade2.studentCnt; i++){
			gradeSums.put(i, gradeArray.get(i).getSum());
		}
		
		for(int i = 0; i < Grade2.studentCnt; i++){
			for(int j = i + 1; j < Grade2.studentCnt; j++){
				if(gradeSums.get(i) < gradeSums.get(j)){
					short tmp;
					tmp = gradeSums.get(i);
					gradeSums.replace(i, gradeSums.get(j));
					gradeSums.replace(j, tmp);
				}
			}
			gradeArray.get(i).setRank((short)(i + 1));
		}
		
		System.out.println(String.format("%-10s", "Name") + String.format("%-6s", "Kor") + String.format("%-6s", "Eng")
		 + String.format("%-6s", "Math") + String.format("%-6s", "Sum") + String.format("%-6s", "Avg")
		 + String.format("%-6s", "Rank"));
		System.out.println("============================================");
		for(Grade2 grade : gradeArray){
			System.out.println(grade);
		}
		System.out.println("============================================");
		System.out.print(String.format("%-10s", "Sum"));
		for(int i = 0; i < 4; i++){
			System.out.print(String.format("%-6d", Grade2.scoreSum[i]));
		}
		System.out.println();
		System.out.print(String.format("%-10s", "Avg"));
		for(int i = 0; i < 4; i++){
			System.out.print(String.format("%-6.1f", (float)Grade2.scoreSum[i]/Grade2.studentCnt));
		}
		System.out.println();
	}
}
