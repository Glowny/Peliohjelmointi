#pragma once
class Component
{
public:
	virtual void update() = 0;
	Component();
	~Component();
	virtual int getID();
private:
	int id;
};

