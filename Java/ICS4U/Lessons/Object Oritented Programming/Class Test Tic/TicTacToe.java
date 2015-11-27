/**
 * @(#)TicTacToe.java
 *
 *
 * @author
 *	Mr. McKenzie
 * 
 * @version 1.00 2012/11/20
 */
 
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;

public class TicTacToe extends JFrame implements  MouseListener{
    private TicBoard board;
    private int turn;
    
    public TicTacToe(){
		super("Tic-Tac-Toe");

		board = new TicBoard();		// construct a new TicBoard
		turn = TicBoard.X;
		
		addMouseListener(this);
		setSize(500,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}
    
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}    
    public void mouseClicked(MouseEvent e){}    

    public void mousePressed(MouseEvent e){    
 	
    	if(board.gameOver())	// If someone won then the game is over, ignore any new moves
    		return;
    		
		int x = e.getX();
		int y = e.getY();
		
		if(x>100 && x<400 && y>100 && y<400){
			int gx=x/100-1;
			int gy=y/100-1;
			
			if(board.open(gx,gy)){ 			// checks if the spot has no X or O in it
				board.move(gx,gy,turn);		// sets the spot to whomevers turn it is
				turn = TicBoard.X + TicBoard.O - turn; 
				repaint();
				if(board.gameOver()){
					setTitle(board.winner()+" Wins!");	// If someone won display winner in the title
														// If all spots are full with no winner put Cats Wins
				}
			} 
		}
	}
	
	public void paint(Graphics g){
		Graphics2D g2D = (Graphics2D)g;
		
        g2D.setStroke(new BasicStroke(5));
        g2D.setColor(Color.YELLOW);	
		g2D.fillRect(0,0,500,500);
		
		g2D.setColor(Color.BLACK);	
		g2D.drawLine(200,100,200,400);
		g2D.drawLine(300,100,300,400);
		g2D.drawLine(100,200,400,200);
		g2D.drawLine(100,300,400,300);
		
		for(int i = 0; i<3; i++){
			for(int j = 0; j<3; j++){
				if(board.get(i,j) == TicBoard.X){

					g2D.setColor(Color.BLACK);	
					g2D.drawLine(i*100+110,j*100+110,i*100+190,j*100+190);
					g2D.drawLine(i*100+110,j*100+190,i*100+190,j*100+110);
				}
				if(board.get(i,j) == TicBoard.O){
					g2D.setColor(Color.RED);
					g2D.drawOval(i*100+110,j*100+110,80,80);
				}
			}
			System.out.println();
		}
	}
	
    public static void main(String[] args) {
       new TicTacToe();
    }
}
