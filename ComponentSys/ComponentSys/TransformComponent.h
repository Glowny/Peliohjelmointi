#pragma once
#include "Component.h"
#include <SFML\System.hpp>
class TransformComponent :public Component
{
public:
	TransformComponent();
	TransformComponent(sf::Vector2f location);
	~TransformComponent();
	void update();
	sf::Vector2f location;
	int getID()
	{
		return id;
	}
private:
	int id;
};

