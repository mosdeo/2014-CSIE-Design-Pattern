//C++
//如果沒virtual的話, 呼叫同名函式的依據是看指標(或參考)型別
//如果加上virtual的話, 以實體型別為準
#include <string>
#include <iostream>
using namespace std;

class Chicken
{
public:
	virtual void Glide()=0;
	virtual void Eat()=0;
};

class Swallow
{
public:
	virtual void Fly()=0;
	virtual void Eat()=0;
};

class  WildSwallow:public Swallow
{
public:
	void Fly(){cout << " I am a wild swallow. I can fly";}
	void Eat(){cout << " I am a wild swallow. I can eat";}
};

class ChickenAdapterToSwallow:public Chicken
{
private:
	Swallow* ptrSwallow;
public:
	ChickenAdapterToSwallow(Swallow* p_ptrSwallow)
	{
		ptrSwallow = p_ptrSwallow;
	}
	
	~ChickenAdapterToSwallow()
	{
		delete ptrSwallow; //解構時自動回收 has a 所 new 出來的物件
	}

	void Glide()
	{
		ptrSwallow->Fly();
	}
	void Eat()
	{
		ptrSwallow->Eat();
	}
};

int main()
{
	Chicken* ChickenToSwallow  = new ChickenAdapterToSwallow(new WildSwallow());

	while(1)
	{
		cout << "60130257A 林高遠 Adapter Pattern" << endl;
		cout << "請輸入glide或eat:";
		string InputCommand;
		cin >> InputCommand;

		if("glide" == InputCommand)
		{
			ChickenToSwallow->Glide(); //被轉接成Fly();
			cout << endl;
		}

		if("eat" == InputCommand)
		{
			ChickenToSwallow->Eat(); //被轉接成另一個Eat();
			cout << endl;
		}

		cout << endl;
	}
}