// missing link.cpp

#include <iostream>
#include <string>

using namespace std;

bool prime(int num) {
	for (int i = 0; i <= num/2; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	string num, prime_test;
	int pos;
	int possibilities[10];

	getline(cin, num);

	pos = num.find("_");

	if (pos != 0) {
		for (int i = 0; i < 10; i++) {
			prime_test = num;
			prime_test.replace(to_string(i), pos);
		}
	}

	return 0;
}