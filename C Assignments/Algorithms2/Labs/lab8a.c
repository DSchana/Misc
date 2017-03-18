#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee {
	char first_name[40];
	char last_name[40];
	int id;
	int gpa;
};
typedef struct employee Employee;

void inputEmpRecord(Employee *emp_list);
void printEmpList(const Employee *emp_list);
void saveEmpList(const Employee *emp_list, const char *file_name);

int main() {
	Employee emp_list[3];

	FILE *fp = fopen("employee.dat", "r+");

	for (int i = 0; i < 3; i++) {
		char str[255];
		fscanf(fp, "%s", str);

		Employee tmp_emp;

		char *tok = strtok(str, " ");
		for (int j = 0; tok != NULL; j++) {
			if (j == 0) {
				tmp_emp.id = atoi(tok);
			}

			tok = strtok(NULL, " ");
		}

		emp_list[i] = tmp_emp;
	}

	//inputEmpRecord(emp_list);
	printEmpList(emp_list);
	//saveEmpList(emp_list, "employee.dat");

	return 0;
}

void printEmpList(const Employee *emp_list) {
	for (int i = 0; i < 3; i++) {
		printf("%d. %s %s: %d", (emp_list + i)->id,
					(emp_list + i)->first_name,
					(emp_list + i)->last_name,
					(emp_list + i)->gpa);
	}
}
