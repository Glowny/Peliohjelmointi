#pragma once
#include <vector>
#include "GameObject.h"
class System
{
public:
	virtual void Update() = 0;
	virtual void CheckGameObjects() = 0;
	void SetGameObjectVector(std::vector<GameObject*> gameObjectVector);
	System();
	virtual ~System();
protected:
	std::vector<GameObject*> gameObjectVector;
};

