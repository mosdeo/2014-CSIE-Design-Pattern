#pragma once //�קK���Ʃw�q
#include<iostream>
using namespace std;

class Command
{
public:
	static int ObjCount;

public:
	Command()
	{
		ObjCount++;
		cout << "�@��Command����غc! "<< ObjCount <<endl;
	}
	virtual void execute()
	{/*�o�̤@�w�n�g��? �i���i�H�u�ŧiprototype ?*/
		cout << "Im Based class execute()" << endl;
	};
	virtual void undo()
	{/*�o�̤@�w�n�g��? �i���i�H�u�ŧiprototype ?*/
		cout << "Im qBased class undo()" << endl;
	};

	~Command()
	{
		ObjCount--;
		//cout << "�@��Command����Ѻc! "<< ObjCount <<endl;
	}
};int Command::ObjCount=0;