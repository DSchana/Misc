#include <stdio.h>

int main() {
	int n, d1, d2;  // Full number, first digit, second sigit
	int isTeen = 0;  // Flag true if the number is from 13-19

	printf("Enter a 2 digit number: ");
	scanf("%d", &n);

	printf("You entered the number ");

	// Edge cases 10, 11, 12, 13, 15, 18. Does not fit the later pattern
	switch(n) {
	case 10:
		printf("ten\n");
		return 0;
	case 11:
		printf("eleven\n");
		return 0;
	case 12:
		printf("twelve\n");
		return 0;
	case 13:
		printf("thirteen\n");
		return 0;
	case 15:
		printf("fifteen\n");
		return 0;
	case 18:
		printf("eighteen\n");
		return 0;
	default:
		break;
	}

	// Obtain the separate digits
	d2 = n % 10;
	d1 = (n - d2) / 10;

	// Print first digit name
	switch(d1) {
	case 1:
		isTeen = 1;
		break;
	case 2:
		printf("twenty");
		break;
	case 3:
                printf("thirty");
		break;
	case 4:
                printf("forty");
		break;
	case 5:
                printf("fifty");
		break;
	case 6:
                printf("sixty");
		break;
	case 7:
                printf("seventy");
		break;
	case 8:
                printf("eighty");
		break;
	case 9:
                printf("ninety");
		break;
	default:
		break;
	}

	// seprator dash only printed if the number requires it
	if (isTeen == 0 && d2 != 0) {
		printf("-");
	}

	// Second digit name
	switch(d2) {
	case 1:
		printf("one");
		break;
        case 2:
                printf("two");
		break;
        case 3:
                printf("three");
		break;
        case 4:
                printf("four");
		break;
        case 5:
                printf("five");
		break;
        case 6:
                printf("six");
		break;
        case 7:
                printf("seven");
		break;
        case 8:
                printf("eight");
		break;
        case 9:
                printf("nine");
		break;
        default:
                break;
        }

	if (isTeen == 1) {
		printf("teen");
	}

	printf("\n");

	return 0;
}
