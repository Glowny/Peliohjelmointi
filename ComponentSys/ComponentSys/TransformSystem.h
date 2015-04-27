#pragma once
#include "System.h"
#include "TransformComponent.h"
#include "GameObject.h"
class TransformSystem :
	public System
{
public:
	TransformSystem();
	~TransformSystem();
	void Update();
	void CheckGameObjects();
private:
	void UpdateTransformLocation(TransformComponent*);
	std::vector<TransformComponent*> transformCompVector;
};

