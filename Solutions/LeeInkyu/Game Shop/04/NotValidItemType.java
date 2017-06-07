/**
 * Created by Inkyu Lee on 2017-06-06.
 */
//유효한 타입이 아닐 경우 예외

public class NotValidItemType extends Exception {
	public NotValidItemType() {}
	public NotValidItemType(String strPm)
	{
		super(strPm);
	}
}
