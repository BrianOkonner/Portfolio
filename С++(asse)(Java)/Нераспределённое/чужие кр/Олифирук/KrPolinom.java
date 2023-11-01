/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package krpolinom;
import java.util.Scanner;
import java.util.*;
import java.io.*;
import java.util.Arrays;
/**
 *
 * @author Maxim
 */
abstract class polinom
{
    public int step;
    public int maskoeff[];
}

class CPolinom extends polinom
{
    public CPolinom(int step)
    {
        this.step=step;
        this.maskoeff=new int[step];
        for(int i=0;i<step;i++)
        {
            int a1=(int)(Math.random()*10);
            maskoeff[i]=a1;
        }
    }

    public void Sloj(CPolinom A,CPolinom B)
    {
        for(int i=0;i<step;i++)
        {
            this.maskoeff[i]=A.maskoeff[i]+B.maskoeff[i];
        }
    }
    
    public void Vuchit(CPolinom A,CPolinom B)
    {
        for(int i=0;i<step;i++)
        {
            this.maskoeff[i]=A.maskoeff[i]-B.maskoeff[i];
        }
    }
    
    public void Delenie(CPolinom A,int vel)
    {
        for(int i=0;i<step;i++)
        {
            this.maskoeff[i]=A.maskoeff[i]/vel;
        }
    }
    
    public void Znach(CPolinom A,int znach)
    {
        int sum=0;
        for(int i=step-1;i>=0;i--)
        {
            sum=sum+maskoeff[i]*(int)Math.pow(znach, i);
        }
    }
    
    public String toString()
    {
        String Str="";
         for(int i=0;i<step;i++)
        {
            Str=Str+maskoeff[i]+" ";
        }
        return "step= "+this.step+" "+Str;
    }
}

class BPolinom extends polinom
{
    public BPolinom(int step)
    {
        this.step=step;
        this.maskoeff=new int[step];
        for(int i=0;i<step;i++)
        {
            int a1=(int)(Math.random()*2);
            maskoeff[i]=a1;
        }
    }

    public void Sloj(BPolinom A,BPolinom B)
    {
        for(int i=0;i<step;i++)
        {
            if(A.maskoeff[i]==0 &&B.maskoeff[i]==0 )
            {
                this.maskoeff[i]=0;
            }
            else
            {
                this.maskoeff[i]=1;
            }
        }
    }
    
    public void Umnoj(BPolinom A,BPolinom B)
    {
        for(int i=0;i<step;i++)
        {
            if(A.maskoeff[i]==1 &&B.maskoeff[i]==1 )
            {
                this.maskoeff[i]=1;
            }
            else
            {
                this.maskoeff[i]=0;
            }
        }
    }
    
  
    
    public void Znach(BPolinom A,int znach)
    {
        int sum=0;
        for(int i=step-1;i>=0;i--)
        {
            sum=sum+maskoeff[i]*(int)Math.pow(znach, i);
        }
    }
    
    public String toString()
    {
        String Str="";
         for(int i=0;i<step;i++)
        {
            Str=Str+maskoeff[i]+" ";
        }
        return "step= "+this.step+" "+Str;
    }
}


public class KrPolinom 
{

    public static void main(String[] args) 
    {
       System.out.println("Первый полином");
       CPolinom c1=new CPolinom(3);
       System.out.println(c1);
       
       System.out.println("Второй полином");
       CPolinom c2=new CPolinom(3);
       System.out.println(c2);
        
       CPolinom c3=new CPolinom(3);
       System.out.println("Сумма");
       c3.Sloj(c1,c2);
       System.out.println(c3);
       
       c3.Vuchit(c1,c2);
       System.out.println("Разность");
       System.out.println(c3);
      
       System.out.println("Первый бул полином");
       BPolinom b1=new BPolinom(3);
       System.out.println(b1);
       
        System.out.println("Второй бул полином");
       BPolinom b2=new BPolinom(3);
       System.out.println(b2);
       
         System.out.println("Сумма");
       BPolinom b3=new BPolinom(3);
       b3.Sloj(b1,b2);
       System.out.println(b3);
       
        System.out.println("Произведение");
       b3.Umnoj(b1,b2);
       System.out.println(b3);
    }
    
}
