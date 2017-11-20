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

	int dim = 1000;
	int num_kids = 10;

	if (arg_c == 9) {i
		dim = atoi(arg_v[7]);
		num_kids = atoi(arg_v[8]);
	}

	int pid, stat;
	int* pids;
	char*** outs;
	pids = (int*)malloc(num_kids);
	char* name = arg_v[1];
	strcat(name, ".ppm");

	// Make kids
	for (int i = 0; i < num_kids; i++) {
		if ((pids[i] = fork()) == 0) {
			break;
		}
	}

	// New file
	int n_img = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);

	char* tmp[10];
	itoa(dim, tmp, 10);

	write(n_img, "P6\n", 3);
	write(n_img, tmp, strlen(tmp));
	write(n_img, " ", 1);
	write(n_img, tmp, strlen(tmp));
	write(n_img, "\n255\n", 5);

	close(n_img);

	for (int i = 0; i < num_kids; i++) {
		if (pids[i] == 0) {

		}
	}

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
