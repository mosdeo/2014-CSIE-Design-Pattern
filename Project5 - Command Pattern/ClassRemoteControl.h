#pragma once //�קK���Ʃw�q
#include"ClassCommand.h"
#include<iostream>
using namespace std;

class RemoteControl
{
private:
	//Command* ptr_onCommand[5];
	//Command* ptr_offCommand[5];
	Command** ptr_onCommand; //�ƶq�|���M�w
	Command** ptr_offCommand;

public:
	//RemoteControl(int No)
	//{
	//	cout << "RemoteControl���� �غc�}�l" << endl;
	//	for(int i=0;i<No;i++)
	//	{
	//		(*ptr_onCommand)+i  = new Command();//compiler ERROR 
	//		*(ptr_offCommand+i) = new Command();//runtime ERROR
	//	}
	//	cout << "RemoteControl���� �غc����" << endl;
	//}

	RemoteControl(int No)
	{
		ptr_onCommand = (Command**)malloc(No*sizeof(ptr_onCommand));
		ptr_offCommand = (Command**)malloc(No*sizeof(ptr_offCommand));
	}


	void setCommand(int No, Command* DeviceOnCommand, Command* DeviceOffCommand)
	{//���J���������Ѫ���k

		//��ئP�ˮĪG
		*(ptr_onCommand+No) = DeviceOnCommand;
		*(ptr_offCommand+No) = DeviceOffCommand;
		//ptr_onCommand[No] = DeviceOnCommand;
		//ptr_offCommand[No] = DeviceOffCommand;
	}

	void onButtonWasPushed(int No)
	{
		//��ؤ��P�ˮĪG, ����0�Ӥ����@��

		//�N�޲z���h�l��������¦�����СA�̷өҩI�s���l�����A�j���૬���I�s���l�����A

		//�Ĥ@��
		switch(No)
		{
		case 0:
			((TVOnCommand*)(*(ptr_onCommand+No)))->execute();
			break;
		case 1:
			((LightOnCommand*)(*(ptr_onCommand+No)))->execute();
			break;
		case 2:
			((AirconditionerOnCommand*)(*(ptr_onCommand+No)))->execute();
			break;
		case 3:
			((DVDplayerOnCommand*)(*(ptr_onCommand+No)))->execute();
			break;
		case 4:
			((StereoOnCommand*)(*(ptr_onCommand+No)))->execute();
			break;
		default:
			break;
		}
		//�ĤG��
		//(*ptr_onCommand+No)->execute();
	}

	void offButtonWasPushed(int No)
	{
		//��ؤ��P�ˮĪG, ����0�Ӥ����@��

		//�Ĥ@��
		switch(No)
		{
		case 0:
			((TVOffCommand*)(*(ptr_offCommand+No)))->undo();
			break;
		case 1:
			((LightOffCommand*)(*(ptr_offCommand+No)))->undo();
			break;
		case 2:
			((AirconditionerOffCommand*)(*(ptr_offCommand+No)))->undo();
			break;
		case 3:
			((DVDplayerOffCommand*)(*(ptr_offCommand+No)))->undo();
			break;
		case 4:
			((StereoOffCommand*)(*(ptr_offCommand+No)))->undo();
			break;
		default:
			break;
		}

		//�ĤG��
		//(*ptr_onCommand+No)->execute();
	}
};