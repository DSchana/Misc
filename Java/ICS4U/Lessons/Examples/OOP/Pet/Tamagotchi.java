// Tamagotchi.java

public class Tamagotchi {
	private int hunger;
	private int happiness;
	private int discipline;
	private int age;
	private String name;

	public Tamagotchi(String name) {
		name = name;
	}

	public void age() {
		age++;
		happiness--;
		discipline--;
		hunger++;
	}

	public void feed() {
		hunger = Math.max(0, hunger - 10);
	}

	public void play() {
		happiness = Math.min(100, happiness - 10);
	}

	public void scold() {
		discipline = Math.min(100, discipline - 10);
	}

	public String toString() {
		String ret = "";
		ret += name + " ";
		ret += age / 1440 + " ";
		ret += (age / 60 - (age / 1440) * 1440) + " ";
		ret += (age - (age / 60) * 60) + " ";

		// Happiness
		if (happiness < 20)
			ret += "Critically unhappy ";
		else if (happiness < 40)
			ret += "I has a sad ";
		else if (happiness < 60)
			ret = ret;
		else if (happiness < 80)
			ret += "I is happy ";
		else if (happiness <= 100)
			ret += "I is super mega happy ";

		// Discpline
		if (discipline < 20)
			ret += "Screw you ";
		else if (discipline < 40)
			ret += "Your NOT my real mom ";
		else if (discipline < 60)
			ret = ret;
		else if (discipline < 80)
			ret += "Ok whatever ";
		else if (discipline <= 100)
			ret += "Sir, yes sir! ";

		// Hunger
		if (hunger < 20)
			ret += "I am full ";
		else if (hunger < 40)
			ret += "Food is good ";
		else if (hunger < 60)
			ret = ret;
		else if (hunger < 80)
			ret += "Feed me ";
		else if (hunger <= 100)
			ret += "Need food pls ";

		return ret;
	}
}