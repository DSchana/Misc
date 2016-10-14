#include <time.h>
#include <stdio.h>

int main(void) {
	time_t my_time;
	struct tm *ptr_time;
	char buffer[15];

	time(&my_time);  // get the current time
	ptr_time = localtime(&my_time);  // point to a tm structure
	// Convert time to a spacific string and ouput

	strftime(buffer, 15, "%m/%d/%Y", ptr_time);
	printf("Today is %s. \nHave a nice day!\n", buffer);

	return 0;
}
