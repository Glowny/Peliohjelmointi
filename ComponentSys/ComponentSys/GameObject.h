#pragma once
#include <vector>
#include "Component.h"
class GameObject
{
public:
	GameObject();
	~GameObject();
	std::vector<Component> components;
};

