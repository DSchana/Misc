#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double g, c, t, d, v;
	cin >> g >> c >> t;

	d = (g/2.0)*pow(t, 2);
	v = g*t;

	cout << d << endl << v << endl;
}