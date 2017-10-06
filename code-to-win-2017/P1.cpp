#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector <int> stringSimilarity(vector <string> inputs) {
	vector<int> counts;

	for (int i = 0; i < inputs.size(); i++) {
		int count = 0;
		vector<string> subs;

		for (int j = 0; j < inputs[i].size(); j++) {
			subs.push_back(inputs[i].substr(j));
		}

		for (int j = 0; j < subs.size(); j++) {
			for (int k = 0; k < subs[j].size(); k++) {
				string curr = subs[j].substr(0, subs[j].size() - k);
				if (inputs[i].find(curr) == 0) {
					count += curr.size();
					break;
				}
			}
		}
		printf("%d\n", count);
		counts.push_back(count);
	}

	return counts;
}

int main() {
	vector<string> inps;
	inps.push_back("ababaa");
	stringSimilarity(inps);

	return 0;
}
