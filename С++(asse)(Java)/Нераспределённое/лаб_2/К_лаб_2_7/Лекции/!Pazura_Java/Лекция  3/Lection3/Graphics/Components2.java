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

class Components2 extends Frame{  

Components2(String s)
{ super(s);  

setLayout(null);  

setFont(new Font("Serif", Font.BOLD, 15)); 

Label L1 = new Label("�������� �����:", Label.CENTER);  

L1.setBounds(10, 50, 130, 30); add (L1);  

Label L2 = new Label("�������� ������ ������:");  

L2.setBounds(170, 50, 200, 30); add(L2); 

List l = new List(2, true); 

l.add("�����"); 

l.add("�����"); 

l.add("�������"); 

l.setBounds(20, 90, 100, 40); add(l); 

Choice ch = new Choice(); 

ch.add("�������� ���������"); 

ch.add("��������� ������"); 

ch.setBounds(170, 90, 200,30); add(ch); 

Button b1 = new Button("����������"); 

b1.setBounds( 30, 150, 100, 30); add(b1); 

Button b2 = new Button("��������"); 

b2.setBounds(140, 150, 100, 30); add(b2); 

Button b3 = new Button("�����"); 

b3.setBounds(250, 150, 100, 30); add(b3); 

setSize(400, 200); setVisible(true); 

} 

public static void main(String[] args){ 

Frame f = new Components2(" ������� ����������");  

f.addWindowListener(new WindowAdapter(){ 

public void windowClosing(WindowEvent ev){ 

System.exit(0);  

} 

});  

}  

} 


