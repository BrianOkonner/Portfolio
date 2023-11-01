
package кр.pkg2;

import java.io.FileInputStream; 
import java.io.FileNotFoundException; 
import java.io.PrintStream; 
import java.math.BigDecimal; 
import java.math.RoundingMode; 
import java.text.DecimalFormat; 
import java.util.Arrays; 
import java.util.Scanner;
import java.util.Comparator;
class WrongDobavlenie extends Exception{};
class FirstSravn implements Comparator<QueueOnMassive>
{
    
    @Override
    
    public int compare(QueueOnMassive A,QueueOnMassive B)
    {
        if(A.GetFirst()==B.GetFirst())
            return 0;
        if(A.GetFirst()>B.GetFirst())
            return -1;
        return 1;
    }
    
    
}
abstract class QueueOnMassive
{
    protected int[] mas;
    protected int colvo;
    public abstract boolean IsFull();
     public abstract boolean IsEmpty();
      public abstract int GetFirst();
       public abstract void DobavlenieVKonec(int k) throws WrongDobavlenie;
      public abstract String toString();
      
       
      
       QueueOnMassive(int Razmer)
       {
           this.mas=new int[Razmer];
           this.colvo=0;
       }
}
class CircleQueue extends QueueOnMassive
{
    CircleQueue(int Razmer)
    {
        super(Razmer);
    }
    @Override
    public boolean IsEmpty()
    {
        return this.colvo==0;
    }
    public boolean IsFull()
    {
        return this.colvo==this.mas.length;
    }
    @Override
    public int GetFirst()
    {
       
            return mas[0];
        
    }
    @Override
    public void DobavlenieVKonec(int k)throws WrongDobavlenie
    {
        if (IsFull()==false){
           this.mas[this.colvo]=k;
           this.colvo++;
        }
        else
             throw new WrongDobavlenie();
        
    } 
    public  String toString()
    {
        return "Вся очередь: "+Arrays.toString(mas)+"Первый элемент: "+GetFirst()+" ";
    }

}
class DualQueue extends QueueOnMassive
{
    DualQueue(int Razmer)
    {
        super(Razmer);
    }
    public boolean IsEmpty()
    {
        return this.colvo==0;
    }
    public boolean IsFull()
    {
        return this.colvo==this.mas.length;
    }
    public int GetFirst()
    {
        
            return mas[0];
        
         
    }
    @Override
    public void DobavlenieVKonec(int k)throws WrongDobavlenie
    {
        if (IsFull()==false){
           this.mas[this.colvo]=k;
           this.colvo++;
        }
        else
             throw new WrongDobavlenie();    
    }
    public void DobavlenieVNachalo(int k)throws WrongDobavlenie
    {
        if(IsFull()==false){
            if(IsEmpty()==true)
            {
                this.mas[0]=k;
                this.colvo++;
            }
            else{
        for(int i=this.colvo-1;i>=0;i--)
        {
           this.mas[i+1]=this.mas[i];
        }
        this.mas[0]=k;
        this.colvo++;}
        }
        else
            throw new WrongDobavlenie();
    }
     public void UdalenieVKonce()
     {
         mas[colvo-1]=0;
         colvo--;
     }
      public  String toString()
    {
        return "Вся очередь: "+Arrays.toString(mas)+"Первый элемент: "+GetFirst()+" ";
    }
}
public class КР2 {

 
    public static void main(String[] args)throws WrongDobavlenie {
        
       try{
           QueueOnMassive[] QUEUE={new DualQueue(5),new DualQueue(7),new CircleQueue(10),new CircleQueue(8)};
           for(int i=0;i<QUEUE[0].mas.length;i++)
           {
               QUEUE[0].DobavlenieVKonec(2);
           }
           for(int i=0;i<QUEUE[2].mas.length-1;i++)
           {
               QUEUE[2].DobavlenieVKonec(3);
           }
 for(int i=0;i<QUEUE[1].mas.length-1;i++)
           {
               QUEUE[1].DobavlenieVKonec(7);
           }
  for(int i=0;i<QUEUE[3].mas.length-1;i++)
           {
               QUEUE[3].DobavlenieVKonec(6);
           }
  QUEUE[3].DobavlenieVKonec(188);
         System.out.println(QUEUE[0]+"\n"+QUEUE[1]+"\n"+QUEUE[2]+"\n"+QUEUE[3]);
         Arrays.sort(QUEUE,new FirstSravn());
         System.out.println("Сортировка: \n");
         for(int i=0;i<QUEUE.length;i++)
             System.out.println(QUEUE[i]);
      DualQueue A=new DualQueue(8);
      CircleQueue B=new CircleQueue(7);


      System.out.println(A);
      System.out.println("Добавили в начало 6, в конец 2, в начало 9");
      A.DobavlenieVNachalo(6);
      A.DobavlenieVKonec(2);
      A.DobavlenieVNachalo(9);
     
       System.out.println(A);
       System.out.println("Проверки: "+A.IsEmpty()+" "+A.IsFull());
       }
        catch(WrongDobavlenie e)
                {
                System.out.println("Ошибка дополнения!");
                }
       
    }
    
}
