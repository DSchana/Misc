import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

def fadeFlashLed(led):
	for i in range(0, 100, 2):
		led.ChangeDutyCycle(i)
		time.sleep(0.01)

	for i in range(100, 0, -2):
		led.ChangeDutyCycle(i)
		time.sleep(0.01)

led = 4

GPIO.setup(led, GPIO.OUT)

light = GPIO.PWM(led, 50)
light.start(0)

for i in range(0, 5):
	fadeFlashLed(light)

light.stop()
GPIO.cleanup()