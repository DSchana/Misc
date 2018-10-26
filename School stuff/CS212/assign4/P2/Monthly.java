public class Monthly extends Appointment {
	public Monthly(String des, int d, int m, int y) {
		super(des, d, m, y);
	}

	@Override
	public boolean occursOn(int d, int m, int y) {
		return super.getDate().split(" ")[0].equals(String.valueOf(d));
	}
}
