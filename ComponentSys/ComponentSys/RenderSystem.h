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

	void CheckGameObjects();
private:

	std::vector<GameObject*> drawableGameObjectVector;
	sf::RenderWindow* window;
	void DrawGameObjectVector();
	void DrawGameObject(GameObject* gameObject);


};

