import javax.swing.*;
import java.awt.*;

    
public class DB_Graphics extends JFrame 
{
	private int x,vx;
	private Image dbImage; 
	private Graphics dbg;
	
	public DB_Graphics(){
		super("DB_Graphics");
		
		x = 100;
		vx = 5;
		setSize (500, 530);
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		setVisible (true);
	}
	
    public static void delay (long len)
    {
		try{
		    Thread.sleep (len);
		}
		catch (InterruptedException ex){
		    System.out.println(ex);
		}
    }
 

 	public void move(){
 		x += vx;
 		if(x<0 || x > getWidth())
 			vx *= -1;
 	}
 
    public void paint(Graphics g){
		if (dbImage == null){
			dbImage = createImage (getWidth(), getHeight());
			dbg = dbImage.getGraphics ();
		}
		
		//drawing to double buffer image then copying to screen	
		dbg.setColor (getBackground ());
		dbg.fillRect (0, 0, this.getSize().width, this.getSize().height);		
		dbg.setColor (Color.red);
		dbg.fillOval(x,200,50,50);
		
		g.drawImage (dbImage, 0, 0, this);
	}
	
	public static void main(String []args){
		DB_Graphics frame= new DB_Graphics();
		while(true){
			frame.move();
	 		frame.repaint();
	 		delay(20);
		}
	}
}
