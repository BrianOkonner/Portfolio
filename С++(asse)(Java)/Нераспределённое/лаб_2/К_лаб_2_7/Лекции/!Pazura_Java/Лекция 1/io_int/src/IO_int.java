import java.io.*;
import java.util.*;
/*
 * Created on 02.06.2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author -
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class IO_int {
	  static String kb_getstring() throws IOException {
	    String s;
	    BufferedReader in=new BufferedReader(
	    		new InputStreamReader(System.in));
	    s = in.readLine(); //Читаем с клавиатуры строку
	    return s; 
	  }
	  static int a[]= new int[10];
	public static void main(String args[]) 
	throws IOException,Exception  
	{
	System.out.println("Вводите числа через пробел");
	String s=kb_getstring();
	StringTokenizer st = 
		new StringTokenizer(s, " \t\n\r");  
	int i=0;
	Vector v1 = new Vector(),v2 = new Vector(); 
	Integer A;

	while(st.hasMoreTokens()){ 
//	 Получаем слово и что-нибудь делаем с ним, например, 

		a[i]=Integer.parseInt(st.nextToken());
//		a[i]=Integer.valueOf(st.nextToken()).intValue();
    	A=new Integer(a[i++]);
	    v1.add(A);  // Добавляем в конец вектора, 
	    					// предварительно превращаем в об'ект
	}
	DataOutputStream dos = new DataOutputStream ( 
			new FileOutputStream("Ex1.bin"));  

    PrintWriter out1 =
        new PrintWriter(
          new BufferedWriter(
            new FileWriter("Ex1.txt")));

    int sum=0;

	for (int j=0; j<i; j++){
		sum += a[j];
		System.out.print(a[j] + " ");
        out1.print(a[j] + " ");
    	dos.writeInt(a[j]);  
	}
	System.out.println("Sum=" + sum + " ");
	out1.println("Sum=" + sum + " ");
	sum = 0;
	for (int j=0; j<i; j++){
		int x;
		x=((Integer)v1.get(j)).intValue();
		System.out.print( x + " ");
		sum += x;
        out1.print(x + " ");
    	dos.writeInt(x);  
	}
	System.out.println("Sum=" + sum + " ");
	out1.println("Sum=" + sum + " ");
    out1.close();
	dos.close();

	// Проверка файла из байтового потока 
	DataInputStream dis = new DataInputStream ( 
			new FileInputStream("Ex1.bin")) ;  
			while(true)  
			try{ 
			int a = dis.readInt();  
			System.out.print(a + " ");  
			}catch(IOException e){  
			dis.close(); 
			System.out.println("End of file");  
			System.exit (0);  
			}  
	}
}
