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

Label L1 = new Label("�������� �����:", Label.CENTER);  

L1.setBounds(10, 50, 130, 30); add(L1);  

Label L2 = new Label("�������� ������ ������:");  

L2.setBounds(160, 50, 200, 30); add(L2); 

Checkbox ch1 = new Checkbox("�����");  

ch1.setBounds(20, 90, 100, 30); add(ch1);  

Checkbox ch2 = new Checkbox("�����");  

ch2.setBounds(20, 120, 100, 30); add(ch2);  

Checkbox ch3 = new Checkbox("�������");  

ch3.setBounds(20, 150, 100, 30); add(ch3); 

CheckboxGroup grp = new CheckboxGroup(); 

Checkbox chg1 = new Checkbox("�������� ���������", grp, true); 

chg1.setBounds(170, 90, 200, 30); add(chg1); 

Checkbox chg2 = new Checkbox("��������� ������", grp, false); 

chg2.setBounds(170, 120, 200, 30); add(chg2); 

Button b1 = new Button("����������");  

b1.setBounds( 30, 220, 100, 30); add(b1);  

Button b2 = new Button("��������");  

b2.setBounds(140, 220, 100, 30); add(b2);  

Button b3 = new Button("�����");  

b3.setBounds(250, 220, 100, 30); add(b3); 

Choice choice1=new Choice();
choice1.setBounds(170,150,170,30);
choice1.add("��������");
choice1.add("��������� ��������");
choice1.add("���������� ���");
add(choice1);

setSize(400, 300); 

setVisible(true);  

}  

public static void main(String[] args){ 

Frame f = new Components1 (" ������� ����������"); 

f.addWindowListener(new WindowAdapter(){ 

public void windowClosing(WindowEvent ev){ 

System.exit(0);  

} 

});  

}  

} 


