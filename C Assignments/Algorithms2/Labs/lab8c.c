/* 	
 * Title:	Lab8c.c
 * Author:	Dilpreet Chana
 * Description:	This program modifies the top secret information of employees
*/

#include <stdio.h>
#include <string.h>

struct employee {
     char firstname[40];
     char lastname[40];
     int id;
     float GPA;
};
typedef struct employee Employee;


void InputEmpRecord(Employee *EmpList);
void PrintEmpList(const Employee *EmpList);
void SaveEmpList(const Employee *EmpList, const char *FileName);

int main() {
     Employee EmpList[3];
     InputEmpRecord(EmpList);
     PrintEmpList(EmpList);
     SaveEmpList(EmpList, "employeeDA.dat");

     return 0;
}

/* 
 * Description: Takes the inputted records of employees 
 * Parameters:	Emplist is assumed to contain the records of 3 employees
 * Returns:	void 
**/
void InputEmpRecord(Employee *EmpList){
	char first[40] = {"\0"};
	char last[40] = {"\0"};;
	int id = 0;
	float GPA = 0;

	for (int i = 0; i < 3; i++){
		printf("Enter the employee #%d's information (ID First_Name Last_Name GPA): ", i + 1);
		scanf("%d %s %s %f", &id, first, last, &GPA);

		EmpList[i].id = id;
		strcpy(EmpList[i].firstname, first);
		strcpy(EmpList[i].lastname, last);
		EmpList[i].GPA = GPA; 
	}
}

/* 
 * Description: Prints the contents of the employee list
 * Parameters:	Emplist is assumed to contain the records of 3 employees
 * Returns:	void
**/
void PrintEmpList(const Employee *EmpList){
	for (int i = 0; i < 3; i++){
		printf("%d %s %s %.1f\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
	}
}

/* 
 * Description: Saves the contents of the employee list to a direct access file
 * Parameters:	Emplist is assumed to contain the records of 3 employees
 * Returns:	void
**/
void SaveEmpList(const Employee *EmpList, const char *FileName){
	FILE *out;

	out = fopen(FileName, "w");
	fwrite(EmpList, sizeof(Employee), 3,  out);

	fclose(out);
}
