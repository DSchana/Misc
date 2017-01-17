// a2_4integers.c
// Dilpreet S. Chana
// Find the largest and smallest number
// in a set of 4 integers

#include <stdio.h>

int main() {
    int nums[4];  // nums holds the 4 numbers
    for (int i = 0; i < 4; i++) {
        scanf("%d", &nums[i]);
    }

    // Set the largest and smallest to any
    // arbitrary value in the nums array
    int large = nums[0];
    int small = nums[0];

    // Iterate through array and check if the value
    // is larger or smaller than the current values
    for (int i = 0; i < 4; i++) {
        if (nums[i] > large) large = nums[i];
        else if (nums[i] < small) small = nums[i];
    }

    printf("Largest: %d \nSmallest: %d\n", large, small);

    return 0;
}