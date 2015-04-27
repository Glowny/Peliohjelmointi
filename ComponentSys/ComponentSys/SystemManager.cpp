#include "SystemManager.h"

SystemManager::SystemManager()
{
}

SystemManager::~SystemManager()
{
}
bool SystemManager::CheckChanges()
{
	bool changes = false;
	for (unsigned i = 0; i < gameObjectVector.size(); i++)
	{
		if (gameObjectVector[i]->componentChanges)
		{
			changes = true;
			gameObjectVector[i]->componentChanges = false;
		}
	}
	return changes;
}

void SystemManager::AddSystem(System* system)
{
	_systems.insert(std::make_pair(&typeid(*system), system));
}

void SystemManager::Update()
{
	bool changes = CheckChanges();
	for (auto it = _systems.begin(); it != _systems.end(); ++it)
	{
		if (changes)
			it->second->CheckGameObjects();
		it->second->Update();
	}
}

void SystemManager::SetGameObjectVector(std::vector<GameObject*> gameObjectVector)
{
	this->gameObjectVector = gameObjectVector;
	for (auto it = _systems.begin(); it != _systems.end(); ++it)
	{
		it->second->SetGameObjectVector(gameObjectVector);
	}
}