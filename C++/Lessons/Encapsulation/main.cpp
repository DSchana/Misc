// main.cpp

#include <iostream>

using namespace std;

class Frog {
private:
	string name;
	string getName() { return name; }

public:
	Frog(string name): name(name) {}
	void info() { cout << "Name: " << getName() << endl; }
};

int main() {
	Frog frog("Freddy");
	frog.info();

	return 0;
}
