#pragma once
class Component
{
public:
	virtual void update() = 0;
	Component();
	virtual ~Component();
	virtual int getID();
private:
	int id;
};

