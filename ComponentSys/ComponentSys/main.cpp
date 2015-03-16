#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "GameObject.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include <vector>
int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Window");

	std::vector<GameObject> gameObjects;

	GameObject gameObject;
	gameObject.addComponent(new TransformComponent(sf::Vector2f(100, 200)));
	gameObject.addComponent(new RenderComponent());


	GameObject gameObject2;
	gameObject.addComponent(new TransformComponent(sf::Vector2f(400, 200)));
	gameObject.addComponent(new RenderComponent());

	gameObjects.push_back(gameObject);
	gameObjects.push_back(gameObject2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		for (unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i].update();
			drawable draw = gameObjects[i].getDrawable();
			window.draw(draw.vertexArray, &draw.texture);
		}

		window.display();
	}
}

