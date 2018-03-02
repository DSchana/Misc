#include <cstdio>
#include <pigpio.h>

using namespace std;

int main() {
	gpioInitialise();

	gpioSetMode(12, PI_OUTPUT);
	gpioSetPWMfrequency(12, 333);

	gpioPWM(12, 128);  // Talon OFF
	time_sleep(5);
	gpioPWM(12, 85);  // Talon MAX REV
	time_sleep(5);
	gpioPWM(12, 170);  // Talon MAX FORW
	time_sleep(5)
	gpioPWM(12, 128);  // Talon OFF
	time_sleep(10);

	gpioTerminate();

	return 0;
}
