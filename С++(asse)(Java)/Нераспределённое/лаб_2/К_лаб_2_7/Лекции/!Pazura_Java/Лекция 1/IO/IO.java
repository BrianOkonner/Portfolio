//: c11:IOStreamDemo.java
// �������� ������������ ������� �����/������.
import java.io.*;

public class IO {
  // ������������ ���������� �� �������:
  public static void main(String[] args) 
  throws IOException {
    // 1. ������ ����� �� �������:
    BufferedReader in =
      new BufferedReader(
        new FileReader("IO.java"));
    String s, s2 = new String();
    while((s = in.readLine())!= null)
      s2 += s + "\n";
    in.close();

    // 1b. ������ ������������ �����:
    BufferedReader stdin =
      new BufferedReader(
        new InputStreamReader(System.in));      
    System.out.print("Enter a line:");
    System.out.println(stdin.readLine());

    // 2. ���� �� ������
    StringReader in2 = new StringReader(s2);
    int c;
    while((c = in2.read()) != -1)
      System.out.print((char)c);

    // 3. ��������������� ���� �� ������
    try {
      DataInputStream in3 =
        new DataInputStream(
          new ByteArrayInputStream(s2.getBytes()));
      while(true)
        System.out.print((char)in3.readByte());
    } catch(EOFException e) {
      System.err.println("End of stream");
    }

    // 4. ����� � ����
    try {
      BufferedReader in4 =
        new BufferedReader(
          new StringReader(s2));
      PrintWriter out1 =
        new PrintWriter(
          new BufferedWriter(
            new FileWriter("IODemo.out")));
      int lineCount = 1;
      while((s = in4.readLine()) != null )
        out1.println(lineCount++ + ": " + s);
      out1.close();
    } catch(EOFException e) {
      System.err.println("End of stream");
    }

    // 5. �������� � ���������� ������
    try {
      DataOutputStream out2 =
        new DataOutputStream(
          new BufferedOutputStream(
            new FileOutputStream("Data.txt")));
      out2.writeDouble(3.14159);
      out2.writeChars("That was pi\n");
      out2.writeBytes("That was pi\n");
      out2.close();
      DataInputStream in5 =
        new DataInputStream(
          new BufferedInputStream(
            new FileInputStream("Data.txt")));
      BufferedReader in5br =
        new BufferedReader(
          new InputStreamReader(in5));
      // ���������� ������������ DataInputStream ��� ������:
      System.out.println(in5.readDouble());
      // ������ ����� ������������ "����������" readLine():
      System.out.println(in5br.readLine());
      // �� ��������� ������ �������.
      // ������, ��������� � ������� writeBytes, � �������:
      System.out.println(in5br.readLine());
    } catch(EOFException e) {
      System.err.println("End of stream");
    }

    // 6. ������/������ ������ � ������������ �������
    RandomAccessFile rf =
      new RandomAccessFile("rtest.dat", "rw");
    for(int i = 0; i < 10; i++)
      rf.writeDouble(i*1.414);
    rf.close();

    rf =
      new RandomAccessFile("rtest.dat", "rw");
    rf.seek(5*8);
    rf.writeDouble(47.0001);
    rf.close();

    rf =
      new RandomAccessFile("rtest.dat", "r");
    for(int i = 0; i < 10; i++)
      System.out.println(
        "Value " + i + ": " +
        rf.readDouble());
    rf.close();
  }
} 