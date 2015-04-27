#include "System.h"


System::System()
{
}


System::~System()
{
}

void System::SetGameObjectVector(std::vector<GameObject*> gameObjectVector)
{
	this->gameObjectVector = gameObjectVector;
}