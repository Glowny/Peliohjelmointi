#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "GameObject.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "RenderComponentFactory.h"
#include "RenderSystem.h"
#include <vector>
int main()
{
	RenderSystem renderSystem;

	renderSystem.CreateWindow(sf::Vector2i(900, 900), "renderSystemWindow");

	std::vector<GameObject*> gameObjects;

	RenderComponentFactory renderCFactory;
	RenderComponent* Rcomponent1 = renderCFactory.create("welcome.jpg", sf::Vector2f(300, 600));
	RenderComponent* Rcomponent2 = renderCFactory.create("welcome.jpg", sf::Vector2f(150, 200));

	GameObject gameObject;
	gameObject.addComponent(new TransformComponent(sf::Vector2f(100, 200)));
	gameObject.addComponent(Rcomponent1);
	gameObject.getComponent<TransformComponent>()->location = sf::Vector2f(0, 0);

	GameObject gameObject2;
	gameObject2.addComponent(new TransformComponent(sf::Vector2f(200, 200)));
	gameObject2.addComponent(Rcomponent2);
	gameObject2.getComponent<TransformComponent>()->location = sf::Vector2f(400, 400);

	GameObject gameObject3;
	gameObject3.addComponent(new TransformComponent(sf::Vector2f(400, 400)));
	gameObject3.getComponent<TransformComponent>()->location = sf::Vector2f(204, 630);

	gameObjects.push_back(&gameObject);
	gameObjects.push_back(&gameObject2);

	renderSystem.SetGameObjectPointerVector(gameObjects);
	
	bool windowIsOpen = true;
	while (windowIsOpen)
	{
		windowIsOpen = renderSystem.PollEvent();
		
		for (unsigned int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->update();
		}

		renderSystem.Draw();
	}
}

