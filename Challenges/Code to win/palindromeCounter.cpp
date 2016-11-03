#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int countPalindromes(string s) {
	int count = 0;
	for (int i = 1; i <= s.size(); i++) {  // i is lengths of substrings
		for (int j = 0; j <= s.size() - i; j++) {  // Place in string to start
			string toCheck = s.substr(j, i);
			//cout << toCheck << endl;
			bool pal = true;

			// Check for palindrome
			for (int k = 0; k < toCheck.size() / 2; k++) {
				if (toCheck[k] != toCheck[toCheck.size() - k - 1]) {
					pal = false;
				}
			}

			if (pal) {
				count++;
			}
		}
	}

	return count;
}

int main() {
	string test;
	getline(cin, test);

	printf("%d\n", countPalindromes(test));

	return 0;
}
