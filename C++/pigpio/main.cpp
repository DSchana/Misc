#include <cstdio>
#include <iostream>
#include <pigpio.h>

using namespace std;

int main() {
	cout << "START..." << endl;
	gpioInitialise();

	gpioSetMode(12, PI_OUTPUT);
	gpioSetPWMfrequency(12, 333);

	gpioPWM(12, 128);  // Talon OFF
	time_sleep(5);

	cout << "Ready. Flip switch to on..." << endl;
	scanf("");

	cout << "LOW..." << endl;
	gpioPWM(12, 85);  // Talon MAX REV
	time_sleep(5);

	cout << "HIGH..." << endl;
	gpioPWM(12, 170);  // Talon MAX FORW
	time_sleep(5);

	cout << "Turning off..." << endl;
	gpioPWM(12, 128);  // Talon OFF
	time_sleep(10);

	cout << "DONE. Flip switch to off" << endl;
	scanf("");

	gpioTerminate();

	return 0;
}
