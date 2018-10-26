#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int pid;
	int processNum = 1;
	
	for (int i = 1;i < 3;i++){
		if (processNum == 1){
			if ((pid = fork()) < 0){
				exit(1);
			}
		}
		if (pid == 0){
			if (processNum == 1){
				processNum = i + 1;
			}
			if (processNum == 2 || processNum == 3){
				for (int j = 1;j < 3;j++){
					if (processNum == 2 || processNum == 3){
						if ((pid = fork()) < 0){
							exit(1);
						}
					}
					if (pid == 0){
						if (processNum == 2 || processNum == 3){
							if (j == 1){
								processNum = i + j + 2;
							}
							else if (j == 2){
								processNum = i + j + 3;
							}
						}
					}
				}
			}
		}
	}
	sleep(atoi(argv[processNum]));
	printf("process %d terminated pid=%d\n", processNum,getpid());

	return 0;
}
