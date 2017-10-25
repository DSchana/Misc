/*
 * Title:	main.c
 * Author:	Dilpreet S. Chana
 * Description:	Create an image of five squares
 * Usage:	./main image colour_mid colour_top_left colour_top_right colour_bottom_left colour_bottom_right
**/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* RED = "255 42 26 ";
const char* GREEN = "87 154 113 ";
const char* BLUE = "24 154 202 ";
const char* YELLOW = "203 171 37 ";
const char* ORANGE = "204 142 36 ";
const char* CYAN = "124 196 203 ";
const char* MAGENTA = "203 108 198 ";
const char* OCEAN = "79 66 181 ";
const char* VIOLET = "143 0 255 ";

int main(int arg_c, char** arg_v) {
	if (arg_c != 7) return -1;

	char** colours = (char**)malloc(5);

	for (int i = 0; i < 5; i++) {
		if (strcmp(arg_v[i + 2], "red") == 0) {
			colours[i] = (char*)malloc(sizeof(RED));
			colours[i] = RED;
		}
		else if (strcmp(arg_v[i + 2], "green") == 0) {
			colours[i] = (char*)malloc(sizeof(GREEN));
			colours[i] = GREEN;
		}
		else if (strcmp(arg_v[i + 2], "blue") == 0) {
			colours[i] = (char*)malloc(sizeof(BLUE));
			colours[i] = BLUE;
		}
		else if (strcmp(arg_v[i + 2], "yellow") == 0) {
			colours[i] = (char*)malloc(sizeof(YELLOW));
			colours[i] = YELLOW;
		}
		else if (strcmp(arg_v[i + 2], "orange") == 0) {
			colours[i] = (char*)malloc(sizeof(ORANGE));
			colours[i] = ORANGE;
		}
		else if (strcmp(arg_v[i + 2], "cyan") == 0) {
			colours[i] = (char*)malloc(sizeof(CYAN));
			colours[i] = CYAN;
		}
		else if (strcmp(arg_v[i + 2], "magenta") == 0) {
			colours[i] = (char*)malloc(sizeof(MAGENTA));
			colours[i] = MAGENTA;
		}
		else if (strcmp(arg_v[i + 2], "ocean") == 0) {
			colours[i] = (char*)malloc(sizeof(OCEAN));
			colours[i] = OCEAN;
		}
		else if (strcmp(arg_v[i + 2], "violet") == 0) {
			colours[i] = (char*)malloc(sizeof(VIOLET));
			colours[i] = VIOLET;
		}
		else {
			printf("Colour %d is invalid\n", i + 1);
			return -1;
		}
	}

	// Create image
	int img = open(arg_v[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(img, "P3\n1000 1000\n255\n", 17);

	int pid;

	for (int i = 0; i < 10; i++) {
		if ((pid = fork) == 0) {
			for (int j = 0; j < 100; j++) {
				for (int k = 0; k < 1000; k++) {
					if (k < 500) {
						write(img, colours[1], sizeof(colours[1]));
					}
					else {
						write(img, colours[2], sizeof(colours[2]));
					}
				}
			}
		}
	}

	close(img);

	return 0;
}
