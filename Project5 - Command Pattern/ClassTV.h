#pragma once //Á×§K­«½Æ©w¸q
#include"ClassCommand.h"
#include<iostream>
using namespace std;

class TV
{
private:
	bool bState;

public:
	TV()
	{
		bState = false;
	}
	void On(){bState = true;}
	void Off(){bState = false;}
	bool getState(){return bState;}
};

class TVOnCommand:public Command
{
private:
	TV* tv;

public:
	TVOnCommand(TV* tv)
	{
		this->tv = tv;
	}

	virtual void execute(){tv->On();}
};

class TVOffCommand:public Command
{
private:
	TV* tv;

public:
	TVOffCommand(TV* tv)
	{
		this->tv = tv;
	}

	virtual void undo(){tv->Off();}
};