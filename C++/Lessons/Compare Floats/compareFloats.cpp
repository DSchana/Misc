// compareFloats.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
	float value1 = 1.1;

	cout << setprecision(10) << value1 << endl;

	if (value1 == 1.10) {
		cout << "equals" << endl;
	} else {
		cout << "Not equals" << endl;
	}

	return 0;
}