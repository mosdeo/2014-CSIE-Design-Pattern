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
	# send ��Hello World��
	# del c1
	# send ��Hello World Again��

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
	{//�ۭq�غc�l
		Name = initialName;
		cType = initial_cType;
	}

	void setMessage(string MessageBuf)
	{
		//�p�g��j�g
		for(unsigned int i=0;i<MessageBuf.size();i++)
		{
			switch(cType)
			{//�̪��󥻨��]�w�n������(�j�gor�p�g)��ܥ��T���r���ഫ�{��
				case 'c':
					if(MessageBuf.c_str()[i]>=97 && MessageBuf.c_str()[i]<=122)//�o�d�򤺬O�p�g
						MessageBuf.replace(i,1,1,(char)(MessageBuf.c_str()[i]-32));
				break;

				case 'l':
					if(MessageBuf.c_str()[i]>=65 && MessageBuf.c_str()[i]<=90)//�o�d�򤺬O�j�g
						MessageBuf.replace(i,1,1,(char)(MessageBuf.c_str()[i]+32));
				break;
				
				//���O�^��r����,�����쪬���B�z
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
	//���V Client ���󪺰ʺA�}�C
	vector<Client*> ArrayOfClient; //Has much Client, not a Client

	void  add(string ObjName,string Type)
	{
		//�g�i�������
		char cType;
		if(0 == Type.compare("type=c"))cType='c';
		if(0 == Type.compare("type=l"))cType='l';

		ArrayOfClient.push_back(new Client(ObjName,cType));
	};

	void send(string RxBuf)
	{
		//�^���s�����e
		RxBuf = RxBuf.substr(1,RxBuf.size()-2);

		for(unsigned int i=0;i<ArrayOfClient.size();i++)
		{//��C��ť���̧� 1.�o�e 2.�q�X�W�ٻP���e
			ArrayOfClient[i]->setMessage(RxBuf);
			cout << ArrayOfClient[i]->getName();
			cout << " ";
			cout << ArrayOfClient[i]->getMessage() << endl;
		}
	};
	
	void del(string killName)
	{
		for(unsigned int i=0;i<ArrayOfClient.size();i++)//�C�Ӧs�b����������
			if(ArrayOfClient[i]->getName() == killName)//�p�G�O�n�Q�R����
				ArrayOfClient.erase(ArrayOfClient.begin()+i);//�N����
	};
};


int main()
{
	cout << "60132057A �L���� �]�p�Ҧ� HW2" << endl << endl;
	
	Server S1;
	string KeyinCommand;

	while(1)
	{
		cout << "Command: ";
		cin >> KeyinCommand;

		//add ���O
		if(0 == KeyinCommand.compare("add"))
		{
			string KeyinName,KeyinType;
			cin >> KeyinName;
			cin >> KeyinType;
			S1.add(KeyinName,KeyinType);
		}

		//del ���O
		if(0 == KeyinCommand.compare("del"))
		{
			string KeyinKillName;
			cin >> KeyinKillName;
			S1.del(KeyinKillName);
		}

		//send ���O
		if(0 == KeyinCommand.compare("send"))
		{
			string KeyinString;
			cin >> KeyinString;
			S1.send(KeyinString);
		}
	}
}