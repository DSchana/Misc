#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int countInString(string toCount, string toFind) {
	int index;
	int count = 0;
	while (true) {
		index = toCount.find(toFind);
		if (index == -1)
			return count;

		count++;
		toCount = toCount.substr(index + toFind.length());
	}
}

int main() {
	int N;
	string query;
	vector<string> docs;

	cin >> N;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < N; i++) {
		string userIn;
		getline(cin, userIn);
		docs.push_back(userIn);
	}
	getline(cin, query);

	// calc idf(T, D)
	int toDivide = 0;
	for (int i = 0; i < N; i++) {
		if (countInString(docs[i], query) > 0) {
			toDivide++;
		}
	}

	if (toDivide == 0) {
		for (int i = 0; i < N; i++) {
			printf("%d %d\n", i + 1, 0);
		}
		return 0;
	}

	float idf = log10(float(N) / float(toDivide));
	//printf("here: %f\n", idf);

	for (int i = 0; i < N; i++) {
		int T = countInString(docs[i], query);
		printf("%d %f\n", i + 1, float(T) * idf);
	}

	return 0;
}
