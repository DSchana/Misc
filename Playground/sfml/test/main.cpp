#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	// Circle
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// Load texture
	sf::Texture texture;
	texture.loadFromFile("TED.png");
	sf::Sprite sprite(texture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.draw(sprite);
		window.display();
	}

	return 0;
}
