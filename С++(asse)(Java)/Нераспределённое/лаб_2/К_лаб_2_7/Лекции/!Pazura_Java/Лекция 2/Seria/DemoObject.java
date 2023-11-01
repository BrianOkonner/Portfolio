import java.io.*;

public class DemoObject implements Serializable {

    private static int counter = 0;

    private transient int cnt = 0;
    private String number;

    public DemoObject(int numb) {
        cnt = counter++;
        number = String.valueOf(numb);
    }

    public DemoObject() {
        number = null;
    }

    public String toString() {
        return " "+cnt+": "+number;
    }

    public static void dropCounter() {
        counter = 0;
    }

    private void readObject(ObjectInputStream in)
                     throws IOException, ClassNotFoundException {
        in.defaultReadObject();
        cnt = counter++;
    }
}
