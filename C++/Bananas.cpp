#import <iostream>
#import <string>

using namespace std;

int strcmp ( const char * str1, const char * str2 );

bool aWord(string word) {
    char bCheck = word[0];
    char sCheck = word[-1];
    string b = "B";
    string s = "S";
    if (word == "A") {
        return true;
    }
    else if (word.length() > 2 && strcmp(bCheck, b) == 0 && strcmp(sCheck, s) == 0) {
        return mWord(word[1:-1]);
    }
    else {
        return false;
    }
}

bool mWord(string word) {
    if (aWord(word)) {
        return true;
    }
    else {
        bool monkey = false;
        for (int i = 1; i<word.length()-1; i++) {
            if (word[i] == "N") {
                if (aWord(word[0:i]) && mWord(word[i+1:word.length()+1])) {
                    monkey = true
                }
            }
        }
        return monkey
    }
}


int main() {
    string word;
    while (true) {
        cin >> word;
        if (word.compare("X") == 0) {
            break;
        }
        if (mWord(word)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
