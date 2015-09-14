#include "Screen.h"

namespace scrn {


Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
	
}

bool Screen::init() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	// Create window
	m_window = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	// Create render
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	// Create texture
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	// Allocate memory to hold all pixel info
	// Uint32 type variables hold 32 bits of memory, which is 1 pixel (8 * 4)
	Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];  // buffer is an allocation of memory

	// Write info to buffer
	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));  // fill buffer with white black

	// set pixel colours
	for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		buffer[i] = 0xFFFFFFFF;
	}

	return true;
}

bool Screen::processEvents() {
	SDL_Event event;
	// Event loop
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	Uint32 colour = 0;

	colour += red;
	colour <<= 8;

	colour += green;
	colour <<= 8;

	colour += blue;
	colour <<= 8;

	colour += 0xFF;

	cout << colour << endl;

	/*
	stringstream ss;
	ss << hex << colour;
	string hex_colour(ss.str());

	cout << hex_colour << endl;
	*/

	m_buffer[(y * SCREEN_WIDTH) + x] = colour;
}

void Screen::update() {
	// Display the texture to the screen
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::quit() {
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

// Get methods
int Screen::getWidth() {
	return SCREEN_WIDTH;
}

int Screen::getHeight() {
	return SCREEN_HEIGHT;
}


}
