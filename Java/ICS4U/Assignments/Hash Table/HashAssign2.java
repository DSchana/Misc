// HashAssign2.java
// Dilpreet Chana

import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import javax.swing.*;

public class HashAssign2 extends JFrame implements ActionListener {
	Panel panel;

	// Init frame
	public HashAssign2() {
		super("HashAssign2");
		setSize(800, 600);
		setLayout(null);

		panel = new Panel(this);
		panel.setLocation(0, 0);
		panel.setSize(800, 600);

		add(panel);

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
		repaint();
	}

	public static void main(String[] args) {
		HashAssign2 hash = new HashAssign2();
	}
}

class Panel extends JPanel implements MouseListener, MouseMotionListener {
	HashTable<Emotion> emotions = new HashTable<Emotion>();
	private int mx, my;
	private boolean mouseDown;
	private boolean[] keys;
	private HashAssign2 mainFrame;
	private Image map;

	public Panel(HashAssign2 m) {
		super();

		setFocusable(true);
		grabFocus();

		keys = new boolean[KeyEvent.KEY_LAST - 1];
		map = new ImageIcon("./Hash Tabel/windsor.png").getImage();
		mainFrame = m;
		addMouseListener(this);
		addMouseMotionListener(this);

		readEmotions();
	}

	public void mouseClicked(MouseEvent e) { }
	public void mouseEntered(MouseEvent e) { }
	public void mosueExited(MouseEvent e) { }

	public void mousePressed(MouseEvent e) {
		mouseDown = true;
	}

	public void mouseReleased(MouseEvent e) {
		mouseDown = false;
	}

	public void mouseDragged(MouseEvent e) {
		// Update mouse position
		mx = e.getX();
		my = e.getY();
	}

	public void paintComponent(Graphics g) {
		g.drawImage(map, 0, 0, this);

		if (!mouseDown) {
			repaint();
			return;
		}

		showEmotions(g);

		repaint();
	}

	private void readEmotions() {
		Scanner fileIn;

		// Try to open file
		try {
			fileIn = new Scanner(new File("./Hash Assign/creeper.txt"));
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found");
			System.exit(1);
		}

		// Add emotions to HashTable
		while (fileIn.hasNext()) {
			Emotion emot = new Emotion(fileIn.nextLine());
			// New coord for emotion
			if (emotions.get(emot.hashCode()) == null) {
				emotions.add(emot);
			}
			// Overlap of emotion
			else {
				emotions.get(emot.hashCode()).merge(emot);
			}
		}
	}

	private void showEmotions(Graphics g) {
		for (int x = mx - 10; x < mx + 10; x++) {
			for (int y = my - 10; y < my + 10; y++) {
				if (x < 0 || x > 800 || y < 0 || y > 600) {
					continue;  // Skip if coords are off screen
				}

				Emotion emot = emotions.get(Integer.parseInt("" + x + y));

				// Check of emotion is not null and within 10px radius of mouse
				if (emot != null && Math.sqrt(Math.pow(x - emot.getX(), 2) + Math.pow(y - emot.getY(), 2)) <= 10) {
					g.setColor(emot.getColour());
					g.fillRect(emot.getX() - 1, emot.getY() - 1, 1, 1);
				}
			}
		}
	}
}

class Emotion {
	private int x, y;
	private float lh, hs, eb;
	private int overLaps = 0;  // Counts the number of emotions from the text file lie on this x, y

	public Emotion(int x, int y, float lh, float hs, float eb) {
		this.x = x;
		this.y = y;
		this.lh = lh;
		this.hs = hs;
		this.eb = eb;
	}

	public Emotion(String str) {
		String[] props = str.split(" ");
		this.x = Integer.parseInt(props[0]);
		this.y = Integer.parseInt(props[1]);
		this.lh = (float)Integer.parseInt(props[2]);
		this.hs = (float)Integer.parseInt(props[3]);
		this.eb = (float)Integer.parseInt(props[4]);
	}

	// Get methods
	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public float getLH() {
		return lh;
	}

	public float getHS() {
		return hs;
	}

	public float getEB() {
		return eb;
	}

	// map lh, hs, eb to r, g, b
	public Color getColour() {
		return new Color((float)((lh + 100)/200.0), (float)((hs + 100)/200.0), (float)((eb + 100)/200.0));
	}

	// Get hashCode of emotion
	public int hashCode() {
		// Hash Code made from coordinates to allow for easier
		// comparison to found coords.
		return Integer.parseInt("" + x + y);
	}

	// Merge this emotion with another on the same point by averaging the
	// lh, hs, eb values
	public Emotion merge(Emotion toMerge) {
		overLaps++;
		Emotion ret = new Emotion(x, y,
								 (lh*overLaps + toMerge.getLH())/(overLaps + 1),
								 (hs*overLaps + toMerge.getHS())/(overLaps + 1),
								 (eb*overLaps + toMerge.getEB())/(overLaps + 1));
		return ret;
	}
}