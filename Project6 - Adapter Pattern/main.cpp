//C++
//�p�G�Svirtual����, �I�s�P�W�禡���̾ڬO�ݫ���(�ΰѦ�)���O
//�p�G�[�Wvirtual����, �H���髬�O����
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
		delete ptrSwallow; //�Ѻc�ɦ۰ʦ^�� has a �� new �X�Ӫ�����
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
		cout << "60130257A �L���� Adapter Pattern" << endl;
		cout << "�п�Jglide��eat:";
		string InputCommand;
		cin >> InputCommand;

		if("glide" == InputCommand)
		{
			ChickenToSwallow->Glide(); //�Q�౵��Fly();
			cout << endl;
		}

		if("eat" == InputCommand)
		{
			ChickenToSwallow->Eat(); //�Q�౵���t�@��Eat();
			cout << endl;
		}

		cout << endl;
	}
}