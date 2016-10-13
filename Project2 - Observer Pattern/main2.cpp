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
	{//�ۭq�غc�l
		Name = initialName;
		cType = initial_cType;
	}

	void setRxBuf(string p_RxBuf)
	{
		RxBuf = p_RxBuf;//���s�U��

		//�p�g��j�g
		for(int i=0;i<RxBuf.size();i++)
		{
			switch(cType)
			{
				case 'c':
					if(RxBuf.c_str()[i]>=97 && RxBuf.c_str()[i]<=122)//�o�d�򤺬O�p�g
						RxBuf.replace(i,1,1,(char)(RxBuf.c_str()[i]-32));
				break;

				case 'l':
					if(RxBuf.c_str()[i]>=65 && RxBuf.c_str()[i]<=90)//�o�d�򤺬O�j�g
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
	//���V Client ���󪺰ʺA�}�C
	vector<Client*> ArrayOfClient;

	cout << "60132057A �L���� �]�p�Ҧ� HW2" << endl << endl;
	

	while(1)
	{
		cout << "Command: ";
		string inputCommand;
		cin >> inputCommand;

		//add ���O
		if(0 == inputCommand.compare("add"))
		{
			string tempObjName;
			char cType;

			//Ū�i����W
			cin >> inputCommand;
			tempObjName = inputCommand;

			//Ū�i�������
			cin >> inputCommand;
			if(0 == inputCommand.compare("type=c"))cType='c';
			if(0 == inputCommand.compare("type=l"))cType='l';

			ArrayOfClient.push_back(new Client(tempObjName,cType));
			//cout << "push_back a Client, named:" << ArrayOfClient[ArrayOfClient.size()-1]->getName();
			//cout << ",Type:" << ArrayOfClient[ArrayOfClient.size()-1]->getType();
			//cout << endl;
		}

		//del ���O
		if(0 == inputCommand.compare("del"))
		{
			string killName;
			cin >> killName;

			for(int i=0;i<ArrayOfClient.size();i++)
				if(ArrayOfClient[i]->getName() == killName)
					ArrayOfClient.erase(ArrayOfClient.begin()+i);
		}

		//send ���O
		if(0 == inputCommand.compare("send"))
		{
			string RxBuf;
			getline(cin,RxBuf);

			//�^���s�����e
			RxBuf = RxBuf.substr(2,RxBuf.size()-3);

			for(int i=0;i<ArrayOfClient.size();i++)
			{//��C��ť���̧� 1�o�e 2�q�X�W�ٻP���e
				ArrayOfClient[i]->setRxBuf(RxBuf);
				cout << ArrayOfClient[i]->getName();
				cout << " ";
				cout << ArrayOfClient[i]->getRxBuf() << endl;
			}
		}
	}

	system("PAUSE");
}