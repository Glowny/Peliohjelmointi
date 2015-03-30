#include "SystemManager.h"

SystemManager::SystemManager()
{
}

SystemManager::~SystemManager()
{
}
void SystemManager::AddSystem(System* system)
{
	_systems.insert(std::make_pair(&typeid(*system), system));
}

void SystemManager::Update()
{
	for (auto it = _systems.begin(); it != _systems.end(); ++it)
	{
		it->second->Update();
	}
}

void SystemManager::SetGameObjectPointerVector(std::vector<GameObject*> gameObjectPointerVector)
{
	this->gameObjectPointerVector = gameObjectPointerVector;
}