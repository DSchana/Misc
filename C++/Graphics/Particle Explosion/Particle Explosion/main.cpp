// Title:	main.cpp
// Author:	Dilpreet Chana

#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;
using namespace scrn;

int main(int argc, char* args[]) {
	Screen screen;
	if (!screen.init()) {
		cout << "Error initializing SDL" << endl;
		return 1;
	}

	// Game loop
	while (true) {
		if (!screen.processEvents()) {
			break;
		}

		for (int y = 0; y < screen.getHeight(); y++) {
			for (int x = 0; x < screen.getWidth(); x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		screen.update();  // update the screen
	}

	screen.quit();

	return 0;
}