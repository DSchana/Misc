#include <iostream>

using namespace std;

int main() {
    int player1, player2;
    player1 = player2 = 100;
    int round;

    cin >> round;

    int dice1,dice2;

    for (int i = 0; i<round; i++) {
        cin >> dice1 >> dice2;
        if (dice1 > dice2) {
            player2 -= dice1;
        }
        if (dice1 < dice2) {
            player1 -= dice2;
        }
    }
    cout << player1 << endl << player2 << endl;
}
