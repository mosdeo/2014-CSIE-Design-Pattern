/*
Progrmmer:Lin Kao-Yuan
Date:2014/3/4

The porgram is a "Observer pattern" exercise,
using a "Server" object management to his "Client" objects,
"Server" object can be add, delete or broadcasting to "Client" objects.

ex:
	Command:
	# add c1 type=c
	# add c2 type=l
	# send “Hello World”
	# del c1
	# send “Hello World Again”

	Output:
	c1 HELLO WORLD
	c2 hello world
	c2 hello world again
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Client
{
private:
	string Name;
	string Message;
	char cType;
public:
	Client(string initialName,char initial_cType)
	{//自訂建構子
		Name = initialName;
		cType = initial_cType;
	}

	void setMessage(string MessageBuf)
	{
		//小寫轉大寫
		for(unsigned int i=0;i<MessageBuf.size();i++)
		{
			switch(cType)
			{//依物件本身設定好的類型(大寫or小寫)選擇正確的字元轉換程式
				case 'c':
					if(MessageBuf.c_str()[i]>=97 && MessageBuf.c_str()[i]<=122)//這範圍內是小寫
						MessageBuf.replace(i,1,1,(char)(MessageBuf.c_str()[i]-32));
				break;

				case 'l':
					if(MessageBuf.c_str()[i]>=65 && MessageBuf.c_str()[i]<=90)//這範圍內是大寫
						MessageBuf.replace(i,1,1,(char)(MessageBuf.c_str()[i]+32));
				break;
				
				//不是英文字母的,維持原狀不處理
				default:
				break;
			}
		}

		Message = MessageBuf;
	}
	string getMessage(){return Message;}
	string getName(){return Name;}
	string getType(){return 'c'==cType ? "Capital":"Lowercase";}
};

class Server
{
public:
	//指向 Client 物件的動態陣列
	vector<Client*> ArrayOfClient; //Has much Client, not a Client

	void  add(string ObjName,string Type)
	{
		//寫進物件種類
		char cType;
		if(0 == Type.compare("type=c"))cType='c';
		if(0 == Type.compare("type=l"))cType='l';

		ArrayOfClient.push_back(new Client(ObjName,cType));
	};

	void send(string RxBuf)
	{
		//擷取廣播內容
		RxBuf = RxBuf.substr(1,RxBuf.size()-2);

		for(unsigned int i=0;i<ArrayOfClient.size();i++)
		{//對每個聽眾依序 1.發送 2.秀出名稱與內容
			ArrayOfClient[i]->setMessage(RxBuf);
			cout << ArrayOfClient[i]->getName();
			cout << " ";
			cout << ArrayOfClient[i]->getMessage() << endl;
		}
	};
	
	void del(string killName)
	{
		for(unsigned int i=0;i<ArrayOfClient.size();i++)//每個存在的元素都問
			if(ArrayOfClient[i]->getName() == killName)//如果是要被刪除的
				ArrayOfClient.erase(ArrayOfClient.begin()+i);//就擦掉
	};
};


int main()
{
	cout << "60132057A 林高遠 設計模式 HW2" << endl << endl;
	
	Server S1;
	string KeyinCommand;

	while(1)
	{
		cout << "Command: ";
		cin >> KeyinCommand;

		//add 指令
		if(0 == KeyinCommand.compare("add"))
		{
			string KeyinName,KeyinType;
			cin >> KeyinName;
			cin >> KeyinType;
			S1.add(KeyinName,KeyinType);
		}

		//del 指令
		if(0 == KeyinCommand.compare("del"))
		{
			string KeyinKillName;
			cin >> KeyinKillName;
			S1.del(KeyinKillName);
		}

		//send 指令
		if(0 == KeyinCommand.compare("send"))
		{
			string KeyinString;
			cin >> KeyinString;
			S1.send(KeyinString);
		}
	}
}