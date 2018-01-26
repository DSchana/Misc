#include "car.h"
#include <cstdio>

using namespace std;
using namespace test;

int main() {
	Car car1("BMW", 400);
	Car car2("Hellcat", 707);
	car1.model;

	printf("hp-%d speed-%d\n", car1.getHp(), car1.getSpeed());
	printf("hp-%d speed-%d\n", car2.getHp(), car2.getSpeed());

	return 0;
}
