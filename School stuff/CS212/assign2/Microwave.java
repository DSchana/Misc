/*
 * Title:	Microwave.java
 * Author:	Dilpreet S. Chana
 * Description:	Microwave class definition
**/

public class Microwave {
	private int time;
	private int power_lvl;

	public Microwave() {
		this.time = 0;
		this.power_lvl = 0;
	}

	// Increment time by 30 sec
	public void increaseTime() {
		this.time += 30;
	}

	// Set power mode
	public void setPower(int pwr) {
		if (pwr == 1 || pwr == 2) {
			this.power_lvl = pwr;
		}
	}

	// Set to default
	public void reset() {
		this.time = 0;
		this.power_lvl = 0;
	}

	// Start cooking
	public void start() {
		if (this.power_lvl == 0) {
			System.out.println("No power level indicated");
			return;
		}

		System.out.printf("Cooking for %d seconds at %d power level\n", this.time, this.power_lvl);
	}
}
