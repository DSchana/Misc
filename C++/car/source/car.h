#ifndef CAR_H
#define CAR_H

#include <string>
#include <cmath>
#include <map>

using namespace std;

namespace test {
	class Car {
	private:
		string model;
		int hp;
		int speed;
		map<int, int> t_map;

	public:
		Car(string n_model, int n_hp);
		string getModel();
		int getHp();
		int getSpeed();
		
	};
}
#endif
