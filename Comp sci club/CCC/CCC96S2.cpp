/// CCC96S2.cpp

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, num_check, sub_num;
	bool isDivisible;
	stringstream ss;

	cin >> n;

	string nums[n+1], num, unit_num;

	for (int i = 0; i <= n; i++)
		getline(cin, nums[i]);

	for (int i = 1; i <= n; i++)
	{
		num = nums[i];
		num_check = 0;

		ss.clear();
		ss.str("");
		ss.str(num);
		ss >> num_check;

		isDivisible = false;
		while (num_check >= 100)
		{
			// unit_num = num[sizeof(num) / sizeof(string) - 1];
			unit_num = num[num.size() - 1];
			num = num.substr(0, num.size()-1);
			num_check /= 10;

			ss.clear();
			ss.str("");
			ss.str(unit_num);
			ss >> sub_num;

			num_check -= sub_num;

   			ss.clear();
   			ss.str("");
   			ss << num_check;
   			num = ss.str();

			cout << num_check << endl;
		}
		if (num_check == 11)
		{
			isDivisible = true;
		}

		if (isDivisible)
			cout << "The number " << nums[i] << " is divisible by 11." << endl;
		else
			cout << "The number " << nums[i] << " is not divisible by 11." << endl << endl;
	}

	return 0;
}