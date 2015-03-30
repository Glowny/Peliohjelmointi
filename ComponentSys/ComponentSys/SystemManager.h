#pragma once
#include "GameObject.h"
#include "RenderSystem.h"
#include "System.h"

class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	
	void SetGameObjectPointerVector(std::vector<GameObject*> gameObjectPointerVector);
	void AddSystem(System* system);
	template<typename T>
	T* getSystem();
	void Update();
private:
	std::vector<GameObject*> gameObjectPointerVector;
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
