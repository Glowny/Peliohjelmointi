#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	location.x = 0;
	location.y = 0;
	speed.x = 0;
	speed.y = 0;

}

TransformComponent::TransformComponent(sf::Vector2f location)
{
	this->location = location;
	speed.x = 0;
	speed.y = 0;
}


TransformComponent::~TransformComponent()
{
}
