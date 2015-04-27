#include "RenderComponent.h"
// Sisältää tekstuurin ja piirtoon tarvittavat.

RenderComponent::RenderComponent(Drawable drawable)
{
	this->drawable = drawable;
}
RenderComponent::RenderComponent()
{

}

RenderComponent::~RenderComponent()
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