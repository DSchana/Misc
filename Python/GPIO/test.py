import RPi.GPIO as GPIO
import time

def flashLed(led):
	GPIO.output(led, 1)
	time.sleep(0.5)
	GPIO.output(led, 0)
	time.sleep(0.5)

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

led = 4

GPIO.setup(led, GPIO.OUT)

flashLed(led)

GPIO.cleanup()
