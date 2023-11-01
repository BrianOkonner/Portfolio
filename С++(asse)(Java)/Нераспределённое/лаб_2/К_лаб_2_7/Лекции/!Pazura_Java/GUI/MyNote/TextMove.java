import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JTextArea;
import javax.swing.JTextField;

/*
 * Created on 19.04.2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */


public class TextMove implements ActionListener{
	private JTextField tf;
	private JTextArea ta;
	TextMove(JTextField tf, JTextArea ta){
		this.tf = tf; this.ta=ta;
	}
	public void actionPerformed(ActionEvent ae){
		ta.append(tf.getText()+"\n");
	}
}
