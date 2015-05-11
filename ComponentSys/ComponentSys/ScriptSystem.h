#pragma once
#include "System.h"
#include <string>
#include <lua/lua.hpp>>
class ScriptSystem : public System
{
public:
	ScriptSystem(std::string sysScriptFilename);
	~ScriptSystem();
	static int SetEntitySpeed(lua_State* luaState);
private:
	lua_State* luaState;

};

