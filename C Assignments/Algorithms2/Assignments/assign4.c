#include <stdio.h>

struct CourseInfo {
	int id;
	char name[50];
	char code[12] = "";
	char term[6] = "";
};

CourseInfo *loadCourses();
CourseInfo *append(CourseInfo *c_info, CourseInfo n_info);
void displayCourses();
void addCourseInfo(int id, char name[], char code[], char term[]);
void searchCourseInfo(int id);
void searchCourseInfo(char name[]);

int main() {
	CourseInfo *infos = loadCourses();

	return 0;
}

CourseInfo *loadCourses() {
	CourseInfo (*c_info)[0];
	char buff[255];
	FILE *fp = fopen("courses.txt", "w+");

	while (fscanf(fp, "%s", buff) != EOF) {
		CourseInfo n_course;
		int counter = 0;
		char *tok = strtok(buff, ",");

		while (tok != NULL) {
			if (counter == 0) {
				n_course.name = tok;
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

		c_info = append(c_info, n_course);
	}

	return c_info;
}

CourseInfo *append(CourseInfo *c_info, CourseInfo n_info) {
	int curr_size = sizeof(c_info) / sizeof(CourseInfo);
	CourseInfo (*r_info)[curr_size + 1];

	for (int i = 0; i < curr_size; i++) {
		*(r_info + i) = *(c_info + i);
	}
	*(r_info + curr_size) = n_info;

	return r_info;
}