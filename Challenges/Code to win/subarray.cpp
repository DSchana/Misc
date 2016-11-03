#include <cstdio>
#include <vector>

using namespace std;

long count(vector < int > numbers, int k) {
	long tot = 0;
	for (int i = 1; i <= numbers.size(); i++) {  // i is length
                for (int j = 0; j <= numbers.size() - i; j++) {  // Place to start
			vector<int> toCheck(numbers.begin() + j, numbers.begin() + j + i);
			long prod = 1;
			for (int z = 0; z < toCheck.size(); z++) {
				//printf("%d ", toCheck[z]);
				prod *= toCheck[z];
			}
			//printf("%lu\n", prod);

			if (prod < k) {
				tot++;
			}
		}
	}
	return tot;
}

int main() {
	int n, k;
	scanf("%d", &n);
	vector<int> invec;
	for (int i = 0; i < n; i++) {
		int userIn;
		scanf("%d", &userIn);
		invec.push_back(userIn);
	}
	scanf("%d", &k);

	printf("%lu\n", count(invec, k));

	return 0;
}
