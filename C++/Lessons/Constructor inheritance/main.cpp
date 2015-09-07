// main.cpp

#include <iostream>

using namespace std;

class Machine {
private:
	int id;

public:
	Machine(): id(0) { cout << "Machine created with no arguments" << endl; }
	void info() { cout << "Id: " << id << endl; }
};

class Vehicle: public Machine {
public:
        Vehicle() { cout << "Vehicle created with no arguments" << endl; }
};

int main() {
	Vehicle vehicle;
	Vehicle.info();

	return 0;
}
