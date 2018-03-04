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

	gpioPWM(12, 128);  // Talon OFF
	time_sleep(5);

	cout << "Ready. Flip switch to on..." << endl;
	cin >> in;

	cout << "LOW..." << endl;
	gpioPWM(12, 85);  // Talon MAX REV
	time_sleep(2);

	cout << "HIGH..." << endl;
	gpioPWM(12, 170);  // Talon MAX FORW
	time_sleep(2);

	cout << "Turning off..." << endl;
	gpioPWM(12, 128);  // Talon OFF
	time_sleep(10);

	cout << "DONE. Flip switch to off" << endl;
	cin >> in;

	gpioTerminate();

	return 0;
}
