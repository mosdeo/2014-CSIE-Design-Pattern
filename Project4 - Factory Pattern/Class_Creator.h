#include"Class_Product.h"

#include<string>
#include<sstream>
#include<iostream>
using namespace std;

//************ �H�U�O�إߪ����O ************//
class CharacterFactory
{//�����Ҧ��إߪ̪���¦���O
public:
	void create_Character();
	virtual Character* order_Character(string InputStr)  = 0;
};

class ParisCharacterFactory:public CharacterFactory
{
	Character* ptrCharacter;
public:
	void create_Character()
	{
		ptrCharacter = new Character();
	}

	Character* order_Character(string InputStr)
	{
		if("king" == InputStr)
			return new Paris_King();
		else if("queen" == InputStr)
			return new Paris_Queen();
		else if("troll" == InputStr)
			return new Paris_Troll();
		else if("knight" == InputStr)
			return new Paris_Knight();
		else if("archer" == InputStr)
			return new Paris_Archer();
		else
			return NULL;
	}
};

class LondonCharacterFactory:public CharacterFactory
{
	Character* ptrCharacter;
public:
	void create_Character()
	{
		ptrCharacter = new Character();
	}

	Character* order_Character(string InputStr)
	{
		if("king" == InputStr)
			return new London_King();
		else if("queen" == InputStr)
			return new London_Queen();
		else if("troll" == InputStr)
			return new London_Troll();
		else if("knight" == InputStr)
			return new London_Knight();
		else if("archer" == InputStr)
			return new London_Archer();
		else
			return NULL;
	}
};
//************ �H�W�O�إߪ����O ************//