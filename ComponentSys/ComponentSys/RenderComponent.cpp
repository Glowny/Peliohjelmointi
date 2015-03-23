#include "RenderComponent.h"
// Sisältää tekstuurin ja piirtoon tarvittavat.

RenderComponent::RenderComponent(Drawable drawable)
{
	id = 1;
	this->drawable = drawable;
}
RenderComponent::RenderComponent()
{
	id = 1;
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::update()
{

}
void RenderComponent::setDrawable(Drawable drawable)
{
	this->drawable = drawable;
}

void RenderComponent::setTexture(sf::Texture texture)
{
	drawable.texture = texture;
}
void RenderComponent:: setVertexData(sf::VertexArray vertexArray)
{
	drawable.vertexArray = vertexArray;
}

Drawable RenderComponent::getDrawable()
{
	return drawable;
}