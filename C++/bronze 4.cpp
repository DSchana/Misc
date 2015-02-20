// bronze 4.cpp

#include <iostream>
using namespace std;

int main() {
    int r;
    int ans = 1;

    cin >> r;

    for (int m=-r; m<r; m++) {
        for (int n=-r; n<r; n++) {
            if (n*n + m*m <= r*r) {
                ans++;
            }
        }
    }

    if (r == 0) {
        cout << 1;
    } else {
        cout << ans+1;
    }
}
