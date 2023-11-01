package kr2;

import java.util.Arrays;
import java.util.Comparator;

class wrongEdges extends Exception{}
class zeroException extends Exception{}

class cmp implements Comparator<solid>
{
	@Override
	public int compare(solid f1,solid f2)
	{
		if(f1.S()==f2.S())
			return 0;
		if(f1.S()>f2.S())
			return 1;
		return -1;
	}
}
interface solid{
	public abstract double S();
	public abstract double V();
}

class pyramid implements solid
{
	private double a;
	private double b;
	private double c;
	private double h;
	pyramid(double a1,double b1,double c1, double h1) throws wrongEdges, zeroException
	{
		if(a1+b1<=c1 || b1+c1<=a1 || a1+c1<=b1)
			throw new wrongEdges();
		if(h1==0 || a1==0 || b1==0 || c1==0)
			throw new zeroException();
		a=a1;
		b=b1; 
		c=c1; 
		h=h1;
	}
	public double P()
	{
		return (a+b+c);
	}
	@Override
	public double S()
	{
		return Math.sqrt(this.P()/2*(this.P()/2-a)*(this.P()/2-b)*(this.P()/2-c));
	}
	@Override
	public double V()
	{
		return this.S()*h/3;
	}
	public String toString()
	{
		return "Основание: "+a+" "+b+" "+c+"\n"+"Высота: "+h;
	}
}

class cone implements solid
{
	private double r;
	private double h;
	public cone(double r,double h) throws zeroException
	{
		if(r==0 || h==0)
			throw new zeroException();
		this.r=r;
		this.h=h;
	}
	@Override
	public double S()
	{
		return Math.PI*r*r;
	}
	@Override
	public double V()
	{
		return this.S()*h/3;
	}
	public String toString()
	{
		return "Радиус: "+r+"\n"+"Высота: "+h;
	}
}
public class kr2_2 {

	public static void main(String[] args) throws wrongEdges, zeroException {
		// TODO Auto-generated method stub
		pyramid p1=new pyramid(3,4,5,8);
		pyramid p2=new pyramid(2,2,3,11);
		cone c1=new cone(7,10);
		cone c2=new cone(8,12);
		solid []s=new solid[] {p1,p2,c1,c2};
		System.out.println(p1+"\nПлощадь основания:"+p1.S()+"\nОбъём:"+p1.V()+"\n");
		System.out.println(p2+"\nПлощадь основания:"+p2.S()+"\nОбъём:"+p2.V()+"\n");
		System.out.println(c1+"\nПлощадь основания:"+c1.S()+"\nОбъём:"+c1.V()+"\n");
		System.out.println(c2+"\nПлощадь основания:"+c2.S()+"\nОбъём:"+c2.V()+"\n");
		System.out.println("\n\nВызов через массив:");
		for(solid t:s)
			System.out.println(t+"\nПлощадь основания:"+t.S()+"\nОбъём:"+t.V());
		Arrays.sort(s,new cmp());
		System.out.println("\nОтсортированный массив:");
		for(solid t:s)
			System.out.println(t+"\nПлощадь основания:"+t.S()+"\n");
	}

}
