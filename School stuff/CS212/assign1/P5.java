public class P5 {
	public static void main(String[] args) {
		double s;
		double s0 = 2;
		double v0 = 3;
		double g = 9.81;
		double t = 4;

		double G;
		double a = 9.81;
		double p = 5;
		double m1 = 10;
		double m2 = 15;

		s = s0 + v0 + 0.5 * g * t * t;
		G = 4 * 3.14159 * 3.14159 * (a * a * a) / (p * p * (m1 * m2));
	}
}
