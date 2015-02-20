// silver 3.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
	string userIn;
	int n;
	int k = 1;

	getline(cin, userIn);

	for (int i = 0; i < userIn.find(" "); i++) {
		n += atoi(userIn[i].c_str());
	}

	cout << n;
}
