
package javaapplication6;
public class JavaApplication6 {

    public static void main(String[] args) {
        location[] mas=new location[6];
    
     rect A=new rect(0,0,3,2);
     rect B=new rect(2,1,4,3);
     rect C=new rect(4,1,6,3);
     rect D=new rect(0,4,2,5);
     circle I=new circle(1,2,4);
     circle F=new circle(1,5,5);
    mas[0]=A;
    mas[1]=B;
    mas[2]=C;
    mas[3]=D;
    mas[4]=I;
    mas[5]=F;
    System.out.println("Пересекающиеся прямоугольники A и B возвращают: "+mas[0].Location(mas[1]));
    System.out.println("Соприкосающиеся прямоугольники B и C возвращают: "+mas[2].Location(mas[1]));
    System.out.println("Несоприкасающиеся прямоугольники A и D возвращают: "+mas[0].Location(mas[3]));
    System.out.println("Касающиеся прямоугольник B и окружность I возвращают: "+mas[1].Location(mas[4]));
    System.out.println("Пересекающиеся прямоугольник D и окружность I возвращают: "+mas[4].Location(mas[3]));
    System.out.println("Непересекающиеся прямоугольник A и окружность F возвращают: "+mas[0].Location(mas[5]));
    }
    
}
