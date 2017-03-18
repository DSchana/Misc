#include <stdio.h>

struct CourseInfo {
	int id;
	char name[50];
	char code[12];
	char term[6];
};

CourseInfo *loadCourses();
void displayCourses();
void addCourseInfo(int id, char name[], char code[], char term[]);
void searchCourseInfo(int id);
void searchCourseInfo(char name[]);

int main() {
	CourseInfo *infos;

	return 0;
}

CourseInfo *loadCourses() {
	FILE *fp = fopen("courses.txt", "w+");
}
