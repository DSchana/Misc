#pragma once

#include <SDL.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

namespace scrn {

class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

	Screen();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool init();
	bool processEvents();
	void quit();

	int getWidth();
	int getHeight();
};

}  // namespace scrn