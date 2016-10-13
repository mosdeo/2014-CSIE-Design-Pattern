#pragma once //Á×§K­«½Æ©w¸q
#include"ClassCommand.h"
#include<iostream>
using namespace std;

class Light
{
private:
	bool bState;

public:
	Light()
	{
		bState = false;
	}
	void On(){bState = true;}
	void Off(){bState = false;}
	bool getState(){return bState;}
};

class LightOnCommand:public Command
{
private:
	Light* light;

public:
	LightOnCommand(Light* light)
	{
		this->light = light;
	}

	virtual void execute(){light->On();}
};

class LightOffCommand:public Command
{
private:
	Light* light;

public:
	LightOffCommand(Light* light)
	{
		this->light = light;
	}

	virtual void undo(){light->Off();}
};