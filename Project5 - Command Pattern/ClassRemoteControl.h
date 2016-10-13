#pragma once //避免重複定義
#include"ClassCommand.h"
#include<iostream>
using namespace std;

class RemoteControl
{
private:
	//Command* ptr_onCommand[5];
	//Command* ptr_offCommand[5];
	Command** ptr_onCommand; //數量尚未決定
	Command** ptr_offCommand;

public:
	//RemoteControl(int No)
	//{
	//	cout << "RemoteControl物件 建構開始" << endl;
	//	for(int i=0;i<No;i++)
	//	{
	//		(*ptr_onCommand)+i  = new Command();//compiler ERROR 
	//		*(ptr_offCommand+i) = new Command();//runtime ERROR
	//	}
	//	cout << "RemoteControl物件 建構結束" << endl;
	//}

	RemoteControl(int No)
	{
		ptr_onCommand = (Command**)malloc(No*sizeof(ptr_onCommand));
		ptr_offCommand = (Command**)malloc(No*sizeof(ptr_offCommand));
	}


	void setCommand(int No, Command* DeviceOnCommand, Command* DeviceOffCommand)
	{//載入遙控器插槽的方法

		//兩種同樣效果
		*(ptr_onCommand+No) = DeviceOnCommand;
		*(ptr_offCommand+No) = DeviceOffCommand;
		//ptr_onCommand[No] = DeviceOnCommand;
		//ptr_offCommand[No] = DeviceOffCommand;
	}

	void onButtonWasPushed(int No)
	{
		//兩種不同樣效果, 但第0個元素一樣

		//將管理眾多衍生類的基礎類指標，依照所呼叫的衍生類，強制轉型成呼叫的衍生類，

		//第一種
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
		//第二種
		//(*ptr_onCommand+No)->execute();
	}

	void offButtonWasPushed(int No)
	{
		//兩種不同樣效果, 但第0個元素一樣

		//第一種
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

		//第二種
		//(*ptr_onCommand+No)->execute();
	}
};
