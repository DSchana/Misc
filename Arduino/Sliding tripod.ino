// Sliding tripod.ino

#include <Servo.h>

int slide_motor_pin = 9;
int start_button_pin = 2;
int stop_button_pin = 3;
int pot_pin = A0;
int rot_pin = A1;

Servo rot_servo;

void setup() {
	rot_servo.attach(10);
	pinMode(slide_motor_pin, OUTPUT);
	pinMode(start_button_pin, OUTPUT);
	pinMode(stop_button_pin, OUTPUT);
	pinMode(pot_pin, INPUT);
	pinMode(rot_pin, INPUT);
}

void loop() {
	// Do stuff
}