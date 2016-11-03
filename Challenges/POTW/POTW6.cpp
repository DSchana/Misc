#include <cstdio>

using namespace std;

int main() {
    int n, smith = -1;
    scanf("%d", &n);

    int progs[n];
    for (int i = 0; i < n; i++) {
        progs[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int userIn;
        scanf("%d", &userIn);

        if (progs[userIn] == 0) {
            progs[userIn]++;
        }
        else if (smith == -1) {
            smith = userIn;
        }
    }

    printf("%d\n", smith);

    return 0;
}