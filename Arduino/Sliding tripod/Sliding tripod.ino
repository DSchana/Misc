// Sliding tripod.ino

#include <Servo.h>

int start_button_pin = 2;
int stop_button_pin = 3;
int speed_pin = A0;  // Speed potentiometer pin
int rot_pin = A1;  // Rotation potentiometer pin

int speed;

bool inMotion = false;

Servo rot_servo;
Servo slide_servo;

void setup()
{
	rot_servo.attach(10);
	slide_servo.attach(9);
	pinMode(start_button_pin, OUTPUT);
	pinMode(stop_button_pin, OUTPUT);
}

void loop()
{
	for (int i = 0; i < 180; i++) {
		slide_servo.write(i);
		delay(10);
	}
	speed = analogRead(speed_pin);
	speed = map(speed, 0, 1023, 0, 360);

	// Start or stop the sliding manually
	if (digitalRead(start_button_pin))
	{
		inMotion = true;
	}
	else if (digitalRead(stop_button_pin))
	{
		inMotion = false;
	}

	move();
}

void move()
{
	if (inMotion)
	{
		slide_servo.write(speed);
	}
	else
	{
		slide_servo.write(180);
	}
}