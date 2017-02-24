#include <stdio.h>

int main() {
	int a = 7 ;
	int *aPtr ;
	aPtr = &a ;
	printf( "%p\n", &a );	   // Print address of a
	printf( "%p\n", aPtr );	   // Print address of a
	printf( "%p\n", &aPtr );   // Print address of aPtr
	printf( "%d\n", a );	   // Print value of a
	printf( "%d\n", *aPtr );   // Print value of a
	printf( "%p\n", *&aPtr );  // Print address of a
	printf( "%p\n", &*aPtr );  // Print address of a
	printf( "%d\n", *&a );	   // Print value of a
	//printf( "%d", &*a );	   // Error: a is not a pointer

	return 0;
}