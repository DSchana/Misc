#working_hopfuly_drone.py

import pygame
import os
import RPi.GPIO as GPIO

pygame.init()

# Headless shit
os.environ["SDL_VIDEODRIVER"] = "dummy"
pygame.display.init()
screen = pygame.display.set_mode((1, 1))

running = True
clock = pygame.time.Clock()
pygame.joystick.init()

while running:
        for e in pygame.event.get():
                "Keep the loop going"

        joystick_count = pygame.joystick.get_count()

        for i in range(joystick_count):
                joystick = pygame.joystick.Joystick(i)
                joystick.init()

                axes = joystick.get_numaxes()
                axes_list = []

                for j in range(axes):
                        axis = joystick.get_axis(j)
                        axes_list.append(round(axis, 1))

                print(axes_list)


        clock.tick(60)

pygame.quit()
