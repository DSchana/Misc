#include "car.h"

using namespace test;

Car::Car(string n_model, int n_hp) {
	model = n_model;
	hp = n_hp;
	speed = 0;
}

string Car::getModel() {
	return model;
}

int Car::getHp() {
	return hp;
}

int Car::getSpeed() {
	return speed;
}