import java.io.*; 

class IO_str{ 

public static void main(String[] args){  

try{ 

	BufferedReader br = 

	new BufferedReader(new InputStreamReader(System.in, "Cp866"));  

	PrintWriter pw = new PrintWriter( 

		new OutputStreamWriter(System.out, "Cp866"), true);  

	String s = "��� ������ � ������� �������";  

	System.out.println("System.out puts: " + s);  

	pw.println("PrintWriter puts: " + s) ;  

	int c = 0; 

	pw.println("������������ ����:");  

	while((c = br.read()) != -1) 

		pw.println((char)c);  

	pw.println("���������� ����:");  

	do{ 

		s = br.readLine();  
	
		pw.println(s);  

	} while(!s.equals("q"));  

   } catch(Exception e){ 

	System.out.println(e);  

   }  

}  

} 

