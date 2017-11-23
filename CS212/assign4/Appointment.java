public class Appointment {
	private String descrip;
	private String date;

	public Appointment(String des, int d, int m, int y) {
		descrip = des;
		date = "" + d + " " + m + " " + y;
	}

	public boolean occursOn(int d, int m, int y) {
		return date.equals(d + " " + m + " " + y);
	}

	@Override
	public String toString() {
		return "Appointment: " + descrip + " on " + date;
	}

	public String getDate() {
		return date;
	}
}
