#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

//void GameObject::addComponent(Component* component)
//{
//	components.push_back(component);
//}

void GameObject::addComponent(Component* component)
{
	_components.insert(std::make_pair(&typeid(*component), component));
}

void GameObject::update()
{
	for (auto it = _components.begin(); it != _components.end(); ++it)
	{
		it->second->update();
	}
}
Drawable GameObject::GetFinalDrawable()
{
	
	Drawable tempDraw = 
		getComponent<RenderComponent>()->getDrawable();

	sf::Vector2f location = getLocation();
	tempDraw.vertexArray = move(tempDraw.vertexArray, location);
	return tempDraw;
	
}
sf::Vector2f GameObject::getLocation()
{
	sf::Vector2f tempLoc =
		getComponent<TransformComponent>()->location;

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