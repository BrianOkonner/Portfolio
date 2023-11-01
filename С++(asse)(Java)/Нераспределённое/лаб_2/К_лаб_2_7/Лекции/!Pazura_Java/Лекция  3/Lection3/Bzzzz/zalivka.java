package Bzzzz;

import java.awt.*; 

import java.awt.geom.*; 

import java.awt.image.*; 

import java.awt.event.*; 

class Zalivka extends Frame{ 
	Zalivka(String s){ super(s) ; 


setSize(300, 300);  

setVisible(true);  

addWindowListener(new WindowAdapter(){ 

public void windowClosing(WindowEvent ev){ 

System.exit(0); } 

});  

} 
	public void paint(Graphics gr){  

		Graphics2D g = (Graphics2D)gr;
		BufferedImage bi=new BufferedImage(20, 20, BufferedImage.TYPE_INT_RGB);  

			Graphics2D big = bi.createGraphics();  

			big.draw(new Line2D.Double(0.0, 0.0, 10.0, 10.0));  

			big.draw(new Line2D.Double(0.0, 10.0, 10.0, 0.0));  

			TexturePaint tp = new TexturePaint(bi, 

			  new Rectangle2D.Double(0.0, 0.0, 10.0, 10.0));  

			g.setPaint(tp); 

			g.fill(new Rectangle2D. Double (50, 50, 200, 200));  
			GradientPaint gp=new GradientPaint(100,100,Color.white,150,150,Color.black,true);
			g.setPaint(gp);
			g.fill(new Ellipse2D.Double(100,100,200,200));
			
}
public static void main(String[] args){ 

new Zalivka(" Способы заливки");  

}  

}