// main.cpp

#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	int halt;
	cout << "Test" << endl;
	cin >> halt;
	
	SDL_Quit();

	return 0;
}