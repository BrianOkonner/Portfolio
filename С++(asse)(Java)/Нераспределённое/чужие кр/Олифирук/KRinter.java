/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package krinter;
import java.util.*;
/**
 *
 * @author Maxim
 */
class wrongkoordcub extends Exception{}

class Comparer_perimetr implements  Comparator <Geometric>
{
    @Override
    public int compare(Geometric o1,Geometric o2)
    {
        if(o1.perimetrosn()==o2.perimetrosn())
            return 0;
        else
            if(o1.perimetrosn()>o2.perimetrosn())
                return 1;
        else
                return -1;
    }
}

interface Geometric
{
    abstract public double perimetrosn();
    abstract public String centr();
}

class Paral implements Geometric
{
    private int x1;
    private int y1;
    private int z1;
    private int x2;
    private int y2;
    private int z2;
    
    Paral(int x1,int y1,int z1,int x2,int y2,int z2)  
    {
       
        this.x1=x1;
        this.y1=y1;
        this.z1=z1;
        this.x2=x2;
        this.y2=y2;
        this.z2=z2;
    }
    
    public int getx1()
    {
        return this.x1;
    }
    
    public int gety1()
    {
        return this.y1;
    }
    
    public int getz1()
    {
        return this.z1;
    }
    
     public int getx2()
    {
        return this.x2;
    }
    
    public int gety2()
    {
        return this.y2;
    }
    
    public int getz2()
    {
        return this.z2;
    }
    
     public double perimetrosn()
     {
         return (2*(this.x2-this.x1)+2*(this.y2-this.y1));
     }
    
     public String centr()
     {
         return " xc1= "+(this.x1+this.x2)/2+" yc1= "+(this.y1+this.y2)/2+" zc1= "+(this.z1+this.z2)/2;
     }
 
    
    public String toString()
    {
        return "Paral: x1 = "+x1+" y1= " +y1+" z1= "+z1+" x2= "+x2+" y2= "+y2+" z2= "+z2;
    }
}

class Cub implements Geometric
{
    private int x1;
    private int y1;
    private int z1;
    private int x2;
    private int y2;
    private int z2;
    
    Cub(int x1,int y1,int z1,int x2,int y2,int z2) throws wrongkoordcub
    {
         if(((x2-x1)!=(y2-y1))&&((z2-z1)!=(y2-y1)))
          throw new wrongkoordcub(); 
        this.x1=x1;
        this.y1=y1;
        this.z1=z1;
        this.x2=x2;
        this.y2=y2;
        this.z2=z2;
    }
    
    public int getx1()
    {
        return this.x1;
    }
    
    public int gety1()
    {
        return this.y1;
    }
    
    public int getz1()
    {
        return this.z1;
    }
    
     public int getx2()
    {
        return this.x2;
    }
    
    public int gety2()
    {
        return this.y2;
    }
    
    public int getz2()
    {
        return this.z2;
    }
    
     public double perimetrosn()
     {
         return 4*(this.x2-this.x1);
     }
    
     public String centr()
     {
         return " xc1= "+(this.x1+this.x2)/2+" yc1= "+(this.y1+this.y2)/2+" zc1= "+(this.z1+this.z2)/2;
     }
 
    
    public String toString()
    {
        return "Cub: x1 = "+x1+" y1= " +y1+" z1= "+z1+" x2= "+x2+" y2= "+y2+" z2= "+z2;
    }
}

public class KRinter {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        try
     {
       Paral p1=new Paral(1,1,1,2,4,2);
       System.out.println(p1);
       System.out.println(p1.perimetrosn());
       
       Cub c1=new Cub(1,1,1,2,2,3);
       System.out.println(c1);
       System.out.println(c1.perimetrosn());
       
       Geometric F1[]=new Geometric[2];
        F1[0]=p1;
        F1[1]=c1;
        
        System.out.println("\nSort Array 1:");
        Arrays.sort(F1,new Comparer_perimetr());
        System.out.println(Arrays.toString(F1));
    }
        catch(wrongkoordcub e)
        {
            System.out.println("this is not cub");
        }
    }
    
}
