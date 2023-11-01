import java.util.*;
import java.io.*;

public class SerializableDemo {

    public static void main(String args[]) {

//--- 1. �������� ArrayList �� 20 ��������� DemoObject
        ArrayList list = new ArrayList();
        Random r = new Random();
        for ( int i = 0; i < 20; i++ ) {
            DemoObject obj = new DemoObject(r.nextInt()%1000);
            list.add(obj);
        }
//--- 2. ������� ��� ���� ������� � 10-� ������� ������
        list.add(10, new DemoObject(1111));
//--- 3. ����������� ���������
        print("�������� ������", list);
//--- 4. �������� ��� � �����
        ObjectOutputStream out = null;
        try {
             out = new ObjectOutputStream(new BufferedOutputStream(
                                          new FileOutputStream("Demo.ser")));
             out.writeObject(list);
        } catch ( IOException ex ) {
             ex.printStackTrace();
        } finally {
             if ( out != null )
                 try {
                     out.close();
                 } catch ( IOException ex ) {
                     ex.printStackTrace();
                 }
        }
//--- 5. ����������� ��� �� �����
        DemoObject.dropCounter();     // ����� �������� ��������
        ObjectInputStream in = null;
        try {
            in = new ObjectInputStream(new BufferedInputStream(
                                       new FileInputStream("Demo.ser")));
            list = (ArrayList)in.readObject();
        } catch ( IOException ex ) {
            ex.printStackTrace();
        } catch ( Exception ex ) {
            ex.printStackTrace();
        } finally {
             if ( in != null )
                 try {
                     in.close();
                 } catch ( IOException ex ) {
                     ex.printStackTrace();
                 }
        }
//--- 6. ���������� ���������
        print("��������������� ������", list);
    }

    static void print(String title, List list) {
        System.out.println(title);
        Iterator iter = list.iterator();
        for ( int i = 0; iter.hasNext(); i++ ) {
            System.out.println("N "+i+"="+iter.next());
        }
    }
}
      
