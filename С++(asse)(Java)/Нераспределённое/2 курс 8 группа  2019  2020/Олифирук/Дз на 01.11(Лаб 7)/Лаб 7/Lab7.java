/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab7;
import java.util.*;
import java.io.*;
import java.util.Arrays;
/**
 *
 * @author Maxim
 */

enum MusicG
{
    song,
    opera,
    simphonia,
    another;
}

class Musiclong implements Comparator<MusicComposition>
{
@Override
public int compare(MusicComposition A,MusicComposition B){
if(A.Getlongsin()==B.Getlongsin())
    return 0;
if(A.Getlongsin()>B.Getlongsin())
        return -1;
return 1;}
}

class CompareComp implements Comparator<MusicComposition>
{
@Override
public int compare(MusicComposition A,MusicComposition B)
{
return A.getNameOfComposition().compareTo(B.getNameOfComposition());
}
}

class wronglongsing extends Exception{}
class wrongrate extends Exception{}

class MusicComposition
{
    protected final int id;
    private final String NameOfComposition;
    private final MusicG ganre;
    final String Author;
    private final String Firstname;
    private final double longsing;
    private final double rate;
    private static int count=0;
    
    MusicComposition(String NameOfComposition , String Author , String Firstname,MusicG ganre, double longsing  ,double rate)
     throws wronglongsing
    {
      if(longsing < 0 )
          throw new wronglongsing(); 
      count++;
      
      this.id=count;
      this.ganre=ganre;
      this.NameOfComposition= NameOfComposition;
      this.Author=Author;
      this.Firstname=Firstname;
      this.longsing=longsing;
      this.rate=rate;
      
    }
    
       public int getid()
      {
         return this.id;
      }
       
       public String toString()
       {
        return " Id= "+this.id+" NameOfComposition: "+this.NameOfComposition+" Author: "+this.Author+" Firstname: "+this.Firstname+" Ganre: "+this.ganre+" longsing: "+this.longsing+" rate: "+this.rate+"\r\n";
       }
       
       public String getNameOfComposition()
       {
         return this.NameOfComposition;
       }
       
       public String getAuthor()
       {
        return this.Author;
       }
       
       public String getFirstname()
       {
         return this.Firstname;
       }
  
       public MusicG Getganre()
       {
         return this.ganre;
       }
       
        public  double Getrate()
       {
         return this.rate;
       }
        
         public  double Getlongsin()
       {
         return this.longsing;
       }
    
}

class Remake extends MusicComposition
{
    private final String reshiser;
    private final int year_of_remake;
    
    public Remake(String NameOfComposition , String Author , String Firstname, MusicG ganre, double longsing  ,double rate, String reshiser,int year_of_remake) throws wronglongsing
    {
        super(NameOfComposition ,Author,Firstname,ganre,longsing,rate);
        this.reshiser=reshiser;
        this.year_of_remake=year_of_remake;
    }
    
    
    public String getNameOfReshiser()
    {
         return this.reshiser;
    } 
    
    public int getYearOfRemake()
    {
         return this.year_of_remake;
    } 
    
    @Override
    public String toString()
    {
        return super.toString()+" reshiser: "+this.reshiser+" year of remake: "+this.year_of_remake+"\r\n";
    }
    
}

class Cd
{
    private MusicComposition[]Music;
    
    public Cd(MusicComposition[]Music)throws wronglongsing
    {
       this.Music=new MusicComposition[Music.length];
       System.arraycopy(Music,0,this.Music,0,Music.length);
    }
    
    @Override
    public String toString()
    {
        return Arrays.toString(this.Music);
    }
    
    public String getAuthor(String name)
    {
        StringBuffer sb=new StringBuffer();
        for(MusicComposition a:this.Music)
        {
            if(a.getAuthor().equalsIgnoreCase(name))
            {
                sb.append(a);
            }
        }
        return sb.toString();
    }
    
    
    public String getGenge(MusicG ganre)
    {
        StringBuffer sb=new StringBuffer();
        for(MusicComposition a:this.Music)
           if(a.Getganre()==ganre)
               sb.append(a);
        return sb.toString();
    }
    
    public String GetRate(double num1,double num2)
    {
        StringBuffer sb=new StringBuffer();
        for(MusicComposition a:this.Music)
            if((a.Getrate()>num1)&&(a.Getrate()<num2))
               sb.append(a);
        return sb.toString();
    }
    
    public void sortbylong()
    {
        Arrays.sort(this.Music,new Musiclong());
    }
    
    public void sortbyNameOfComposition()
    {
        Arrays.sort(this.Music,new CompareComp());
    }
    
    
    
    
    
}

public class Lab7
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException,wronglongsing
    {
        FileInputStream ifr=new FileInputStream("input.txt");
        Scanner sr=new Scanner(ifr);
        PrintStream pw=new PrintStream("output.txt");
        MusicComposition [] mus=new MusicComposition[7];
        
        int i=0;
        while(sr.hasNext())
        {
            String str=sr.nextLine();
            String[]a=str.split(" ");
            String NameOfComposition=a[0];
            String Author=a[1];
            String Firstname=a[2];
            MusicG ganre=MusicG.valueOf(a[3]);
            double longsing=Double.parseDouble(a[4]);
            double rate=Integer.parseInt(a[5]);
           
            
            if(a.length<=6)
            {
                mus[i++]=new MusicComposition(NameOfComposition, Author, Firstname,ganre,longsing,rate);
            }
            else
            {
                String reshiser=a[6];
                int year_of_remake=Integer.parseInt(a[7]);
                mus[i++]=new Remake(NameOfComposition, Author, Firstname,ganre,longsing,rate,reshiser,year_of_remake);
            }
            
           
          
        }
         Cd g=new Cd(mus);
            
           System.out.println("\n1-Все композиции");
           pw.println("\n1-Все композиции");
           System.out.println(g);
           pw.println(g);
           
            System.out.println("\n2-Композиции Бетховена");
            pw.println("\n2-Композиции Бетховена");
            String name="Bethoven";
            System.out.println(g.getAuthor(name));
            pw.println(g.getAuthor(name));
            
            System.out.println("\n3-Песни");
            pw.println("\n3-Песни");
            System.out.println(g.getGenge(MusicG.song));
            pw.println(g.getGenge(MusicG.song));
            
             System.out.println("\n4-Композиции с рейтингом от 88 до 95");
               pw.println("\n4-Композиции с рейтингом от 88 до 95");
            System.out.println(g.GetRate(88,95));
            pw.println(g.GetRate(88,95));

        System.out.println("\n5-упорядочение по убыванию длительности звучания");
        pw.println("\n5-упорядочение по убыванию длительности звучания");
        g.sortbylong();
        System.out.println(g);
        pw.println(g);
        
        System.out.println("\n6-упорядочение в алфавитном порядке");
          pw.println("\n6-упорядочение в алфавитном порядке");
        g.sortbyNameOfComposition();
        System.out.println(g);
        pw.println(g);
    } 
}
