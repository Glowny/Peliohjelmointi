#include "ScriptSystem.h"

#include <iostream>
int ScriptSystem::SetEntitySpeed(lua_State* luaState)
{
	lua_Number speedY = lua_tonumber(luaState, -1);
	lua_Number speedX = lua_tonumber(luaState, -2);
	lua_Number index = lua_tonumber(luaState, -3);

	if (gameObjectVector.size() > index >= 0)
		gameObjects[index]->getComponent<TransformComponent>()->speed = sf::Vector2f(speedX, speedY);
	else
		std::cout << "Out of vector bounds" << std::endl;
	return 3;
}

ScriptSystem::ScriptSystem(std::string scriptFilename)
{
	luaState = luaL_newstate();
	int result = luaL_loadfile(luaState, "fishScript.lua");
	if (result != LUA_OK)
	{
		const char* message = lua_tostring(luaState, -1);
		std::cout << message << std::endl;
	}
	assert(result == LUA_OK);
}


ScriptSystem::~ScriptSystem()
{
}
