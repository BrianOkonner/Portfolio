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
public class Graphics2 extends Frame{
	 Graphics2(String s){  
	    super (s); 
	    setSize(400, 150);  
	    setVisible(true);
	    
	    addWindowListener(
	    new WindowAdapter(){ 
	      public void windowClosing(WindowEvent ev){ 
	        System.exit (0);  
	      } 
	    });  

	  }  


	public static void main(String[] args) {
		 new Graphics2(" Моя программа");  
	}
}
