#include <cstdio>
#include <vector>

using namespace std;

vector<int>::iterator getBeg(vector<int> &v) {
	return v.begin();
}

int main() {
	vector<int> v;
	v.push_back(3);

	getBeg(v);

	return 0;
}
