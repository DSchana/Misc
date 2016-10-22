#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

namespace test {
	class Car {
	private:
		string model;
		int hp;
		int speed;

	public:
		Car(string n_model, int n_hp);
		string getModel();
		int getHp();
		int getSpeed();
		
	};
}
#endif