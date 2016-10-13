#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Server
{
public:
	void static send()
	{
	}
	void static add();
	void static del();
};


class Client
{
private:
	string Name;
	string RxBuf;
	char cType;
public:
	Client(string initialName,char initial_cType)
	{//自訂建構子
		Name = initialName;
		cType = initial_cType;
	}

	void setRxBuf(string p_RxBuf)
	{
		RxBuf = p_RxBuf;//先存下來

		//小寫轉大寫
		for(int i=0;i<RxBuf.size();i++)
		{
			switch(cType)
			{
				case 'c':
					if(RxBuf.c_str()[i]>=97 && RxBuf.c_str()[i]<=122)//這範圍內是小寫
						RxBuf.replace(i,1,1,(char)(RxBuf.c_str()[i]-32));
				break;

				case 'l':
					if(RxBuf.c_str()[i]>=65 && RxBuf.c_str()[i]<=90)//這範圍內是大寫
						RxBuf.replace(i,1,1,(char)(RxBuf.c_str()[i]+32));
				break;
			}
		}
	}
	string getRxBuf(){return RxBuf;}
	string getName(){return Name;}
	string getType(){return 'c'==cType ? "Capital":"Lowercase";}
};



int main()
{
	//指向 Client 物件的動態陣列
	vector<Client*> ArrayOfClient;

	cout << "60132057A 林高遠 設計模式 HW2" << endl << endl;
	

	while(1)
	{
		cout << "Command: ";
		string inputCommand;
		cin >> inputCommand;

		//add 指令
		if(0 == inputCommand.compare("add"))
		{
			string tempObjName;
			char cType;

			//讀進物件名
			cin >> inputCommand;
			tempObjName = inputCommand;

			//讀進物件種類
			cin >> inputCommand;
			if(0 == inputCommand.compare("type=c"))cType='c';
			if(0 == inputCommand.compare("type=l"))cType='l';

			ArrayOfClient.push_back(new Client(tempObjName,cType));
			//cout << "push_back a Client, named:" << ArrayOfClient[ArrayOfClient.size()-1]->getName();
			//cout << ",Type:" << ArrayOfClient[ArrayOfClient.size()-1]->getType();
			//cout << endl;
		}

		//del 指令
		if(0 == inputCommand.compare("del"))
		{
			string killName;
			cin >> killName;

			for(int i=0;i<ArrayOfClient.size();i++)
				if(ArrayOfClient[i]->getName() == killName)
					ArrayOfClient.erase(ArrayOfClient.begin()+i);
		}

		//send 指令
		if(0 == inputCommand.compare("send"))
		{
			string RxBuf;
			getline(cin,RxBuf);

			//擷取廣播內容
			RxBuf = RxBuf.substr(2,RxBuf.size()-3);

			for(int i=0;i<ArrayOfClient.size();i++)
			{//對每個聽眾依序 1發送 2秀出名稱與內容
				ArrayOfClient[i]->setRxBuf(RxBuf);
				cout << ArrayOfClient[i]->getName();
				cout << " ";
				cout << ArrayOfClient[i]->getRxBuf() << endl;
			}
		}
	}

	system("PAUSE");
}