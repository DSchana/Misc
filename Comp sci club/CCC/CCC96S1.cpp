// CCC96S1.cpp

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, sum;
	cin >> n;
	int nums[n];

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 1; j < nums[i] / 2 + 1; j++)
		{
			if (nums[i] % j == 0)
				sum += j;
		}
		if (sum == nums[i])
			cout << nums[i] << " is a perfect number." << endl;
		else if (sum < nums[i])
			cout << nums[i] << " is a deficient number." << endl;
		else
			cout << nums[i] << " is an abundant number." << endl;
	}

	return 0;
}