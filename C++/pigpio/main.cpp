#include <cstdio>
#include <pigpio.h>

using namespace std;

int main() {
	gpioInitialise();

	gpioSetMode(12, PI_OUTPUT);
	gpioSetPWMfrequency(12, 333);

	gpioPWM(12, 128);
	time_sleep(5);
	gpioPWM(12, 0);

	gpioTerminate();

	return 0;
}
