#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

typedef struct colour {
	int r;
	int g;
	int b;
} Colour;

void stoc(char* str, Colour* col);

int main(int arg_c, char** arg_v) {
	if (arg_c != 7 && arg_c != 9) exit(1);

	Colour colours[5];
	for (int i = 0; i < 5; i++) {
		stoc(arg_v[i + 2], colours + i);
	}

	int len = 1000;
	int children = 10;

	if (arg_c == 9) {
		len = atoi(arg_v[7]) - atoi(arg_v[7]) % 4;
		children = atoi(arg_v[8]) + atoi(arg_v[8]) % 2;
	}

	int pid, stat, v, ed_len;
	char* name = arg_v[1];
	char c[3];
	strcat(name, ".ppm");

	// New image
	int n_img = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);

	if (arg_c == 7) {
		char* tmp_s = "P6\n1000 1000\n255\n";
		write(n_img, tmp_s, strlen(tmp_s));
		ed_len = strlen(tmp_s);
	}
	else {
		write(n_img, "P6\n", 3);
		write(n_img, arg_v[7], strlen(arg_v[7]));
		write(n_img, " ", 1);
		write(n_img, arg_v[7], strlen(arg_v[7]));
		write(n_img, "\n255\n", 5);
		ed_len = 2 * strlen(arg_v[7] + 9);
	}

	close(n_img);

	return 0;
}

void stoc(char* str, Colour* col) {
	if (strcmp(str, "red") == 0) {
		*col = (Colour) { .r = 255, .g = 42, .b = 26 };
	}
	else if (strcmp(str, "green") == 0) {
		*col = (Colour) { .r = 87, .g = 154, .b = 113 };
	}
	else if (strcmp(str, "blue") == 0) {
		*col = (Colour) { .r = 24, .g = 154, .b = 202 };
	}
	else if (strcmp(str, "orange") == 0) {
		*col = (Colour) { .r = 204, .g = 142, .b = 36 };
	}
	else if (strcmp(str, "cyan") == 0) {
		*col = (Colour) { .r = 124, .g = 196, .b = 203 };
	}
	else if (strcmp(str, "magenta") == 0) {
		*col = (Colour) { .r = 203, .g = 108, .b = 198 };
	}
	else if (strcmp(str, "ocean") == 0) {
		*col = (Colour) { .r = 203, .g = 108, .b = 198 };
	}
	else if (strcmp(str, "violet") == 0) {
		*col = (Colour) { .r = 143, .g = 0, .b = 225 };
	}
	else if (strcmp(str, "yellow") == 0) {
		*col = (Colour) { .r = 103, .g = 171, .b = 37 };
	}
	else {
		*col = (Colou) { .r = 0, .g = 0, .b = 0 };
	}
}
