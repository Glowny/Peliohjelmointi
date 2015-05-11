#pragma once
#include "Component.h"
#include <string>
#include <lua/lua.hpp>
class ScriptComponent : public Component
{
public:
	ScriptComponent(std::string scriptFunctionName);
	~ScriptComponent();
private:
	std::string functionName;
};

