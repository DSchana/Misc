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

	gpioPWM(PIN, 128);  // Talon OFF
	time_sleep(5);

	cout << "Ready. Flip switch to on..." << endl;
	cin >> in;

	cout << "LOW..." << endl;
	gpioPWM(PIN, 85);  // Talon MAX REV
	time_sleep(2);

	cout << "HIGH..." << endl;
	gpioPWM(PIN, 170);  // Talon MAX FORW
	time_sleep(2);

	cout << "Turning off..." << endl;
	gpioPWM(PIN, 128);  // Talon OFF
	time_sleep(10);

	cout << "DONE. Flip switch to off" << endl;
	cin >> in;

	gpioTerminate();

	return 0;
}
