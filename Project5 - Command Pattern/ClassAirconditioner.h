#pragma once //Á×§K­«½Æ©w¸q
#include"ClassCommand.h"
#include<iostream>
using namespace std;

class Airconditioner
{
private:
	bool bState;
	string state;

public:
	Airconditioner()
	{
		bState = false;
	}
	void On(){bState = true;}
	void Off(){bState = false;}
	bool getState(){return bState;}
};

class AirconditionerOnCommand:public Command
{
private:
	Airconditioner* airconditioner;

public:
	AirconditionerOnCommand(Airconditioner* airconditioner)
	{
		this->airconditioner = airconditioner;
	}

	virtual void execute(){airconditioner->On();}
};

class AirconditionerOffCommand:public Command
{
private:
	Airconditioner* airconditioner;

public:
	AirconditionerOffCommand(Airconditioner* airconditioner)
	{
		this->airconditioner = airconditioner;
	}

	virtual void undo(){airconditioner->Off();}
};