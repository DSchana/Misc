import java.util.*;
import java.lang.*;

public class Percent implements Comparable<Percent> {
	public double val;

	public Percent(double v) {
		val = v;
	}

	public Percent(int n, int d) {
		val = n / d;
	}

	public String toString() {
		return String.format("%.2f", val*100) + "%";
	}

	@Override
	public int compareTo(Percent p) {
		return (int)(this.val - p.val);
	}
}