/**
 * 
 */
package whiteWeed.gradeManage;

import java.util.Arrays;

/**
 * <pre>
 * whiteWeed.gradeManage
 *   |_GradeTest
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 5. 18.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class GradeTest {
	public static void main(String[] args) {
		byte[][] scores = {
				{96, 92, 98},
				{88, 90, 68},
				{98, 80, 75},
				{64, 70, 72},
				{80, 88, 94}
		};
		
		int[] sumss = {0, 0, 0};
		
		Grade[] grades = {
				new Grade("John", scores[0]),
				new Grade("Chris", scores[1]),
				new Grade("James", scores[2]),
				new Grade("Tom", scores[3]),
				new Grade("Jane", scores[4]),
		};
		
		int sum = 0;
		
		short[] sums = {0, 0, 0, 0, 0};
		
		for(int i = 0; i < 5; i++){
			sums[i] = grades[i].getSum();
		}
		
		Arrays.sort(sums);
		
		short temp;

	    for (int i = 0; i < sums.length / 2; i++) {
	      temp = sums[i];
	      sums[i] = sums[(sums.length - 1) - i];
	      sums[(sums.length - 1) - i] = temp;
	    }
		
		for(short i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(sums[i] == grades[j].getSum()){
					grades[j].setRank((short)(i + 1));
				}
			}
		}
		
		System.out.println(String.format("%-10s", "Name") + String.format("%-6s", "Kor") + String.format("%-6s", "Eng")
									 + String.format("%-6s", "Math") + String.format("%-6s", "Sum") + String.format("%-6s", "Avg")
									 + String.format("%-6s", "Rank"));
		System.out.println("============================================");
		for(Grade grade : grades){
			System.out.println(grade);
		}
		System.out.println("============================================");
		for(int i = 0; i < 3; i++){
			for(Grade grade : grades){
				sumss[i] += grade.scores[i];
			}
			sum += sumss[i];
		}
		System.out.println(String.format("%-10s", "Sum") + String.format("%-6d", sumss[0]) + String.format("%-6d", sumss[1])
		+ String.format("%-6d", sumss[2]) + String.format("%-6d", sum));
		System.out.println(String.format("%-10s", "Avg") + String.format("%-6.1f", (float)sumss[0]/5) + String.format("%-6.1f", (float)sumss[1]/5)
		+ String.format("%-6.1f", (float)sumss[2]/5) + String.format("%-6.1f", (float)sum/5));
	}
}
