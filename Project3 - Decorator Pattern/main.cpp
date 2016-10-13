#include"Pizza Class.h"
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Convert
{//Designed by LKY
public:
	static void Toupper(string& src_string)
	{
		std::transform(src_string.begin(),src_string.end(),src_string.begin(),toupper);
	}

	static string Toupper(char* ptrString)
	{
		string OutString(ptrString);
		Toupper(OutString);
		return OutString;
	}
};

void OrderList(void)
{
	cout << "CSIE@NTNU Pizza store"<<endl;
	cout << "=== 餅皮 (only 1, must be first key-in)===" <<endl;
	cout << "ThinDough 400" <<endl;
	cout << "CrushDough 450" <<endl;
	cout <<endl;
	cout << "=== 香料 (muti-choose) ===" <<endl;
	cout << "cheese 100" <<endl;
	cout << "mushroom 150" <<endl;
	cout << "clam 200" <<endl;
	cout << "pea 50" <<endl;
}

int main()
{
	cout << "設計模式 HW3 60132057A 林高遠" << endl;
	cout << endl;
	OrderList();
	cout << endl;

	Dough* ptr_dough = NULL;
	string KeyinOrder;
	vector<string> vs; //存放 餅皮,加料 等細項的字串陣列
	

	while(cout << "請訂購您的客製化 Pizza:"<<endl && getline(cin,KeyinOrder))
	{
		Convert::Toupper(KeyinOrder); //Anti stupid 轉大寫
		istringstream iss(KeyinOrder); //不太懂
		copy(istream_iterator<string>(iss),istream_iterator<string>(),back_insert_iterator<vector<string>>(vs));

		for(vector<string>::iterator it=vs.begin();it!=vs.end();it++)
		{//使用STL智慧型pointer, 此處(*it)之型別為string

			if(Convert::Toupper("CPP") == *it ||Convert::Toupper("Java") == *it)
				printf("A"),
				printf("B");

			if(Convert::Toupper("Pizza") == *it)
				printf("C");
		
			//餅皮
			else if(Convert::Toupper("ThinDough") == *it) ptr_dough = new ThinDough();
			else if(Convert::Toupper("CrushDough")== *it) ptr_dough = new CrushDough();

			//香料
			else if(Convert::Toupper("cheese") == *it) ptr_dough = new Cheese(ptr_dough);
			else if(Convert::Toupper("mushroom") == *it) ptr_dough = new Mushroom(ptr_dough);
			else if(Convert::Toupper("clam") == *it) ptr_dough = new Clam(ptr_dough);
			else if(Convert::Toupper("pea") == *it) ptr_dough = new Pea(ptr_dough);
		}//for end

		cout << "The order "<< ptr_dough->getDescription() <<" is "<< ptr_dough->Cost() <<" dollars"<<endl<<endl;
	}

	system("PAUSE");
}