#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	location.x = 1;
	location.y = 1;
	id = 2;
}

TransformComponent::TransformComponent(sf::Vector2f location)
{
	this->location = location;
	id = 2;
}


TransformComponent::~TransformComponent()
{
}
void TransformComponent::update()
{
	location.x = location.x + 1.0f;
}