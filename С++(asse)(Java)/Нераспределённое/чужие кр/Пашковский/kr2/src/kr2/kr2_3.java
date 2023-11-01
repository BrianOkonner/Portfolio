package kr2;

import java.io.FileNotFoundException;
import java.io.PrintStream;

class wrongSold extends Exception{}
class wrongNumber extends Exception{}
enum Type{����,�����,����}

class sold
{
	protected static int count=0;
	protected int id;
	protected String name;
	protected final Type type;
	protected double amSold;
	protected String vendor;
	protected String makler;
	sold(String name,Type type, double amSold, String vendor,String makler) throws wrongSold
	{
		if(amSold<0)
			throw new wrongSold();
		count++;
		id=count;
		this.type=type;
		this.name=name;
		this.amSold=amSold;
		this.vendor=vendor;
		this.makler=makler;
	}
	public String getName()
	{
		return name;
	}
	public Type getType()
	{
		return type;
	}
	public double getAmSold()
	{
		return amSold;
	}
	public String getVendor()
	{
		return vendor;
	}
	public String getMakler()
	{
		return makler;
	}
	public void setAmSold(double n)
	{
		this.amSold=n;
	}
	public int getcount()
	{
		return count;
	}
	public String toString()
	{
		return "id="+id+"\n��������: "+name+"\n���: "+type+"\n���������� ����������: "+amSold+
				"\n���������: "+vendor+"\n������: "+makler+"\n";
	}
}
class market extends sold
{
	market(String name,Type type, double amSold, String vendor,String makler) throws wrongSold
	{
		super(name,type,amSold,vendor,makler);
	}
}
public class kr2_3 {

	public static void main(String[] args) throws FileNotFoundException {
		PrintStream printFile=new PrintStream("output.txt");

	}

}
