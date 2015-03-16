#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::addComponent(Component* component)
{
	components.push_back(component);
}

void GameObject::update()
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->update();
	}
}
drawable GameObject::getDrawable()
{
	drawable tempDraw;
	for (unsigned int i = 0; i < components.size(); i++)
	{
		int id = components[i]->getID();
		if (id == 1)
		{
			RenderComponent* render = dynamic_cast<RenderComponent*>(components[i]);
			assert(render != NULL);
			tempDraw = render->getDrawable();
		}
	}
	sf::Vector2f location = getLocation();
	tempDraw.vertexArray = move(tempDraw.vertexArray, location);
	return tempDraw;
	
}
sf::Vector2f GameObject::getLocation()
{
	sf::Vector2f tempLoc;
	for (unsigned int i = 0; i < components.size(); i++)
	{
		int id = components[i]->getID();
		if (id == 2)
		{
			TransformComponent* transform = dynamic_cast<TransformComponent*>(components[i]);
			assert(transform != NULL);
			tempLoc = transform->location;
			break;
		}
	}
	return tempLoc;
}

sf::VertexArray GameObject::move(sf::VertexArray draw, sf::Vector2f move)
{
	for (unsigned int i = 0; i < draw.getVertexCount(); i++)
	{
		draw[i].position = draw[i].position + move;

	}
	return draw;
}