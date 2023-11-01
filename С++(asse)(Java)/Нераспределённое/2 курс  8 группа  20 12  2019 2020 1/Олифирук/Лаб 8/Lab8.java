/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab8;
import java.util.*;
/**
 *Пересечение фигур
 * @author Maxim
 */
interface Location
{
    abstract public int location(Object o);
}

class Circle implements Location
{
    private int x;
    private int y;
    private double radius;
    
    Circle(int x,int y,double radius)
    {
        this.x=x;
        this.y=y;
        this.radius=radius;
    }
    
    public int getX()
    {
        return this.x;
    }
    
    public int getY()
    {
        return this.y;
    }
    
    public double getR()
    {
        return this.radius;
    }
    
    public double perimetr()
    {
        return 2*3.14*radius;
    }
    
    public double square()
    {
        return 3.14*radius*radius;
    }
    
    public int location(Object o)
    {
        if(!(o instanceof Circle))
            return 0;
        Circle t=(Circle)o;
        double rast=Math.sqrt((this.x-t.getX())*(this.x-t.getX())+(this.y-t.getY())*(this.y-t.getY()));
        if(rast>this.radius+t.getR())
            return 1;
        if(rast==this.radius+t.getR())
            return 2;
        return 3;
    }
    
    public String toString()
    {
        return "circle: x = "+x+" y= " +y+" r= "+radius;
    }
}

class Rectangle implements Location
{
    private int x1,y1;
    private int x2,y2;
    Rectangle(int x1,int y1,int x2,int y2)
    {
        this.x1=x1;
        this.y1=y1;
        this.x2=x2;
        this.y2=y2;
    }
    
    public double perimetr()
    {
        return (double)(2*((x2-x1)*(y2-y1)));
    }
    
    public double square()
    {
        return (double) ((x2-x1)*(y2-y1));
    }
    
    public int getX1()
    {
        return this.x1;
    }
    
    public int getY1()
    {
        return this.y1;
    }
        
    public int getX2()
    {
        return this.x2;
    }
            
    public int getY2()
    {
        return this.y2;
    }
    
    public int location(Object o)
    {
        
        Rectangle t=(Rectangle)o;
        int dx1=this.x1-((t.x2-t.x1)/2);
        int dx2=this.x2+((t.x2-t.x1)/2);
        int dy1=this.y1-((t.y2-t.y1)/2);
        int dy2=this.y2+((t.y2-t.y1)/2);
        
        int cx=(t.x1+t.x2)/2;
        int cy=(t.y1+t.y2)/2;
        
        if((cx>dx1)&&(cx<dx2)&&(cy>dy1)&&(cy<dy2))
        {
         return 3;
        }
           
        if(((cx==dx1)&&(cy>=dy1)&&(cy<=dy2))||((cx==dx2)&&(cy>=dy1)&&(cy<=dy2))||((cy==dy1)&&(cx>=dx1)&&(cx<=dx2))||((cy==dy2)&&(cx>=dx1)&&(cx<=dx2)))
        {
              return 2;
        }
        return 1;
    }
    
    public String toString()
    {
        return "rectangle: x1= "+x1+" y1= "+y1+" x2= "+x2+" y2= "+y2;
    }
}

public class Lab8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Circle c1=new Circle(3,2,3);
        System.out.println(c1);
        Rectangle r1=new Rectangle(1,1,4,3);
        System.out.println(r1);
        Circle c2=new Circle(7,2,2);
        System.out.println(c2);
        Rectangle r2=new Rectangle(3,3,5,6);
        System.out.println(r2);
        System.out.println(c1.location(c2));
        System.out.println(r1.location(r2));
    }
    
}
