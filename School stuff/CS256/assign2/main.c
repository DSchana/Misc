/*
 * Title:	main.c
 * Author:	Dilpreet S. Chana
 * Description:	Program creates a binary ppm file with the given name.
 *		The image is of four colour squares in each corner and
 *		one square in the centre rotated 45 degrees. the colours
 *		are passed in as consol parameters.
 *		Optinal usage:
 *		The size of the image can be passed in along with number
 *		of children. By default the size is 1000 x 1000 and 10
 *		children are used to write the image.
**/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

typedef struct colour{
	int r;
	int g;
	int b;
} Colour;

void stoc(char* str, Colour* col);  // Convert string to colour

int main(int arg_c, char* arg_v[]) {
	if (arg_c != 7 && arg_c != 9) exit(1);

	Colour colours[5];
	for (int i = 0; i < 5; i++) {
		stoc(arg_v[i + 2], colours + i);
	}

	int len = 1000, children = 10;

	// When variable len/len , children entered 
	if (arg_c == 9) {
		len = atoi(arg_v[7]) - atoi(arg_v[7]) % 4;
		children = atoi(arg_v[8]) + atoi(arg_v[8]) % 2;
	}

	int pid, status, v, ed_len;
	char* name = arg_v[1];
	char c[3];
	strcat(name, ".ppm");

	// Writing header to image
	int new_img = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);

	if (arg_c == 7) {
		char* tmp_s = "P6\n1000 1000\n255\n";
		write(new_img, tmp_s, strlen(tmp_s));
		ed_len = strlen(tmp_s);
	}
	else {
		write(new_img, "P6\n", 3);
		write(new_img, arg_v[7], strlen(arg_v[7]));
		write(new_img, " ", 1);
		write(new_img, arg_v[7], strlen(arg_v[7]));
		write(new_img, "\n255\n", 5);
		ed_len = 2 * strlen(arg_v[7]) + 9;
	}

	close(new_img);

	// Loop number of children to write rows
	for (int i = 0; i < children; i++) {
		if ((pid = fork()) == 0) {
			int new_img = open(name, O_WRONLY, 0777);
			lseek(new_img, (len / children) * len * 3 * i + ed_len, SEEK_SET);

			// Write one row to the image
			for (int j = 0; j < (len / children); j++) {

				if (i < children / 2) {
					*c = colours[1].r;
					*(c + 1) = colours[1].g;
					*(c + 2) = colours[1].b;

					for (int k = 0; k < (len / 2); k++) {
						write(new_img, c, 3);
					}

					*c = colours[2].r;
					*(c + 1) = colours[2].g;
					*(c + 2) = colours[2].b;
					for (int k = 0; k < (len / 2); k++) {
						write(new_img, c, 3);
					}

					if ((v = 2 * (i * (len / children) + j - (len / 4))) >= 0) {
						*c = colours[0].r;
						*(c + 1) = colours[0].g;
						*(c + 2) = colours[0].b;
						lseek(new_img, (-1 * len * 3) + (len / 2) * 3 - v * 3 / 2, SEEK_CUR);

						for (int l = 0; l < v; l++) {
							write(new_img, c, 3);
						}

						lseek(new_img, len/2*3 - v*3/2, SEEK_CUR);
					}
				}
				else {
					*c = colours[3].r;
					*(c + 1) = colours[3].g;
					*(c + 2) = colours[3].b;

					for(int k = 0; k < len / 2; k++) {
						write(new_img, c, 3);
					}

					*c = colours[4].r;
					*(c + 1) = colours[4].g;
					*(c + 2) = colours[4].b;

					for (int k = 0; k < len / 2; k++) {
						write(new_img, c, 3);
					}

					if ((v = 2 * (3 * len / 4 - i * (len / children) - j)) > 0) {
						*c = colours[0].r;
						*(c + 1) = colours[0].g;
						*(c + 2) = colours[0].b;
						lseek(new_img, (-1 * len * 3) + len / 2 * 3 - v * 3 / 2, SEEK_CUR);

						for(int l=0;l<v;l++){
							write(new_img, c, 3);
						}

						lseek(new_img, len / 2 * 3 - v * 3 / 2, SEEK_CUR);
					}
				}
			}
			close(new_img);
			exit(0);
		}
		wait(&status);
	}

	return 0;
}

/*
 * Description:	Convert string to colour
 * Parameters:	Pointer to char array: String to convert
 *		Pointer to Colour:     Location to store converted colour
 * Returns:	void
**/
void stoc(char* str, Colour* col){
	Colour tmp;

	if(strcmp(str,"red") == 0){
		tmp = (Colour) { .r = 255, .g = 42, .b = 26 };
	}
	else if(strcmp(str,"green") == 0){
		tmp = (Colour) { .r = 87, .g = 154, .b = 113 };
	}
	else if(strcmp(str,"blue") == 0){
		tmp = (Colour) { .r = 24, .g = 154, .b = 202 };
	}
	else if(strcmp(str,"orange") == 0){
		tmp = (Colour) { .r = 204, .g = 142, .b = 36 };
	}
	else if(strcmp(str,"cyan") == 0){
		tmp = (Colour) { .r = 124, .g = 196, .b = 203 };
	}
	else if(strcmp(str,"magenta") == 0){
		tmp = (Colour) { .r = 203, .g = 108, .b = 198 };
	}
	else if(strcmp(str,"ocean") == 0){
		tmp = (Colour) { .r = 203, .g = 108, .b = 198 };
	}
	else if(strcmp(str,"violet") == 0){
		tmp = (Colour) { .r = 143, .g = 0, .b = 255 };
	}
	else if(strcmp(str,"yellow") == 0){
		tmp = (Colour) { .r = 203, .g = 171, .b = 37 };
	}
	else {
		tmp = (Colour) { .r = 0, .g = 0, .b = 0 };
	}

	*col = tmp;
}
