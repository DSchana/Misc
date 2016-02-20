#include <stdio.h>
#include <string>

using namespace std;

int main() {
	int n, t, gen=0;
	string conf;
	scanf("%d %d", &n, &t);
	scanf("%s", &conf);

	for (int i=0; i<=t; i++) {
		string tmp = "";
		if (&conf[1].compare("1")==0 && &conf[n-1].compare("1")!=0 || &conf[1].compare("1")!=0 && &conf[n-1].compare("1")==0) {
			&tmp += "1";
		}
		else {
			&tmp += "0";
		}

		for (int j=0; j<n-1; j++) {
			if (&conf[i-1].compare("1")==0 && &conf[i+1].compare("1")!=0 || &conf[i-1].compare("1")!=0 && &conf[i+1].compare("1")==0) {
				&tmp += "1";
			}
			else {
				&tmp += "0";
			}
		}

		if (&conf[0].compare("1")==0 && &conf[n-2].compare("1")!=0 || &conf[0].compare("1")!=0 && &conf[n-2].compare("1")==0) {
			&tmp += "1";
		}
		else {
			&tmp += "0";
		}
		&conf=&tmp;
	}

	printf("%s", &conf);

	return 0;
}