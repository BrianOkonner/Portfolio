import java.awt.*;

import javax.swing.*;

/*
 * Created on 19.04.2005
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
public class MyNote extends JFrame{
	MyNote(String title){
		super(title);
		
		Container c =getContentPane();
		
		JTextField tf =new JTextField("Вводите текст",50);
		c.add(tf,BorderLayout.NORTH);
		
		JTextArea ta =new JTextArea();
		ta.setEditable(false);
		c.add(ta);
		
		JPanel p = new JPanel(); 
		c.add(p,BorderLayout.SOUTH);
		JButton b = new JButton("Перенести");
		p.add(b);
		
		tf.addActionListener(new TextMove(tf,ta));
		b.addActionListener(new TextMove(tf,ta));
		
		setSize(300,200);
		setVisible(true);
	}

	public static void main(String[] args) {
		JFrame f = new MyNote("   Обработка ActionEvent");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
