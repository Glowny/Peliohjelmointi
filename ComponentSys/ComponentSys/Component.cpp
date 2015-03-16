#include "Component.h"


Component::Component()
{
	id = 0;
}


Component::~Component()
{
}

int Component::getID()
{
	return id;
}