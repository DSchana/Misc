#include <stdio.h>

double triArea(double b, double h) {
	double p;
	p = b * h;
	return p / 2;
}

int main() {
	printf("%f\n", triArea(3, 4));
	
	return 0;
}
