#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "GameObject.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "RenderComponentFactory.h"
#include <vector>
int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Window");

	std::vector<GameObject> gameObjects;

	RenderComponentFactory renderCFactory;
	RenderComponent* Rcomponent1 = renderCFactory.create("welcome.jpg", sf::Vector2f(100, 600));
	RenderComponent* Rcomponent2 = renderCFactory.create("welcome.jpg", sf::Vector2f(150, 200));

	GameObject gameObject;
	gameObject.addComponent(new TransformComponent(sf::Vector2f(100, 200)));
	gameObject.addComponent(Rcomponent1);
	gameObject.getComponent<TransformComponent>()->location = sf::Vector2f(0, 0);

	GameObject gameObject2;
	gameObject2.addComponent(new TransformComponent(sf::Vector2f(200, 200)));
	gameObject2.addComponent(Rcomponent2);
	gameObject2.getComponent<TransformComponent>()->location = sf::Vector2f(400, 400);

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
			Drawable draw = gameObjects[i].getDrawable();
			window.draw(draw.vertexArray, &draw.texture);
		}

		window.display();
	}
}

