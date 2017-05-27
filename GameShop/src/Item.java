/**
 * Created by Administrator on 2017-05-22.
 */
public class Item
{
    private String name; // 아이템 이름
    private String description; // 아이템 설명
    private int weight; // 아이템 무게
    private int value; // 아이템 가격

    public Item(String name, String description, int weight, int value)
    {
        this.name=name;
        this.description=description;
        this.weight=weight;
        this.value=value;
    } // 생성자

    public void describe()
    {
        System.out.printf("%-11s = %s\n", "Name", name);
        System.out.printf("%-11s = %s\n", "Description", description);
        System.out.printf("%-11s = %s lbs\n", "Weight", weight);
        System.out.printf("%-11s = %s gold coins\n", "Value", value);
        System.out.println();
    } // 아이템 정보 출력
}