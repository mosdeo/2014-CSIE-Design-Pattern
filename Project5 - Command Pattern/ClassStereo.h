#pragma once //Á×§K­«½Æ©w¸q
#include"ClassCommand.h"
#include<iostream>
#include<stdio.h>
using namespace std;

class Stereo
{
private:
	bool bState;

public:
	Stereo()
	{
		bState = false;
	}
	void On(){bState = true;}
	void Off(){bState = false;}
	bool getState(){return bState;}
};

class StereoOnCommand:public Command
{
private:
	Stereo* stereo;

public:
	StereoOnCommand(Stereo* stereo)
	{
		this->stereo = stereo;
	}

	virtual void execute(){stereo->On();}
};

class StereoOffCommand:public Command
{
private:
	Stereo* stereo;

public:
	StereoOffCommand(Stereo* stereo)
	{
		this->stereo = stereo;
	}

	virtual void undo(){stereo->Off();}
};