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
	Capital(string initialName)//自訂建構子
	{
		Name = initialName;
		RxBuf= "HELLO WORLD";
	}
	void setName(string p_Name)
	{
		Name = p_Name;//先存下來

		//小寫轉大寫
		for(int i=0;i<Name.length();i++)
		{
			if(Name.c_str()[i]>=97 && Name.c_str()[i]<=122)//這範圍內是小寫
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
	Lowercase(string initialName)//自訂建構子
	{
		Name = initialName;
		RxBuf= "hello world";
	}
	void setName(string p_Name)
	{
		Name = p_Name;//先存下來

		//大寫轉小寫
		for(int i=0;i<Name.length();i++)
		{
			if(Name.c_str()[i]>=65 && Name.c_str()[i]<=90)//這範圍內是大寫
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
	//父類別指標, 不能存取子類別????
	while(1)
	{
		cin >> inputCommand;

		//add
		if(0 == inputCommand.compare("add"))
		{
			//讀進物件名
			cin >> inputCommand;
			string tempObjName = inputCommand;

			//讀進物件種類
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