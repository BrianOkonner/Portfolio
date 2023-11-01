package app;

import java.util.Arrays;
import java.util.Comparator;



class Pcmp implements Comparator<triangle>
{
	@Override
	public int compare(triangle t1,triangle t2)
	{
		if(t1.P()==t2.P())
			return 0;
		if(t1.P()>t2.P())
			return -1;
		return 1;
	}
}
class triangle{
	private double t[]=new double[3];
	public triangle()
	{
		t[0]=1;
		t[1]=1;
		t[2]=1;
	}
	public triangle(double x,double y,double z)
	{
		if(x+y<=z || y+z<=x || x+z<=y)
			System.out.println("�������� �������!");
		else
		{
			t[0]=x;
			t[1]=y;
			t[2]=z;
		}
		this.sort();
	}
	public triangle(double x,double y)
	{
		t[0]=x;
		t[1]=y;
		t[2]=Math.sqrt(x*x+y*y);
		this.sort();
	}
	public triangle(double x)
	{
		t[0]=x;
		t[1]=x;
		t[2]=x;
	}
	private void sort()
	{
		for(int i=0;i<2;i++)
			if(t[i]>t[i+1])
			{
				double temp=t[i];
				t[i]=t[i+1];
				t[i+1]=temp;
			}
		if(t[0]>t[1])
		{
			double temp=t[0];
			t[0]=t[1];
			t[1]=temp;
		}
	}
	public double geta()
	{
		return this.t[0];
	}
	public double getb()
	{
		return this.t[1];
	}
	public double getc()
	{
		return this.t[2];
	}
	public void set(double x)
	{
		double temp=t[0];
		this.t[0]=x;
		this.sort();
		if(t[0]+t[1]<=t[2])
		{
			t[0]=temp;
			System.out.println("�������� ������!");
		}
	}
	public double P()
	{
		return (this.t[0]+this.t[1]+this.t[2]);
	}
	public double square()
	{
		return Math.sqrt(this.P()/2*(this.P()/2-t[0])*(this.P()/2-t[1])*(this.P()/2-t[2]));
	}
	public int type()
	{
		if(t[0]==t[2])
			return 1;
		if(t[1]==t[0] || t[1]==t[2] && t[0]!=t[1])
			return 2;
		if(t[0]*t[0]+t[1]*t[1]==t[2]*t[2])
			return 3;
		return 4;
	}
	public triangle x2()
	{
		triangle res=new triangle(t[0]*2,t[1]*2,t[2]*2);
		return res;
	}
	public boolean equals(triangle A)
	{
		if(this==A)
			return true;
		return (t[0]==A.t[0] && t[1]==A.t[1] && t[2]==A.t[2]);
	}
	public String toString()
	{
		return "(a,b,c)="+Arrays.toString(t);
	}
}
public class lab5_trgl {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		triangle[] A=new triangle[3];
		A[0]=new triangle(3,4,5);
		A[1]=new triangle(3,3,4);
		A[2]=new triangle(4,12,9);
		
		for(int i=0;i<3;i++)
			System.out.println(A[i].toString()+" "+A[i].type());
		triangle[] B=new triangle[3];
		for(int i=0;i<3;i++)
			B[i]=A[i].x2();
		for(int i=0;i<2;i++)
			for(int j=i+1;j<3;j++)
				if(A[i].equals(A[j]))
					System.out.println("A["+i+"] � A["+j+"] �����.");
		triangle max=A[0];
		triangle min=A[0];
		for(int i=1;i<3;i++)
		{
			if(A[i].square()>max.square())
				max=A[i];
			if(A[i].square()<min.square())
				min=A[i];
		}
		System.out.println("���������� ������� "+min.square()+" �:"+min.toString());
		System.out.println("���������� ������� "+max.square()+" �:"+max.toString());
		Arrays.sort(A,new Pcmp());
	
		for(int i=0;i<3;i++)
			System.out.println("�������� �����: "+A[i].P()+" "+A[i].toString());
	}

}
