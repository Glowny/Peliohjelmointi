#include "RenderSystem.h"


RenderSystem::RenderSystem(sf::RenderWindow* window)
{
	this->window = window;
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::DrawMultipleGameObjects(std::vector<GameObject> gameObjects)
{
	for (int i = 0; i < gameObjects.size(); i++)
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

	Drawable drawable = renderComponent->getDrawable();
	window->draw(drawable.vertexArray, &drawable.texture);

}