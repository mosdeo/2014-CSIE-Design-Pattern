#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Server
{
public:
	void send();
	void add();
	void del();
};

class MyString
{
	
};

class Capital:public MyString
{
private:
	string Name;
	string RxBuf;
public:
	Capital(string initialName)//�ۭq�غc�l
	{
		Name = initialName;
		RxBuf= "HELLO WORLD";
	}
	void setName(string p_Name)
	{
		Name = p_Name;//���s�U��

		//�p�g��j�g
		for(int i=0;i<Name.length();i++)
		{
			if(Name.c_str()[i]>=97 && Name.c_str()[i]<=122)//�o�d�򤺬O�p�g
				Name.replace(i,1,1,(char)(Name.c_str()[i]-32));
		}
	}
	string getName(){return Name;}
};

class Lowercase:public MyString
{
private:
	string Name;
	string RxBuf;
public:
	Lowercase(string initialName)//�ۭq�غc�l
	{
		Name = initialName;
		RxBuf= "hello world";
	}
	void setName(string p_Name)
	{
		Name = p_Name;//���s�U��

		//�j�g��p�g
		for(int i=0;i<Name.length();i++)
		{
			if(Name.c_str()[i]>=65 && Name.c_str()[i]<=90)//�o�d�򤺬O�j�g
				Name.replace(i,1,1,(char)(Name.c_str()[i]+32));
		}
	}
	string getName(){return Name;}
};

string inputCommand;
int main()
{
	
	vector<MyString*> ArrayOfMyString;

	cout << "Command:" << endl;

	MyString* ptr = new Capital("test Obj");
	ptr-
	//�����O����, ����s���l���O????
	while(1)
	{
		cin >> inputCommand;

		//add
		if(0 == inputCommand.compare("add"))
		{
			//Ū�i����W
			cin >> inputCommand;
			string tempObjName = inputCommand;

			//Ū�i�������
			cin >> inputCommand;

			if(0 == inputCommand.compare("type=c"))
			{
				ArrayOfMyString.push_back(new Capital(tempObjName));
				//ArrayOfMyString.back() = new Capital(tempObjName);
				cout << "Push a Capital Obj, named " << ArrayOfMyString[1] <<endl;
			}

			if(0 == inputCommand.compare("type=l"))
			{
				cout << "Push a Lowercase Obj"<<endl;
				ArrayOfMyString.push_back(new Lowercase(tempObjName));
			}
		}

		if(0 == inputCommand.compare("del"));

		if(0 == inputCommand.compare("send"));
	}

	system("PAUSE");
}