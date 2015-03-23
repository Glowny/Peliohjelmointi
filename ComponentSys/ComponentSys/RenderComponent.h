#pragma once
#include "Component.h"
#include "drawable.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
class RenderComponent :public Component
{
public:
	RenderComponent(Drawable drawable);
	RenderComponent();
	~RenderComponent();
	void update();

	void setTexture(sf::Texture texture);
	void setVertexData(sf::VertexArray vertexArray);
	void setDrawable(Drawable drawable);
	Drawable getDrawable();
	int getID()
	{
		return id;
	}
private:
	int id;
	Drawable drawable;

};

