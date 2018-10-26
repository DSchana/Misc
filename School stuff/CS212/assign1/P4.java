import java.net.*;
import javax.swing.*;
import javax.swing.ImageIcon;

public class P4 {
	public static void main(String[] args) throws Exception {
		URL imageLocation = new URL("http://horstmann.com/java4everyone/duke.gif");
		JOptionPane.showMessageDialog(null, "Hello", "Title", JOptionPane.PLAIN_MESSAGE, new ImageIcon(imageLocation));
	}
}
