#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
class RenderSystem
{
public:
	RenderSystem(sf::RenderWindow* window);
	void DrawMultipleGameObjects(std::vector<GameObject> gameObjects);
	void DrawGameObject(GameObject gameObject);
	~RenderSystem();
private:
	sf::RenderWindow* window;
};

