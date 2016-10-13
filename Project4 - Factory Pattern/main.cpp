#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include "Class_Creator.h"
using namespace std;

class Convert
{//Designed by LKY
 //Have to #include<algorithm>
public:
	static void Toupper(string& src_string)
	{
		std::transform(src_string.begin(),src_string.end(),src_string.begin(),toupper);
	}

	static void Tolower(string& src_string)
	{
		std::transform(src_string.begin(),src_string.end(),src_string.begin(),tolower);
	}

	static string Toupper(char* ptrString)
	{
		string OutString(ptrString);
		Toupper(OutString);
		return OutString;
	}

	static string Tolower(char* ptrString)
	{
		string OutString(ptrString);
		Tolower(OutString);
		return OutString;
	}
};

int main(void)
{
	cout << "設計模式 HW4 工廠模式 60132057A 林高遠" << endl;
	cout << endl;

	//*** 以下的while() 相依於這些宣告 ***//
	string KeyinOrder; //輸入的整串命令
	vector<string> vs; //存放 城市,字母 等細項的字串陣列

	while(cout << "請輸入:"<<endl && getline(cin,KeyinOrder))
	{
		string City, strCharacter;

		//建立兩個不同的工廠
		CharacterFactory* LondonFactory = new LondonCharacterFactory();
		CharacterFactory* ParisFactory = new ParisCharacterFactory();

		Convert::Tolower(KeyinOrder); //Anti stupid 轉大寫
		istringstream iss(KeyinOrder); //不太懂
		copy(istream_iterator<string>(iss),istream_iterator<string>(),back_insert_iterator<vector<string>>(vs));

		for(vector<string>::iterator it=vs.begin();it!=vs.end();it++)
		{//使用STL智慧型pointer, 此處(*it)之型別為string

			if(Convert::Tolower("CPP") == *it ||Convert::Tolower("Java") == *it || Convert::Tolower("game") == *it)
				continue;//忽略

			if(Convert::Tolower("London") == *it ||	Convert::Tolower("Paris") == *it)
				City = *it;//存下城市種類

			if(Convert::Tolower("King") == *it || Convert::Tolower("Queen") == *it || Convert::Tolower("Troll") == *it ||
			   Convert::Tolower("Knight") == *it || Convert::Tolower("Archer") == *it )
			   strCharacter = *it;//存下武士種類

			if(Convert::Tolower("exit") == *it)
			{
				delete LondonFactory;
				delete ParisFactory;
				exit(8);//結束程式
			}
		}

		Character* character = NULL;
		if(Convert::Tolower("London") == City)
			character = LondonFactory->order_Character(strCharacter);
		else if(Convert::Tolower("Paris") == City)
			character = ParisFactory->order_Character(strCharacter);

		cout << "I am a " << character->getName() << " The weapon I use to fight is " << character->weapon << endl;
		delete LondonFactory;
		delete ParisFactory;
	}
	
	
}