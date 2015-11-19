// CCC96S3.cpp
// Pattern Generator

#include <iostream>
#include <algorithm>

using namespace std;

void BitPatterns(int n, int k, int n_length, string soFar)
{
	if (n == 0)
	{
		size_t count1 = count(soFar.begin(), soFar.end(), '1');
		if (count1 == k && soFar.size() == n_length)
			cout << soFar << endl;
	}
	else
	{
		BitPatterns(n - 1, k, n_length, soFar + "1");
		BitPatterns(n - 1, k, n_length, soFar + "0");
	}
}

int main(int argc, char const *argv[])
{
	int s;
	cin >> s;
	int n[s], k[s];

	for (int i = 0; i < s; i++)
	{
		cin >> n[i] >> k[i];
	}

	for (int i = 0; i < s; i++)
	{
		cout << "The bit patterns are" << endl;

		BitPatterns(n[i], k[i], n[i], "");
		cout << endl;
	}

	return 0;
}