#pragma once //避免重複定義
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
		cout << "一個Command物件建構! "<< ObjCount <<endl;
	}
	virtual void execute()
	{/*這裡一定要寫嗎? 可不可以只宣告prototype ?*/
		cout << "Im Based class execute()" << endl;
	};
	virtual void undo()
	{/*這裡一定要寫嗎? 可不可以只宣告prototype ?*/
		cout << "Im qBased class undo()" << endl;
	};

	~Command()
	{
		ObjCount--;
		//cout << "一個Command物件解構! "<< ObjCount <<endl;
	}
};int Command::ObjCount=0;