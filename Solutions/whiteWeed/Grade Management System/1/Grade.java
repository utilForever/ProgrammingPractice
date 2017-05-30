/**
 * 
 */
package whiteWeed.gradeManage;

/**
 * <pre>
 * whiteWeed.gradeManage
 *   |_Grade
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 5. 18.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Grade {
	private String name;
	public byte[] scores;
	private short sum = 0, rank;
	private float average;
	
	public Grade(String name, byte[] scores){
		this.name = name;
		this.scores = scores;
		for(byte score : scores){
			this.sum += score;
		}
		this.average = (float)this.sum/3;
	}
	
	public short getSum(){
		return sum;
	}
	
	public void setRank(short rank){
		this.rank = rank;
	}
	
	public String toString(){
		return String.format("%-10s", this.name) + String.format("%-6d", this.scores[0]) + String.format("%-6d", this.scores[1])
					+ String.format("%-6d", this.scores[2]) + String.format("%-6d", this.sum) + String.format("%-6.1f", this.average)
					+ String.format("%-3d", this.rank);
	}
}
