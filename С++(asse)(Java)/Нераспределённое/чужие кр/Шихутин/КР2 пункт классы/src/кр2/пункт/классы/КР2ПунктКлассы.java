/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package кр2.пункт.классы;

import java.io.FileInputStream; 
import java.io.FileNotFoundException; 
import java.io.PrintStream; 
import java.math.BigDecimal; 
import java.math.RoundingMode; 
import java.text.DecimalFormat; 
import java.util.Arrays; 
import java.util.Scanner;
import java.util.Comparator;
import java.io.*;
class ComparePer implements Comparator<Pause>
{
@Override
public int compare(Pause A,Pause B){

return A.NameOfProgramm.compareTo(B.NameOfProgramm);
}
}
class CompareTIme implements Comparator<Pause>
{
@Override
public int compare(Pause A,Pause B){
    if (A.Time==B.Time)
        return 0;
    if(A.Time>B.Time)
        return -1;
    return 1;
}
}
enum TypeOfProduct
{
    toys,drinks,hotels,electronics;
}
class WrongTime extends Exception{};
class Pause{
 protected   int id;
    protected  String  Product;
     protected   TypeOfProduct Type;
      protected String NameOfCompany;
 protected String NameOfProgramm;
 protected static int Count=0;
 protected double Time;
 public Pause(String  Product,TypeOfProduct Type,String NameOfCompany,String NameOfProgramm,double Time)throws WrongTime 
      
 {
    
      if(Time<0 || Time>20)
          throw new WrongTime();
      Count++;
     this.id=Count;
      this.Product=Product;
      this.NameOfProgramm=NameOfProgramm;
      this.NameOfCompany=NameOfCompany;
      this.Type=Type;
      this.Time=Time;
}
  public int getid()
  {
      return this.id;
  }
  public String toString()
  {
      return "Id= "+this.id+" Товар:"+this.Product+" Вид товара:"+this.Type+" Название фирмы: "+this.NameOfCompany+" Название передачи:"+this.NameOfProgramm+" Время передачи:"+this.Time;

  }
    public String getNameOfProgramm(){
      return this.NameOfProgramm;
    }
     public String getNameOfCompany()
  {
      return this.NameOfCompany;
  }
     public double getTime()
     {
         return this.Time;
     }
     public String getProduct()
     {
         return this.Product;
     }
  
     public void setTime(double Time)
     {
        this.Time=Time;
     }
    
}

class AdsWork 
{
    protected String Name;
    protected String Adress;
    protected Pause[] A;
    public AdsWork(String Name,String Adress,Pause[] A)
    {
        this.Name=Name;
        this.Adress=Adress;
        this.A=A;
    }
    public String getName()
    {
        return this.Name;
    }
    public String getAdress()
    {
        return this.Adress;
    }
    public String toString()
    {
        StringBuffer str=new StringBuffer();
        for(int i=0;i<A.length;i++)
            str.append(A[i].toString()+"\n");
       
        return "AdsWork: "+this.Name+" || Street: "+this.Adress+"\n"+str.toString();
    
    }
    public String Dlitelb(double S)
    {
       
        StringBuffer str=new StringBuffer();
        for(int i=0;i<A.length;i++)
            if(A[i].Time>S)
            {
               str.append(A[i].toString()+"\n");
            }
        return str.toString();
    }
//    public String SumPerTime()
//    {
//        String[] A=new String[this.A.length];
//        for(int i=0;i<A.length;i++)
//        {
//            
//        }
//    }
}
public class КР2ПунктКлассы {

    
    public static void main(String[] args) {
      try{
           FileInputStream pv=new FileInputStream("input.txt");
           Scanner sc=new Scanner(pv);
           PrintStream pv1=new PrintStream("output.txt");
      Pause[] ultra=new Pause[sc.nextInt()];
      sc.nextLine();
      int k=0;
      while(sc.hasNext())
      {
          String str=sc.nextLine();
          String[] arr=str.split(" ");

          ultra[k++]=new Pause(arr[0],TypeOfProduct.valueOf(arr[1]),arr[2],arr[3],Double.parseDouble(arr[4]));}
    AdsWork MIR=new AdsWork("REKLAM","Nezalezhnaya",ultra);
    System.out.println(MIR);
    Scanner sc1=new Scanner(System.in);
    System.out.println("Введите желаемую гранчную величину времени: ");
    double s;
    s=sc1.nextDouble();
    System.out.println(MIR.Dlitelb(s));
    Arrays.sort(MIR.A,new ComparePer());
    System.out.println("Отсортированный по именам: ");
        System.out.println(MIR);
           Arrays.sort(MIR.A,new CompareTIme());
    System.out.println("Отсортированный по времени: ");
        System.out.println(MIR);
      }
     catch(IOException e)
       {
           System.out.println("Ошибка");
       }
        catch(WrongTime e)
                {
                System.out.println("Error Money");
                }
      }
}
