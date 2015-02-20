#import <iostream>
using namespace std;

int f[201];
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    else if (f[n] != -1) {
        return f[n];
    }
    else {
        f[n] = fib(n-1)+fib(n-2);
        return f[n];
    }
}

int main() {
    for (int i = 0; i<51; i++) {
        f[i] = -1;
    }
    cout << fib(50) << endl;

    return 0;
}
