// a2_octal.c
// Dilpreet S. Chana
// Convert an integer from decimal to octal

#include <stdio.h>

int main() {
    int n;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    // Iterate through integer until it is in oct
    int oct = 0, counter = 1;  // Counter dictates which place the new number is going
    while (n > 0) {
        oct += (n % 8) * counter;
        n /= 8;
        counter *= 10;
    }

    printf("In octal, your number is: 0%d\n", oct);

    return 0;
}