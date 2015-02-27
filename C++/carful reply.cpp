#include <iostream>

using namespace std;

int main() {
	int t;
	string text;
	cin >> t;
	getline(cin, text);

	for (int i = 0; i < t; i++) {
		int heart = 0;
		getline(cin, text);

		for (int j = 0; j < text.length()-1; j++) {
			if (text[j] == '<') {
				if (text[j+1] == '3') {
					heart++;
				}
			}
		}
		for (int j = 0; j <= heart; j++) {
			cout << "<3 ";
		}
		cout << endl;
	}
	return 0;
}