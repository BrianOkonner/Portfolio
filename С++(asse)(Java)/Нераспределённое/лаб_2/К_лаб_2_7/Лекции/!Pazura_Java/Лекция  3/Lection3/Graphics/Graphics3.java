package Graphics;

import java.awt.*;
import java.awt.event.*;

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
public class Graphics3 extends Frame{
	Graphics3(String s){
		super(s);
		}
	public void paint(Graphics g){ 

	    g.setFont(new Font("Serif", Font.ITALIC | Font.BOLD, 30)); 

	    g.drawString("Hello, XXI century World!", 20, 100);  

	  }  


	public static void main(String[] args) {
		 Frame f = new Graphics3("Здравствуй, мир XXI века!"); 

		    f.setSize(400, 150); 

		    f.setVisible(true); 

		    f.addWindowListener(new WindowAdapter(){ 

		      public void windowClosing(WindowEvent ev){ 

		        System.exit(0);  

		      } 

		    });  
          

		
	}
}
