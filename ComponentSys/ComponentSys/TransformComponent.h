#pragma once
#include "Component.h"
#include <SFML\System.hpp>
class TransformComponent :public Component
{
public:
	TransformComponent();
	TransformComponent(sf::Vector2f location);
	~TransformComponent();

	sf::Vector2f location;
	sf::Vector2f speed;
};

