// The "FullScreenTest" class.
import java.awt.*;
import javax.swing.*;

public class FullScreenTest
{
    private GraphicsDevice device;


    public FullScreenTest ()
    {
	// set up window
	JFrame window = new JFrame ();
	window.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
	window.setUndecorated (true);
	window.setResizable (false);
	DisplayMode displayMode = new DisplayMode (800, 600, 16, 60);

	// get the GraphicsDevice
	GraphicsEnvironment environment =
	    GraphicsEnvironment.getLocalGraphicsEnvironment ();
	device = environment.getDefaultScreenDevice ();

	// use the JFrame as the full screen window
	device.setFullScreenWindow (window);

	// set the background color, foreground color, and font
	window.setBackground (Color.blue);
	window.setForeground (Color.white);
	window.setFont (new Font ("Arial", Font.PLAIN, 24));

	// run full screen example
	run (displayMode);
    } // FullScreenTest Constructor


    public void run (DisplayMode displayMode)
    {
	try
	{
	    // change the display mode
	    device.setDisplayMode (displayMode);
	    // take a nap
	    try
	    {
		Thread.sleep (10000);
	    }
	    catch (InterruptedException ex)
	    {
		// do nothing
	    }
	}
	finally
	{
	    // restores the screen's display mode.
	    Window window = device.getFullScreenWindow ();
	    if (window != null)
	    {
		window.dispose ();
	    }
	    device.setFullScreenWindow (null);
	}
    } // run method


    public void paint (Graphics g)
    {
	g.drawString ("Blue Screen of Example", 20, 50);
    }


    public static void main (String [] args)
    {
	new FullScreenTest ();
    } // main method
} // FullScreenTest class
