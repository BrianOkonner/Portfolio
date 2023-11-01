/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package krflowers;
import java.util.*;
import java.util.Scanner;
import java.io.*;
import java.util.Arrays;
/**
 *
 * @author Maxim
 */
class CompareComp implements Comparator<Prodanny_flowers>
{
@Override
public int compare(Prodanny_flowers A,Prodanny_flowers B)
{
return A. getName_of_composition().compareTo(B.getName_of_composition());
}
}
enum flowers
{
    rosa,
    gerbera,
    lilia;
}
class wrongkol extends Exception{}
class wrongcost extends Exception{}

class Prodanny_flowers
{
    protected final int id;
    private final flowers flow;
    private final String Name_of_composition;
    private final int kol;
    private final double cost;
    private static int count=0;
   
    
    Prodanny_flowers(flowers flow , String Name_of_composition , int kol, double cost)
     throws  wrongkol,wrongcost
    {
      if(kol< 0 )
          throw new wrongkol(); 
       if(cost< 0 )
          throw new wrongcost(); 
      count++;
      
      this.id=count;
      this.flow=flow;
      this.Name_of_composition= Name_of_composition;
      this.kol=kol;
      this.cost=cost;
      
    }
    
       public int getid()
      {
         return this.id;
      }
       
       public String toString()
       {
        return " Id= "+this.id+" Flow: "+this.flow+" Name_of_composition: "+this.Name_of_composition+" kol: "+this.kol+" cost: "+this.cost+"\n";
       }
       
       public flowers getflow()
       {
         return this.flow;
       }
       
       public String getName_of_composition()
       {
        return this.Name_of_composition;
       }
       
       public int getkol()
       {
         return this.kol;
       }
       
        public  double Getcost()
       {
         return this.cost;
       }    
}

class Oranjaray
{ 
    private Prodanny_flowers[]Fl;
   // private String name;
    //private String adress;
    public Oranjaray( Prodanny_flowers[]Fl)
    {
       this.Fl=new Prodanny_flowers[Fl.length];
       System.arraycopy(Fl,0,this.Fl,0,Fl.length);
    }
    
    @Override
    public String toString()
    {
        return Arrays.toString(this.Fl);
    }
    
    
    
    public String GetKol(double num1)
    {
        StringBuffer sb=new StringBuffer();
        for( Prodanny_flowers a:this.Fl)
            if(a.getkol()>num1)
               sb.append(a);
        return sb.toString();
    }
    
   /*  public String GetSum()
    {
        StringBuffer sb=new StringBuffer();
        for( Prodanny_flowers a:this.Fl)
            if(a.getkol()>num1)
               sb.append(a);
        return sb.toString();
    }*/
    
    

}

public class KrFlowers {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException,wrongkol,wrongcost
    {
        FileInputStream ifr=new FileInputStream("input.txt");
        Scanner sr=new Scanner(ifr);
        PrintStream pw=new PrintStream("output.txt");
        Prodanny_flowers [] prod=new Prodanny_flowers[5];

        int i=0;
        while(sr.hasNext())
        {
            String str=sr.nextLine();
            String[]a=str.split(" ");
            flowers flow=flowers.valueOf(a[0]);
            String Name_of_composition=a[1];
            int kol=Integer.parseInt(a[2]);
            double cost=Double.parseDouble(a[3]);
            prod[i++]=new Prodanny_flowers(flow ,Name_of_composition ,kol,cost);
         
        }
        
         
        Arrays.sort(prod,new CompareComp());
        
        Oranjaray g=new Oranjaray(prod);
        
        System.out.println("\n1-Все композиции");
        pw.println("\n1-Все композиции");
        System.out.println(g);
        pw.println(g);
        
        System.out.println("\n2-Все композиции c количеством больше 22");
        pw.println("\n2-Все композиции c количеством больше 22");
        System.out.println(g. GetKol(22));
        pw.println(g. GetKol(22));
        
        System.out.println("\n3-Сортировка по названиям");
        pw.println("\n3-Сортировка по названиям");
        Arrays.sort(prod,new CompareComp());
        System.out.println(g);
   
        
        
    }
    
}
