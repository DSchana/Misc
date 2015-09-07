// practice.cpp

#include <iostream>

using namespace std;

class Alphabet {
private:
	char letter;

public:
	Alphabet() {
		cout << "Letter created" << endl;
		this->letter = 'x';
	}

	~Alphabet() {
		cout << "Letter destroyed" << endl;
	}

	void setLetter(char letter) {
		this->letter = letter;
	}

	void display() {
		cout << letter << endl;
	}
};

int main() {
	Alphabet *pAlphabet = new Alphabet[26];
	pAlphabet[0].setLetter('a');

	for (int i=0; i<26; i++) {
		pAlphabet[i].display();
	}

	delete [] pAlphabet;

	return 0;
}
