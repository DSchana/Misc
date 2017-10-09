#include <cstdio>

using namespace std;

int main() {
	int n;

	printf("Choose an option from 1-5: ");
	scanf("%d", &n);

	switch(n) {
	case 1:
		printf("You chose 1\n");
		break;
	case 2:
		printf("You chose 2\n");
		break;
	case 3:
		printf("You chose 3\n");
		break;
	case 4:
		printf("You chose 4\n");
		break;
	case 5:
		printf("You chose 5\n");
		break;
	default:
		printf("Invalid choice\n");
		break;
	}

	return 0;
}
