// BasicAssign3.java

import java.util.*;
import java.awt.geom.*;

public class BasicAssign3 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		double  x = kb.nextDouble(),
				y = kb.nextDouble(),
				x1 = kb.nextDouble(),
				y1 = kb.nextDouble(),
				x2 = kb.nextDouble(),
				y2 = kb.nextDouble();
		 Point2D.Double point = new Point2D.Double(x, y);
		 Line2D.Double line = new Line2D.Double(x1, y1, x2, y2);

		 if (line.ptLineDist(point) == 0.0) {
		 	System.out.println("Does intersect");
		 } else {
		 	System.out.println("Does not intersect");
		 }
	}
}