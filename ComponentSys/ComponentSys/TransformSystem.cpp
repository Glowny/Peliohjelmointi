#include "TransformSystem.h"


TransformSystem::TransformSystem()
{
}


TransformSystem::~TransformSystem()
{
}

void TransformSystem::Update()
{
	for (int i = 0; i < transformCompVector.size(); i++)
	{
		UpdateTransformLocation(transformCompVector[i]);
	}
}
void TransformSystem::CheckGameObjects()
{
	transformCompVector.clear();

	for (int i = 0; i < gameObjectVector.size(); i++)
	{
		TransformComponent* transformComponent;
		transformComponent = gameObjectVector[i]->getComponent<TransformComponent>();

		if (transformComponent != nullptr)
			transformCompVector.push_back(gameObjectVector[i]->getComponent<TransformComponent>());
	}
}


void TransformSystem::UpdateTransformLocation(TransformComponent* transform)
{
	transform->location += transform->speed;
}