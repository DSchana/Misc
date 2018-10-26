/*
 * Title:	merge.c
 * Author:	Dilpreet S. Chana
 * Description:	Place small image into top right corner of
 *		larger image. Only accepts ppm file types.
 * Usage:	./merge image_1 image_2 new_image
**/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readHeader(int fd, char type[3], char width[5], char height[5]);  // Read header of image file

int main(int arg_c, char *arg_v[]) {
	if (arg_c != 4) return -1;

	// Oprn images
	int img_1 = open(arg_v[1], O_RDONLY, 0777);
	int img_2 = open(arg_v[2], O_RDONLY, 0777);

	char type_1[3], width_1[5], height_1[5], type_2[3], width_2[5], height_2[5];
	int w_1, h_1, w_2, h_2;

	int size_len_1 = readHeader(img_1, type_1, width_1, height_1);
	int size_len_2 = readHeader(img_2, type_2, width_2, height_2);

	w_1 = atoi(width_1);
	h_1 = atoi(height_1);
	w_2 = atoi(width_2);
	h_2 = atoi(height_2);

	// Error if image formats are invalid
	if (w_1 < w_2 || h_1 < h_2 || strcmp(type_1, "P6") != 0 || strcmp(type_2, "P6") != 0) return -1;

	int n_img = open(arg_v[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);

	// Write new image header
	char tmp[size_len_1];
	lseek(img_1, 0, SEEK_SET);
	read(img_1, tmp, size_len_1);
	write(n_img, tmp, size_len_1);

	// Write image 1 to new image
	for (int i = 0; i < h_1; i++) {
		char buff[w_1 * 3];
		read(img_1, buff, w_1 * 3);
		write(n_img, buff, w_1 * 3);
	}

	lseek(n_img, size_len_1, SEEK_SET);
	lseek(img_2, size_len_2, SEEK_SET);

	// Write image 2 to new image
	for (int i = 0; i < h_2; i++) {
		lseek(n_img, (w_1 * 3) - (w_2 * 3), SEEK_CUR);
		char buff[w_1 * 3];
		read(img_2, buff, w_2 * 3);
		write(n_img, buff, w_2 * 3);
	}

	close(img_1);
	close(img_2);
	close(n_img);

	return 0;
}

/*
 * Description:	Read header of ppm image file to obtain image dimensions.
 * Parameters:	Integer - fd: Image file id
 *		Character array - type: Image type
 *		Character array - width: Image width
 *		Character array - height: Image height
 * Returns:	Integer: Location of file where image data begins.
 *			 Where the header ends.
**/
int readHeader(int fd, char type[3], char width[5], char height[5]) {
	int count = 7;
	read(fd, type, 2);
	lseek(fd, 1, SEEK_CUR);

	for (int i = 0; i < 5; i++) {
		count++;
		read(fd, width + i, 1);

		if (width[i] == ' ') {
			width[i] = '\0';
			break;
		}
	}

	for (int i = 0; i < 5; i++) {
		count++;
		read(fd, height + i, 1);

		if (height[i] == ' ') {
			height[i] = '\0';
			break;
		}
	}

	lseek(fd, 4, SEEK_SET);

	return count;
}
