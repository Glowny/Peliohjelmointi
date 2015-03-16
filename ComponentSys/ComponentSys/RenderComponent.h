#pragma once
#include "Component.h"
#include "drawable.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
class RenderComponent :public Component
{
public:
	RenderComponent();
	~RenderComponent();
	void update();
	void setTexture(sf::Texture texture);
	void setTexture();
	drawable getDrawable();
	int getID()
	{
		return id;
	}
private:
	int id;
	drawable Drawable;
	void setVertexData();
	void setTextureData();
};

