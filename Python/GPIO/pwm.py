import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(4, GPIO.OUT)

p = GPIO.PWM(4, 100)  # create an object p for PWM on port 4 at 50 Hertz

p.start(10)  # starts PWM on 50% duty cycle
time.sleep(2)

p.ChangeDutyCycle(90)  # change suty cycle to 90%
time.sleep(2)

for i in range(0, 100, 5):
	p.ChangeDutyCycle(i)
	time.sleep(0.5)

p.ChangeFrequency(10)  # change frequency to 100 Hertz
time.sleep(1)

p.stop()

GPIO.cleanup()
