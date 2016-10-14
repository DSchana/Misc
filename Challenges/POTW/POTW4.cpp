#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isRolling(string op, string person, string target, map<string, vector<string> > fs) {
	if (person == target) {
		return true;
	}
	for (int i = 0; i < fs[person].size(); i++) {
		return isRolling(op, fs[person][i], target, fs);
	}

	return false;
}

int main() {
	int N, M;
	vector<string> persons1, persons2, targets1, targets2;
	map<string, vector<string> > friendships;

	string userIn;
	getline(cin, userIn);
	stringstream(userIn) >> N;

	for (int i = 0; i < N; i++) {
		// Clear cin buffer
		//cin.clear();

		//string userIn;
		getline(cin, userIn);
		persons1.push_back(userIn.substr(0, userIn.find(" ")));
		persons2.push_back(userIn.substr(userIn.find(" ") + 1));
	}

	for (int i = 0; i < N; i++) {
		friendships[persons1[i]].push_back(persons2[i]);
		friendships[persons2[i]].push_back(persons1[i]);
	}

	//cin.clear();
	getline(cin, userIn);
	stringstream(userIn) >> M;
	for (int i = 0; i < M; i++) {
		getline(cin, userIn);
		targets1.push_back(userIn.substr(0, userIn.find(" ")));
		targets2.push_back(userIn.substr(userIn.find(" ") + 1));
	}

	for (int i = 0; i < M; i++) {
		// TODO: Change the method to not be recursive. If you person reaches its self, break and all that sh*t
		if (isRolling(targets1[i], targets1[i], targets2[i], friendships)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}
