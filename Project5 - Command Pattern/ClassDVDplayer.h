#pragma once //Á×§K­«½Æ©w¸q
#include"ClassCommand.h"
#include<iostream>
#include<stdio.h>
using namespace std;

class DVDplayer
{
private:
	bool bState;

public:
	DVDplayer()
	{
		bState = false;
	}
	void On(){bState = true;}
	void Off(){bState = false;}
	bool getState(){return bState;}
};

class DVDplayerOnCommand:public Command
{
private:
	DVDplayer* dvdplayer;

public:
	DVDplayerOnCommand(DVDplayer* dvdplayer)
	{
		this->dvdplayer = dvdplayer;
	}

	virtual void execute(){dvdplayer->On();}
};

class DVDplayerOffCommand:public Command
{
private:
	DVDplayer* dvdplayer;

public:
	DVDplayerOffCommand(DVDplayer* dvdplayer)
	{
		this->dvdplayer = dvdplayer;
	}

	virtual void undo(){dvdplayer->Off();}
};