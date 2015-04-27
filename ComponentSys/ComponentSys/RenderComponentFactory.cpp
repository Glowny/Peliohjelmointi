#include "RenderComponentFactory.h"


RenderComponentFactory::RenderComponentFactory()
{
}


RenderComponentFactory::~RenderComponentFactory()
{
}

RenderComponent* RenderComponentFactory::create(std::string fileName, sf::Vector2f size)
{
	sf::Texture texture;
	texture.loadFromFile(fileName);

	sf::VertexArray vertexArray =
		createVertexData(size);
	vertexArray = 
		createTextureData(vertexArray, texture.getSize());

	Drawable drawable;
	drawable.texture = texture;
	drawable.vertexArray = vertexArray;

	RenderComponent* renderComponent = new RenderComponent;
	renderComponent->setDrawable(drawable);

	return renderComponent;
}

RenderComponent* RenderComponentFactory::create(sf::Vector2f size)
{
	sf::VertexArray vertexArray =
		createVertexData(size);

	Drawable drawable;
	drawable.vertexArray = vertexArray;

	RenderComponent* renderComponent = new RenderComponent;
	renderComponent->setDrawable(drawable);

	return renderComponent;
}

sf::VertexArray RenderComponentFactory::createVertexData(sf::Vector2f size)
{
	sf::VertexArray vertexArray(sf::Quads, 4);
	vertexArray[0].position = sf::Vector2f(0, 0);
	vertexArray[1].position = sf::Vector2f(size.x, 0);
	vertexArray[2].position = sf::Vector2f(size.x, size.y);
	vertexArray[3].position = sf::Vector2f(0, size.y);

	return vertexArray;
}

sf::VertexArray RenderComponentFactory::createTextureData(sf::VertexArray vertexArray, sf::Vector2u size)
{
	vertexArray[0].texCoords = sf::Vector2f(0, 0);
	vertexArray[1].texCoords = sf::Vector2f(size.x, 0);
	vertexArray[2].texCoords = sf::Vector2f(size.x, size.y);
	vertexArray[3].texCoords = sf::Vector2f(0, size.y);

	return vertexArray;
}