#include"ClassTV.h"
#include"ClassLight.h"
#include"ClassAirconditioner.h"
#include"ClassDVDplayer.h"
#include"ClassStereo.h"

#include"ClassRemoteControl.h"
#include<iostream>
using namespace std;

//1: TV, 2: light, 3: airconditioner, 4: dvdplayer, 5: stereo

int main()
{
	cout << "�]�p�Ҧ� HW5 �R�O�Ҧ� 60132057A �L����" << endl;
	cout << endl;
	cout << "============================================================" << endl;
	cout << "switches the ��on�� and ��off�� states of a device. 1~5" << endl;
	cout << "1: TV, 2: light, 3: airconditioner, 4: dvdplayer, 5: stereo" << endl;
	cout << "6: Turn all devices off" << endl;
	cout << "7: Turn all device on." << endl;
	cout << "8: Show the current status of all the devices" << endl;
	cout << "============================================================" << endl;

	RemoteControl* remoteControl = new RemoteControl(5);	//r�إ߻���������

	//�إߦU�ظ˸m����
	TV* tv = new TV();	
	Light* light = new Light();
	Airconditioner* airconditioner = new Airconditioner();
	DVDplayer* dvdplayer = new DVDplayer();
	Stereo* stereo = new Stereo();
	
	//�إߩҦ��� TV �R�O����
	TVOnCommand* tvOn = new TVOnCommand(tv);
	TVOffCommand* tvOff = new TVOffCommand(tv);

	//�إߩҦ��� Light �R�O����
	LightOnCommand* lightOn = new LightOnCommand(light);
	LightOffCommand* lightOff = new LightOffCommand(light);

	//�إߩҦ��� Airconditioner �R�O����
	AirconditionerOnCommand* airconditionerOn = new AirconditionerOnCommand(airconditioner);
	AirconditionerOffCommand* airconditionerOff = new AirconditionerOffCommand(airconditioner);

	//�إߩҦ��� DVDplayer �R�O����
	DVDplayerOnCommand* dvdplayerOn = new DVDplayerOnCommand(dvdplayer);
	DVDplayerOffCommand* dvdplayerOff = new DVDplayerOffCommand(dvdplayer);

	//�إߩҦ��� Stereo �R�O����
	StereoOnCommand* stereoOn = new StereoOnCommand(stereo);
	StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

	//���J���������Ѥ�
	remoteControl->setCommand(0,tvOn,tvOff);
	remoteControl->setCommand(1,lightOn,lightOff);
	remoteControl->setCommand(2,airconditionerOn,airconditionerOff);
	remoteControl->setCommand(3,dvdplayerOn,dvdplayerOff);
	remoteControl->setCommand(4,stereoOn,stereoOff);

	while(1)
	{
		int Command;
		cin >> Command;
		Command--; //shift

		switch(Command)
		{
		case 0://TV
			if(!tv->getState())
			{
				remoteControl->onButtonWasPushed(Command);
				cout << "TV is On" << endl;
			}
			else
			{
				remoteControl->offButtonWasPushed(Command);
				cout << "TV is Off" << endl;
			}
			break;
		case 1://Light
			if(!light->getState())
			{
				remoteControl->onButtonWasPushed(Command);
				cout << "Light is On" << endl;
			}
			else
			{
				remoteControl->offButtonWasPushed(Command);
				cout << "Light is Off" << endl;
			}
			break;
		case 2://Airconditioner
			if(!airconditioner->getState())
			{
				remoteControl->onButtonWasPushed(Command);
				cout << "Airconditioner is On" << endl;
			}
			else
			{
				remoteControl->offButtonWasPushed(Command);
				cout << "Airconditioner is Off" << endl;
			}
			break;
		case 3://DVDplayer
			if(!dvdplayer->getState())
			{
				remoteControl->onButtonWasPushed(Command);
				cout << "DVDplayer is On" << endl;
			}
			else
			{
				remoteControl->offButtonWasPushed(Command);
				cout << "DVDplayer is Off" << endl;
			}
			break;
		case 4://Stereo
			if(!stereo->getState())
			{
				remoteControl->onButtonWasPushed(Command);
				cout << "Stereo is On" << endl;
			}
			else
			{
				remoteControl->offButtonWasPushed(Command);
				cout << "Stereo is Off" << endl;
			}
			break;
		case 5://Turn off All
			for(int i=0;i<5;i++)
			{
				remoteControl->offButtonWasPushed(i);
			}
			cout << "Turned off all device." << endl;
			break;
		case 6://Turn On All
			for(int i=0;i<5;i++)
			{
				remoteControl->onButtonWasPushed(i);
			}
			cout << "Turned on all device." << endl;
			break;
		case 7://Show state of all device
			tv->getState() ? cout << "TV is On" : cout << "TV is Off";
			cout << ", ";
			light->getState() ? cout << "Light is On" : cout << "Light is Off";
			cout << ", ";
			airconditioner->getState() ? cout << "Airconditioner is On" : cout << "Airconditioner is Off";
			cout << ", ";
			dvdplayer->getState() ? cout << "DVDplayer is On" : cout << "DVDplayer is Off";
			cout << ", ";
			stereo->getState() ? cout << "Stereo is On" : cout << "Stereo is Off";
			cout << endl;
			break;
		default:
			cout << "ERROR" << endl;
			break;
		}
	}
}