#include "RenderComponent.h"
// Sis‰lt‰‰ tekstuurin ja piirtoon tarvittavat.

RenderComponent::RenderComponent()
{
	setVertexData();
	setTexture();
	setTextureData();
	id = 1;
}


RenderComponent::~RenderComponent()
{
}

void RenderComponent::update()
{

}

void RenderComponent::setTexture()
{
	Drawable.texture.loadFromFile("welcome.jpg");
}
void RenderComponent::setTexture(sf::Texture texture)
{
	Drawable.texture = texture;
}

void RenderComponent::setVertexData()
{
	Drawable.vertexArray = sf::VertexArray(sf::Triangles, 4);
	Drawable.vertexArray[0].position = sf::Vector2f(10, 10);
	Drawable.vertexArray[1].position = sf::Vector2f(100, 10);
	Drawable.vertexArray[2].position = sf::Vector2f(100, 100);
	Drawable.vertexArray[2].position = sf::Vector2f(10, 100);

	Drawable.vertexArray[0].color = sf::Color::Red;
	Drawable.vertexArray[1].color = sf::Color::Blue;
	Drawable.vertexArray[2].color = sf::Color::Green;
	Drawable.vertexArray[3].color = sf::Color::Magenta;
}

void RenderComponent::setTextureData()
{
	Drawable.vertexArray[0].texCoords = sf::Vector2f(0, 0);
	Drawable.vertexArray[1].texCoords = sf::Vector2f(25, 0);
	Drawable.vertexArray[2].texCoords = sf::Vector2f(25, 50);
	Drawable.vertexArray[3].texCoords = sf::Vector2f(0, 50);
}

drawable RenderComponent::getDrawable()
{
	return Drawable;
}