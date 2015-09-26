// warmup2.cpp

#include <iostream>
#include <sstream>

using namespace std;

void setXs(string tomb[][], int i, int j) {

}

int main() {
	int r, c, t=0;
	cin >> r >> c;

	string tomb[r][c];

	for (int i=0; i<r; i++) {
		string map_in;
		getline(cin, map_in);

		int split_incr=0;
		stringstream ssin(map_in);
		while (ssin.good() && split_incr < c){
			ssin >> tomb[i][split_incr];
			split_incr++;
		}
	}

	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (tomb[i][j] == ".") {
				t++;
				setXs(tomb, i, j);
			}
		}
	}

	cout << t << endl;

	return 0;
}