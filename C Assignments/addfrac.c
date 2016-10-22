// addfrac.c
// Dilpreet S. Chana
// Add 2 fractions in the form n1/d1+n2/d2

#include <stdio.h>

int main() {
    // Declare and get input for variables
    int n1, d1, n2, d2, nf, df;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &n1, &d1, &n2, &d2);

    // Calculate new numerator and denominator
    // from given fractions
    nf = n1 * d2 + n2 * d1;
    df = d1 * d2;
    
    printf("The sum is %d/%d\n", nf, df);

    return 0;
}