package Graphics;

/*
 * Created on 05.06.2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Generation - Code and Comments
 */
/**
 * @author Admin
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Generation - Code and Comments
 */
import java.awt.*;  

import java.awt.event.*; 

class Components1 extends Frame{  

Components1(String s){ super(s);  

setLayout(null); 

Font f = new Font("Serif", Font.BOLD, 15);  

setFont(f); 

Label L1 = new Label("Выберите товар:", Label.CENTER);  

L1.setBounds(10, 50, 130, 30); add(L1);  

Label L2 = new Label("Выберите способ оплаты:");  

L2.setBounds(160, 50, 200, 30); add(L2); 

Checkbox ch1 = new Checkbox("Книги");  

ch1.setBounds(20, 90, 100, 30); add(ch1);  

Checkbox ch2 = new Checkbox("Диски");  

ch2.setBounds(20, 120, 100, 30); add(ch2);  

Checkbox ch3 = new Checkbox("Игрушки");  

ch3.setBounds(20, 150, 100, 30); add(ch3); 

CheckboxGroup grp = new CheckboxGroup(); 

Checkbox chg1 = new Checkbox("Почтовым переводом", grp, true); 

chg1.setBounds(170, 90, 200, 30); add(chg1); 

Checkbox chg2 = new Checkbox("Кредитной картой", grp, false); 

chg2.setBounds(170, 120, 200, 30); add(chg2); 

Button b1 = new Button("Продолжить");  

b1.setBounds( 30, 220, 100, 30); add(b1);  

Button b2 = new Button("Отменить");  

b2.setBounds(140, 220, 100, 30); add(b2);  

Button b3 = new Button("Выйти");  

b3.setBounds(250, 220, 100, 30); add(b3); 

Choice choice1=new Choice();
choice1.setBounds(170,150,170,30);
choice1.add("Наличные");
choice1.add("Кредитная карточка");
choice1.add("Банковский чек");
add(choice1);

setSize(400, 300); 

setVisible(true);  

}  

public static void main(String[] args){ 

Frame f = new Components1 (" Простые компоненты"); 

f.addWindowListener(new WindowAdapter(){ 

public void windowClosing(WindowEvent ev){ 

System.exit(0);  

} 

});  

}  

} 


