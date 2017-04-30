/* 	
 * Title:	Lab8d.c
 * Author:	Dilpreet Chana
 * Description: This program  sorts the top secret information of employees by their GPA from highest to lowest
**/

#include <stdio.h>

struct employee {
     char firstname[40];
     char lastname[40];
     int id;
     float GPA;
};
typedef struct employee Employee;

int main(void){
	FILE *fptr;
	Employee temp = {.firstname = "", .lastname = "", .id = 0, .GPA = 0};
	Employee curr = {.firstname = "", .lastname = "", .id = 0, .GPA = 0};
	Employee comp = {.firstname = "", .lastname = "", .id = 0, .GPA = 0};

	fptr = fopen("employeeDA.dat", "r+");
	
	printf("\nPre-Sorting\n");
	for (int i = 0; i < 3; i++){
		fseek(fptr, i*sizeof(Employee), SEEK_SET);
		fread(&temp, sizeof(Employee), 1, fptr);
		printf("%d %s %s %.1f\n", temp.id, temp.firstname, temp.lastname, temp.GPA);
	}

	fseek(fptr, 0, SEEK_SET);

    // Bubble Sort
    for (int i = 0; i < 3; i++) {
     	for (int j = 0; j < 2; j++){
     		fseek(fptr, j*sizeof(Employee), SEEK_SET);
     		fread(&curr, sizeof(Employee), 1 ,fptr);
     		fread(&comp, sizeof(Employee), 1 ,fptr);
     		if (curr.GPA < comp.GPA){
     			fseek(fptr, j*sizeof(Employee), SEEK_SET);
     			fwrite(&comp, sizeof(Employee), 1, fptr);
     			fwrite(&curr, sizeof(Employee), 1, fptr);
     		}
     	}
    }

    printf("\nPost-Sorting\n");
    fseek(fptr, SEEK_SET, 0);
    for (int i = 0; i < 3; i++){
		fseek(fptr, i*sizeof(Employee), SEEK_SET);
		fread(&temp, sizeof(Employee), 1, fptr);
		printf("%d %s %s %.1f\n", temp.id, temp.firstname, temp.lastname, temp.GPA);
	}

	fclose(fptr);

     return 0;
}
