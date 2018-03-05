#include <cstdio>
#include <iostream>
#include <pigpio.h>

#define PIN 18

using namespace std;

int main() {
	int in;

	cout << "START..." << endl;
	gpioInitialise();

	gpioSetMode(PIN, PI_OUTPUT);
	gpioSetPWMfrequency(PIN, 333);
	gpioPWM(PIN, 0);

	while (true) {
		cin >> in;
		if (in == -1) break;

		gpioPWM(PIN, in);
	}

	gpioPWM(PIN, 0);

	gpioTerminate();

	return 0;
}
