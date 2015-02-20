// CCCJ1.cpp

#include <iostream>

using namespace std;

int main() {
    int a1,a2,a3;
    cin >> a1;
    cin >> a2;
    cin >> a3;

    if (a1+a2+a3 == 180) {
        if (a1 == a2 && a2 == a3) {
            cout << "Equilateral";
        } else if (a1 == a2 || a1 == a3 || a2 == a3) {
            cout << "Isosceles";
        } else {
            cout << "Scalene";
        }
    } else {
        cout << "Error";
    }
}
