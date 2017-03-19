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

void loadCourses();
void append(CourseInfo *c_info, CourseInfo n_info);
void displayCourses(CourseInfo *c_info);
void addCourseInfo(CourseInfo *c_info, int id, char *name, char *code, char *term);
void searchCourseInfoId(CourseInfo *c_info, int id);
void searchCourseInfoName(CourseInfo *c_info, char *name);

int main() {
	CourseInfo *infos;

	loadCourses(infos);
	displayCourses(infos);

	return 0;
}

void loadCourses(CourseInfo *info) {
	CourseInfo c_info[0];
	char buff[255];
	FILE *fp = fopen("courses.txt", "r");

	while (fscanf(fp, "%s", buff) != EOF) {
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

		append(c_info, n_course);
	}

	fclose(fp);

	info = c_info;
}

void displayCourses(CourseInfo *c_info) {
	int size = sizeof(c_info) / sizeof(CourseInfo);

	printf("%-2s %-50s %-12s %-6s\n", "ID", "Name", "Code", "Term");

	for (int i = 0; i < size; i++) {
		printf("%-2d %-50s %-12s %-6s\n", (c_info + i)->id,
						  (c_info + i)->name,
						  (c_info + i)->code,
						  (c_info + i)->term);
	}
}

void addCourseInfo(CourseInfo *c_info, int id, char *name, char *code, char *term) {
	CourseInfo to_add;
	to_add.id = id;
	strcpy(to_add.name, name);
	strcpy(to_add.code, code);
	strcpy(to_add.term, term);

	append(c_info, to_add);

	FILE *fp = fopen("courses.txt", "w+");

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

void searchCourseInfoId(CourseInfo *c_info, int id) {
	int size = sizeof(c_info) / sizeof(CourseInfo);

	for (int i = 0; i < size; i++) {
		if ((c_info + i)->id == id) {
			printf("%2d %50s %12s %6s\n", (c_info + i)->id,
						      (c_info + i)->name,
						      (c_info + i)->code,
						      (c_info + i)->term);

			return;
		}
	}
}

void searchCourseInfoName(CourseInfo *c_info, char *name) {
	int size = sizeof(c_info) / sizeof(CourseInfo);

        for (int i = 0; i < size; i++) {
                if (strcmp((c_info + i)->name, name) == 0) {
                        printf("%2d %50s %12s %6s\n", (c_info + i)->id,
                                                      (c_info + i)->name,
                                                      (c_info + i)->code,
                                                      (c_info + i)->term);

                        return;
                }   
        }
}

void append(CourseInfo *c_info, CourseInfo n_info) {
	int curr_size = sizeof(c_info) / sizeof(CourseInfo);
	CourseInfo r_info[curr_size + 1];

	for (int i = 0; i < curr_size; i++) {
		*(r_info + i) = *(c_info + i);
	}
	n_info.id = curr_size + 1;
	*(r_info + curr_size) = n_info;

	c_info = r_info;
}
