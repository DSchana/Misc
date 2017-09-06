#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Mouse.hpp>

int main() {
	// Setup
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Vector2i mouse_pos;

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

		mouse_pos = sf::Mouse::getPosition(window);
		sprite.setPosition((sf::Vector2f)mouse_pos);

		printf("%d, %d\n", mouse_pos.x, mouse_pos.y);

		window.clear();
		window.draw(shape);
		window.draw(sprite);
		window.display();
	}

	return 0;
}
