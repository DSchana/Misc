#include <cstdio>
#include <iostream>
#include <pigpio.h>

using namespace std;

int main() {
	int in;

	cout << "START..." << endl;
	gpioInitialise();

	gpioSetMode(12, PI_OUTPUT);
	gpioSetPWMfrequency(12, 333);
	gpioPWM(12, 0);

	while (true) {
		cin >> in;
		if (in == -1) break;

		gpioPWM(12, in);
	}

	gpioPWM(12, 0);

	gpioTerminate();

	return 0;
}
