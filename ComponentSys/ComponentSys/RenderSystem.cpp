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
		std::cout << "Window already created, creating new window anyway" << std::endl;
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
	DrawGameObjectPointerVector();
	window->display();
}
// This does not belong here
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




void RenderSystem::SetGameObjectPointerVector(std::vector<GameObject*> gameObjectVector)
{
	this->gameObjectVector = gameObjectVector;
}

void RenderSystem::DrawGameObjectPointerVector()
{
	for (unsigned int i = 0; i < gameObjectVector.size(); i++)
	{
		DrawGameObjectPointer(gameObjectVector[i]);
	}
}

void RenderSystem::DrawGameObjectPointer(GameObject* gameObject)
{
	RenderComponent* renderComponent;
	renderComponent = gameObject->getComponent<RenderComponent>();

	if (renderComponent == nullptr)
		return;

	TransformComponent* transformComponent;
	transformComponent = gameObject->getComponent<TransformComponent>();

	if (transformComponent == nullptr)
		return;

	Drawable drawable = gameObject->GetFinalDrawable();
	window->draw(drawable.vertexArray, &drawable.texture);
}

// Outdated
void RenderSystem::DrawMultipleGameObjects(std::vector<GameObject> gameObjects)
{
	for (unsigned int i = 0; i < gameObjects.size(); i++)
	{
		DrawGameObject(gameObjects[i]);
	}
}

void RenderSystem::DrawGameObject(GameObject gameObject)
{
	RenderComponent* renderComponent;
	renderComponent = gameObject.getComponent<RenderComponent>();

	if (renderComponent == nullptr)
		return;

	TransformComponent* transformComponent;
	transformComponent = gameObject.getComponent<TransformComponent>();

	if (transformComponent == nullptr)
		return;

	Drawable drawable = gameObject.GetFinalDrawable();
	window->draw(drawable.vertexArray, &drawable.texture);
}