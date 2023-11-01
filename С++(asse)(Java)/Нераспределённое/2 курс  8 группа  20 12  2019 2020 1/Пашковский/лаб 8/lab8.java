package ehh;
  
import java.util.Arrays;
import java.util.Comparator;

class cmp implements Comparator<figure>
{
	@Override
	public int compare(figure f1,figure f2)
	{
		if(f1.S()==f2.S())
			return 0;
		if(f1.S()>f2.S())
			return -1;
		return 1;
	}
}

interface location{
	public abstract int poscheck(Object a);
}
interface figure{
    public abstract double P();
    public abstract double S();
}
class circle implements figure,location
{
	private double r;
	private double x;
	private double y;
	public circle(double r,double x,double y){
	this.r=r;
	this.x=x;
	this.y=y;
	}
	@Override 
	public int poscheck(Object a)
	{
		if(a instanceof circle)
			{
				circle c=(circle)a;
				if(Math.sqrt((this.x-c.x)*(this.x-c.x)+(this.y-c.y)*(this.y-c.y))>this.r+c.r)
					return 1;
				if(Math.sqrt((this.x-c.x)*(this.x-c.x)+(this.y-c.y)*(this.y-c.y))==this.r+c.r)
					return 2;
				if(Math.sqrt((this.x-c.x)*(this.x-c.x)+(this.y-c.y)*(this.y-c.y))<this.r+c.r)
					return 3;
			}
		if(a instanceof rect)
			{
				rect rec=(rect)a;
				if((this.x-rec.getx2()-this.r>0)||(this.x+this.r-rec.getx1()<0)||
						(this.y-rec.gety2()-this.r>0)||(this.y-rec.gety1()+this.r<0))
					return 1;
				else {
				//North East South West (Up right down left)
				double distanceNE=Math.sqrt(Math.pow(rec.getx2()-x,2)+Math.pow(rec.gety2()-y,2));
				double distanceNW=Math.sqrt(Math.pow(rec.getx1()-x,2)+Math.pow(rec.gety2()-y,2));
				double distanceSE=Math.sqrt(Math.pow(rec.getx2()-x,2)+Math.pow(rec.gety1()-y,2));
				double distanceSW=Math.sqrt(Math.pow(rec.getx1()-x,2)+Math.pow(rec.gety1()-y,2));
				//������� � �������
				if((distanceNE==this.r && x>=rec.getx2() && y>=rec.gety2())|| 
						(distanceNW==this.r && x<=rec.getx1() && y>=rec.gety2())||
						(distanceSE==this.r && x>=rec.getx2() && y<=rec.gety1())||
						(distanceSW==this.r && x<=rec.getx1() && y<=rec.gety1()))
					return 2;
				else
					if((this.gety()>rec.gety1() && this.gety()<rec.gety2() && (rec.getx2()+this.getr()==this.getx() || rec.getx1()-this.getr()==this.getx()))
						|| (this.getx()>rec.getx1() && this.getx()<rec.getx2() &&(rec.gety1()-this.getr()==this.gety() || rec.gety2()+this.getr()==this.gety())))	
						return 2;
					else
						return 3;
				}
			}
		return 0;
	}
	@Override
	public double P(){
	return 2*r*Math.PI;
	}
	@Override
	public double S(){
	return Math.PI*r*r;
	}
	@Override
	public String toString(){
	    return "\n���� �������: "+r+" � ������� � �����: ("+x+","+y+")";
	}
	public double getr()
    {
    	return r;
    }
	public double getx()
    {
    	return x;
    }
	public double gety()
    {
    	return y;
    }
}
class rect implements figure,location{
    private double x1;
    private double y1;
    private double x2;
    private double y2;
    rect(double x1,double y1,double x2,double y2)
    {
    	if(x1<x2 && y1<y2)
    	{
	    	this.x1=x1;
	    	this.y1=y1;
	    	this.x2=x2;
	    	this.y2=y2;
	    }
    	else
	    	if(x1>x2 && y1>y2)
	    	{
		    	this.x1=x2;
		    	this.y1=y2;
		    	this.x2=x1;
		    	this.y2=y1;
		    }
	    	else 
	    		System.out.println("�������� ��������� ������������!");
    }
    @Override 
    public double P(){
        return 2*(Math.abs(x1-x2)+Math.abs(y1-y2));
    }
    @Override
    public double S(){
        return Math.abs(x1-x2)*Math.abs(y1-y2);
    }
    @Override 
	public int poscheck(Object a)
	{
		if(a instanceof rect)
			{
				rect rec=(rect)a;
				if(rec.x1>x2 || rec.x2<x1 || rec.y1>y2 || rec.y2<y1)
					return 1;
				if((rec.x1==x2 && rec.y1<=y2 && rec.y2>=y1) ||
						(rec.x2==x1 && rec.y1<=y2 && rec.y2>=y1) ||
						(rec.y1==y2 && rec.x1<=x2 && rec.x2>=x1) ||
						(rec.y2==y1 && rec.x1<=x2 && rec.x2>=x1))
					return 2;
				return 3;
			}
		if(a instanceof circle)
			{
				rect rec=(rect)this;
				circle c=(circle)a;
				if((c.getx()-rec.getx2()-c.getr()>0)||(c.getx()+c.getr()-rec.getx1()<0)||
						(c.gety()-rec.gety2()-c.getr()>0)||(c.gety()-rec.gety1()+c.getr()<0))
					return 1;
				else {
				//North East South West (Up right down left)
				double distanceNE=Math.sqrt(Math.pow(rec.getx2()-c.getx(),2)+Math.pow(rec.gety2()-c.gety(),2));
				double distanceNW=Math.sqrt(Math.pow(rec.getx1()-c.getx(),2)+Math.pow(rec.gety2()-c.gety(),2));
				double distanceSE=Math.sqrt(Math.pow(rec.getx2()-c.getx(),2)+Math.pow(rec.gety1()-c.gety(),2));
				double distanceSW=Math.sqrt(Math.pow(rec.getx1()-c.getx(),2)+Math.pow(rec.gety1()-c.gety(),2));
				//������� � �������
				if((distanceNE==c.getr() && c.getx()>=rec.getx2() && c.getr()>=rec.gety2())|| 
					(distanceNW==c.getr() && c.getx()<=rec.getx1() && c.getr()>=rec.gety2())||
					(distanceSE==c.getr() && c.getx()>=rec.getx2() && c.getr()<=rec.gety1())||
					(distanceSW==c.getr() && c.getx()<=rec.getx1() && c.getr()<=rec.gety1()))
					return 2;
				else
					if((c.gety()>rec.gety1() && c.gety()<rec.gety2() && (rec.getx2()+c.getr()==c.getx() || rec.getx1()-c.getr()==c.getx()))
							|| (c.getx()>rec.getx1() && c.getx()<rec.getx2() &&(rec.gety1()-c.getr()==c.gety() || rec.gety2()+c.getr()==c.gety())))
						return 2;
					else
						return 3;
				}
			}
		return 0;
	}
    public String toString(){
        return "\n�������������: ("+x1+","+y1+"),("+x2+","+y2+")";
    }
    public double getx1()
    {
    	return x1;
    }
    public double gety1()
    {
    	return y1;
    }
    public double getx2()
    {
    	return x2;
    }
    public double gety2()
    {
    	return y2;
    }
    
}


public class lab8 {

	public static void main(String[] args) {
		location[] mas=new location[]{
				new circle(5,10,7),
				new circle(1.35,1,4),
				new circle(5,4,-4),
			    new rect(2,1,6,4),
			    new rect(-4,-4,-1,-1)};
		figure[] fig=new figure[]{
				new circle(5,10,7),
				new circle(1.35,1,4),
				new circle(5,4,-4),
			    new rect(2,1,6,4),
			    new rect(-4,-4,-1,-1)};
		for(location i:mas) {
			for(location t:mas)
				if(t!=i)
					{
						System.out.println("������ "+i+" ����������� ������������ ������\n"+t+" :");
						System.out.println(i.poscheck(t)+"\n");
					}
		}
		Arrays.sort(fig,new cmp());
		for(figure f:fig)
		{
			System.out.println(f);
		}
}
}
