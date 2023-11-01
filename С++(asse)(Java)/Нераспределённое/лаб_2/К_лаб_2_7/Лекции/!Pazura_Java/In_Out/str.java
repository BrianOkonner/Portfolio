import java.io.*;

/*
 * Created on 20.04.2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author User1
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class str {

	  public static void main(String[] args) 
	  throws IOException {
	    // 1. Чтение ввода по строкам:Bruce Eckel
	  	BufferedReader in =
	      new BufferedReader(
	        new FileReader("in.txt"));
	    String s;
	    int n=0;
	    s=in.readLine();
	    n = Integer.parseInt(s); // преобразование в целое
	  	String []m1=new String[n];
	    for (int i=0;i<n;i++)
	    	m1[i]=in.readLine();
	    
	    in.close();

	    // 4. Вывод в файл


	      PrintWriter out1 =
	        new PrintWriter(
	          new BufferedWriter(
	            new FileWriter("IODemo.txt")));
	      
	      out1.println(String.valueOf(n)); //преобразование в строку
	      for (int i=0;i<n;i++){
	      	out1.println(m1[i]);
	      }
	      out1.close();
	    }
}
