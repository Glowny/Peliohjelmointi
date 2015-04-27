#pragma once
#include "GameObject.h"
#include "RenderSystem.h"
#include "System.h"

class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	
	void SetGameObjectVector(std::vector<GameObject*> gameObjectVector);
	void AddSystem(System* system);
	template<typename T>
	T* getSystem();
	void Update();
	bool CheckChanges();
private:
	std::vector<GameObject*> gameObjectVector;
	using SystemMap = std::unordered_map <const std::type_info*, System* >;
	SystemMap _systems;
};

template<typename T>
T* SystemManager::getSystem()
{
	SystemMap::const_iterator position = _systems.find(&typeid(T));

	if (position == _components.end())
	{
		return nullptr;
	}
	else
	{
		return static_cast<T*>(position->second);
	}
}
