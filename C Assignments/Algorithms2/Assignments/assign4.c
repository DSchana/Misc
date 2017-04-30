/*
 * Title:	assign4.c
 * Author:	Dilpreet S. Chana
 * Description:	Simple course manager with file access abilities.
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct courseInfo {
	int id;
	char name[50];
	char code[12];
	char term[6];
};
typedef struct courseInfo CourseInfo; 

void getSize(int *size);								// Return size of array
void loadCourses(CourseInfo *info, int *size);						// Load courses from file
void append(CourseInfo *c_info, CourseInfo n_info, int *size);				// Add to array
void displayCourses(CourseInfo *c_info, int *size);					// Print all courses
void addCourseInfo(CourseInfo *c_info, char *name, char *code, char *term, int *size);  // Add new course
void searchCourseInfoId(CourseInfo *c_info, int id, int *size);				// Search by id
void searchCourseInfoName(CourseInfo *c_info, char *name, int *size);			// Search by name

int main() {
	int size = 0;

	getSize(&size);

	CourseInfo infos[size];

	loadCourses(infos, &size);
	displayCourses(infos, &size);

	searchCourseInfoId(infos, 2, &size);
	searchCourseInfoName(infos, "PROGRAMMING", &size);

	addCourseInfo(infos, "ART", "1234-273-56", "F6969", &size);

	return 0;
}

/*
 * Description:	Get length of file
 * Parameters:	Pointer to size var
 * Returns:	void
**/
void getSize(int *size) {
	char buff[255];
	FILE *fp = fopen("courses.txt", "r");

	while (fscanf(fp, "%s", buff) != EOF) {
		(*size)++;
	}
}

/*
 * Description:	Load from file
 * Parameters:	Array to store in
 *		Size of array
 * Returns:	void
**/
void loadCourses(CourseInfo *c_info, int *size) {
	char buff[255];

	FILE *fp = fopen("courses.txt", "r");

	for (int i = 0; fscanf(fp, "%s", buff) != EOF; i++) {
		CourseInfo n_course;

		strcpy(n_course.name, "");
		strcpy(n_course.code, "");
		strcpy(n_course.term, "");

		int counter = 0;
		char *tok = strtok(buff, ",");

		while (tok != NULL) {
			if (counter == 0) {
				for (int i = 0; *(tok + i) != '\0'; *(tok + i) = toupper(*(tok + i)), i++);
				strcpy(n_course.name, tok);
			}
			else if (counter == 1 || counter == 2) {
				strcat(n_course.code, tok);
			}
			else if (counter == 3 || counter == 4) {
				strcat(n_course.code, "-");
				strcat(n_course.code, tok);
			}
			else if (counter == 5 || counter == 6) {
				strcat(n_course.term, tok);
			}

			tok = strtok(NULL, ",");
			counter++;
		}

		n_course.id = i;

		*(c_info + i) = n_course;
	}

	fclose(fp);
}

/*
 * Description:	Print all courses
 * Parameters:	Array of courses to show
 *		Size of array
 * Returns:	void
**/
void displayCourses(CourseInfo *c_info, int *size) {
	printf("%-2s %-50s %-12s %-6s\n", "ID", "Name", "Code", "Term");

	for (int i = 0; i < *size; i++) {
		printf("%-2d %-50s %-12s %-6s\n", (c_info + i)->id + 1,
						  (c_info + i)->name,
						  (c_info + i)->code,
						  (c_info + i)->term);
	}
}

/*
 * Description:	Add new course into file
 * Parameters:	array of courses
 *		data of new course
 *		size of array c_info
 * Returns:	void
**/
void addCourseInfo(CourseInfo *c_info, char *name, char *code, char *term, int *size) {
	for (int i = 0; i < *size; i++) {
		if (strcmp((c_info + i)->code, code)) {
			return;
		}
	}

	FILE *fp = fopen("courses.txt", "w");

	for (int i = 0; i < 7; i++) {
		if (i == 0) {
			fputs(name, fp);
		}
		else if (i == 1) {
			fputc(*(code + 0), fp);
			fputc(*(code + 1), fp);
		}
		else if (i == 2) {
			fputc(*(code + 2), fp);
			fputc(*(code + 3), fp);
		}
		else if (i == 3) {
			fputc(*(code + 4), fp);
			fputc(*(code + 5), fp);
			fputc(*(code + 6), fp);
		}
		else if (i == 4) {
			fputc(*(code + 7), fp);
			fputc(*(code + 8), fp);
		}
			else if (i == 5) {
			fputc(*(term + 0), fp);
		}
		else if (i == 6) {
			for (int j = 1; j <= 4; i++) {
				fputc(*(term + j), fp);
			}
		}

		if (i != 6) {
			fputc(',', fp);
		}
	}
}

/*
 * Description:	Print course with specified id
 * Parameters:	Array of courses
 *		id to search for
 *		size of array
 * Returns:	void
**/
void searchCourseInfoId(CourseInfo *c_info, int id, int *size) {
	for (int i = 0; i < *size; i++) {
		if ((c_info + i)->id == id) {
			printf("%-2d %-50s %-12s %-6s\n", (c_info + i)->id + 1,
						      	  (c_info + i)->name,
						      	  (c_info + i)->code,
						      	  (c_info + i)->term);

			return;
		}
	}
}

/*
 * Description:	Print course with specified name
 * Parameters:	Array of courses
 *		name to search for
 *		size of array
 * Returns:	void
**/
void searchCourseInfoName(CourseInfo *c_info, char *name, int *size) {
        for (int i = 0; i < *size; i++) {
                if (strcmp((c_info + i)->name, name) == 0) {
                        printf("%-2d %-50s %-12s %-6s\n", (c_info + i)->id + 1,
                                                      (c_info + i)->name,
                                                      (c_info + i)->code,
                                                      (c_info + i)->term);

                        return;
                }   
        }
}

/*
 * Description: Add new element to array
 * Parameters:	array to add to
 *		new element
 *		current size of array
 * Returns:	void
**/
void append(CourseInfo *c_info, CourseInfo n_info, int *size) {
	CourseInfo r_info[*size + 1];

	for (int i = 0; i < *size; i++) {
		*(r_info + i) = *(c_info + i);
	}
	n_info.id = *size + 1;
	*(r_info + *size) = n_info;

	c_info = r_info;

	(*size)++;
}
