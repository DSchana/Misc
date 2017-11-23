public class Daily extends Appointment {
	public Daily(String des, int d, int m, int y) {
		super(des, d, m, y);
	}

	@Override
	public boolean occursOn(int d, int m, int y) {
		return true;
	}
}
