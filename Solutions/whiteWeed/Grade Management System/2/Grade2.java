/**
 * 
 */
package whiteWeed.gradeManage;

/**
 * <pre>
 * whiteWeed.gradeManage
 *   |_Grade2
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 6. 2.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Grade2 {
	private String name;
	private short sum = 0, rank;
	private float average;
	protected byte[] score;
	public static int studentCnt = 0;
	
	public Grade2(String name, byte[] score, short sum, float average){
		this.name = name;
		this.score = score;
		this.sum = sum;
		this.average = average;
		studentCnt++;
	}
	
	public short getSum(){
		return sum;
	}
	
	public void setRank(short rank){
		this.rank = rank;
	}
	
	public String toString(){
		return String.format("%-10s", this.name) + String.format("%-6d", this.score[0]) + String.format("%-6d", this.score[1])
					+ String.format("%-6d", this.score[2]) + String.format("%-6d", this.sum) + String.format("%-6.1f", this.average)
					+ String.format("%-3d", this.rank);
	}
}
