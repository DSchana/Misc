// led.cpp

#include <wiringPi.h>

int main(int argc, char const *argv[]) {
	wiringPiSetup();
	pinMode(11, OUTPUT);

	for (int i=0; i<5; i++) {
		digitalWrite(11, HIGH);
		delay(500);

		digitalWrite(11, LOW);
		delay(500);
	}

	return 0;
}