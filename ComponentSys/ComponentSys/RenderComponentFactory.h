#pragma once
#include "RenderComponent.h"
#include <string>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "drawable.h"

class RenderComponentFactory
{
public:
	RenderComponentFactory();
	RenderComponent* create(std::string fileName, sf::Vector2f size);
	RenderComponent* create(sf::Vector2f size);
	~RenderComponentFactory();
private:
	sf::VertexArray createVertexData(sf::Vector2f size);
	sf::VertexArray createTextureData(sf::VertexArray vertexArray, sf::Vector2u size);
};

