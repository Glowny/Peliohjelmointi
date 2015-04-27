#include "RenderSystem.h"
#include <iostream>

RenderSystem::RenderSystem(sf::RenderWindow* window)
{
	this->window = window;
}
RenderSystem::RenderSystem()
{
	window = nullptr;
}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::Update()
{

}

void RenderSystem::CreateWindow(sf::Vector2i screenSize, std::string screenName)
{
	if (window != nullptr)
	{
		std::cout << "Window already created, replacing with a new window" << std::endl;
		window->close();
	}
	window = new sf::RenderWindow(sf::VideoMode(screenSize.x, screenSize.y), screenName);
}

void RenderSystem::SetWindow(sf::RenderWindow* window)
{
	if (this->window != nullptr)
	{
		std::cout << "Window already set, setting window anyway" << std::endl;
	}
	this->window = window; 
}

void RenderSystem::Draw()
{
	if (this->window == nullptr)
	{
		std::cout << "Window is not set, cannot draw!" << std::endl;
		return;
	}
	window->clear(sf::Color::Black);
	DrawGameObjectVector();
	window->display();
}

bool RenderSystem::PollEvent()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
			return false;
		}
	}
	return true;
}



void RenderSystem::DrawGameObjectVector()
{
	for (unsigned int i = 0; i < drawableGameObjectVector.size(); i++)
	{
		DrawGameObject(drawableGameObjectVector[i]);
	}
}

void RenderSystem::DrawGameObject(GameObject* gameObject)
{
	Drawable drawable = gameObject->GetFinalDrawable();
	window->draw(drawable.vertexArray, &drawable.texture);
}

// Check will the updated gameobject be drawn.
void RenderSystem::CheckGameObjects()
{
	drawableGameObjectVector.clear();

	for (int i = 0; i < gameObjectVector.size(); i++)
	{
		bool drawable = true;

		RenderComponent* renderComponent;
		renderComponent = gameObjectVector[i]->getComponent<RenderComponent>();

		if (renderComponent == nullptr)
			drawable = false;

		TransformComponent* transformComponent;
		transformComponent = gameObjectVector[i]->getComponent<TransformComponent>();

		if (transformComponent == nullptr)
			drawable = false;

		if (drawable)
			drawableGameObjectVector.push_back(gameObjectVector[i]);
	}

}

