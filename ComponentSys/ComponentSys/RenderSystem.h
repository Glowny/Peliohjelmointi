#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "System.h"

class RenderSystem : public System
{
public:
	RenderSystem(sf::RenderWindow* window);
	RenderSystem();
	~RenderSystem();
	void Update();

	void CreateWindow(sf::Vector2i screenSize, std::string screenName);
	void SetWindow(sf::RenderWindow* window);

	void Draw();
	bool PollEvent();

	void SetGameObjectPointerVector(std::vector<GameObject*> gameObjectVector);
	void DrawGameObjectPointerVector();
	
	void DrawGameObjectPointer(GameObject* gameObject);

	//Outdated
	void DrawMultipleGameObjects(std::vector<GameObject> gameObjects);
	void DrawGameObject(GameObject gameObject);
private:
	sf::RenderWindow* window;
	std::vector<GameObject*> gameObjectVector;
};

