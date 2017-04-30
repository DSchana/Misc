/*
 * Title:	assign6.c
 * Author:	Dilpreet Chana
 * Created:	April 5, 2017
 * Last Edit:	April 10, 2017
 * Description:	Read the students' data from a file and
 *		sort them in palce by id. Write the sorted
 *		students data to another file for saving
**/

#include <stdio.h>

struct student {
	int id;
	float marks[10];
	float gpa;
};
typedef struct student Student;

int main() {
	// Open files
	FILE *in  = fopen("assign6.dat", "r");
	FILE *out = fopen("assign6out.dat", "w+");
	FILE *sort_out = fopen("assign6res.dat", "w");

	Student curr, comp;  // Student instances for sorting

	size_t tot_bytes = 0;
	size_t bytes_in = 0;

	fseek(in, 0, SEEK_END);
	bytes_in = ftell(in);
	fseek(in, 0, SEEK_SET);

	// Read input file
	while (1) {
		Student tmp;

		for (int i = -1; i < 10; i++) {
			if (i == -1) {
				fscanf(in, "%d", &tmp.id);
				continue;
			}
			else {
				fscanf(in, "%f", &(tmp.marks[i]));
			}
		}

		if (feof(in)) break;

		tmp.gpa = 0;
		for (int i = 0; i < 10; i++) {
			tmp.gpa += tmp.marks[i];
		}
		tmp.gpa /= 10;

		fwrite(&tmp, sizeof(Student), 1, out);
		tot_bytes += sizeof(Student);
	}

	// Sort students from direct access file
	fseek(out, 0, SEEK_SET);

	for (int i = 0; i < tot_bytes / sizeof(Student); i++) {
		for (int j = 0; j < (tot_bytes / sizeof(Student)) - 1; j++) {
			fseek(out, j * sizeof(Student), SEEK_SET);
			fread(&curr, sizeof(Student), 1, out);
			fread(&comp, sizeof(Student), 1, out);

			if (curr.id > comp.id) {
				fseek(out, j * sizeof(Student), SEEK_SET);
				fwrite(&comp, sizeof(Student), 1, out);
				fwrite(&curr, sizeof(Student), 1, out);
			}
		}
	}

	// Write sorted list to file
	fseek(out, 0, SEEK_SET);
	for (int i = 0; i < tot_bytes / sizeof(Student); i++) {
		Student tmp;
		fread(&tmp, sizeof(tmp), 1, out);
		fprintf(sort_out, "%06d: %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f;  Average: %.1f\n", tmp.id,
															tmp.marks[0],
                                                                                                                        tmp.marks[1],
                                                                                                                        tmp.marks[2],
                                                                                                                        tmp.marks[3],
                                                                                                                        tmp.marks[4],
                                                                                                                        tmp.marks[5],
                                                                                                                        tmp.marks[6],
                                                                                                                        tmp.marks[7],
                                                                                                                        tmp.marks[8],
                                                                                                                        tmp.marks[9],
															tmp.gpa);
	}

	fprintf(sort_out, "%zu\n%zu\n", bytes_in, tot_bytes);

	fclose(in);
	fclose(out);
	fclose(sort_out);

	return 0;
}
