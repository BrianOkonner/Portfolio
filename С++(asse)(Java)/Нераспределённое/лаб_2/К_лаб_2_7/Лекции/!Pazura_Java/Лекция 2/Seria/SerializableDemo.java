import java.util.*;
import java.io.*;

public class SerializableDemo {

    public static void main(String args[]) {

//--- 1. Создадим ArrayList из 20 элементов DemoObject
        ArrayList list = new ArrayList();
        Random r = new Random();
        for ( int i = 0; i < 20; i++ ) {
            DemoObject obj = new DemoObject(r.nextInt()%1000);
            list.add(obj);
        }
//--- 2. Добавим еще один элемент в 10-ю позицию списка
        list.add(10, new DemoObject(1111));
//--- 3. Распечатаем результат
        print("Исходный список", list);
//--- 4. Сохраним это в файле
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
//--- 5. Восстановим все из файла
        DemoObject.dropCounter();     // сброс счетчика объектов
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
//--- 6. Отпечатаем результат
        print("Восстановленный список", list);
    }

    static void print(String title, List list) {
        System.out.println(title);
        Iterator iter = list.iterator();
        for ( int i = 0; iter.hasNext(); i++ ) {
            System.out.println("N "+i+"="+iter.next());
        }
    }
}
      
