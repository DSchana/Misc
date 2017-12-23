public class Q2 {
	public static void main(String[] args) {
		Appointment[] a = new Appointment[3];

		a[0] = new OneTime("one", 1, 1, 1);
		a[1] = new Daily("day", 2, 2, 2);
		a[2] = new Monthly("mon", 1, 4, 6);

		for (int i = 0; i < 3; i++) {
			System.out.println(a[i].occursOn(1, 1, 1));
		}
	}
}
