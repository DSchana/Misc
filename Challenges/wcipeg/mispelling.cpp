#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	string words[num];

	for (int i = 0; i < num; i++) {
		int rem;
		string word;

		cin >> rem >> word;

		word.erase(word.begin() + rem - 1);

		words[i] = word;
	}

	for (int i = 0; i < num; i++) {
		printf("%d %s\n", i + 1, words[i].c_str());
	}

	return 0;
}
