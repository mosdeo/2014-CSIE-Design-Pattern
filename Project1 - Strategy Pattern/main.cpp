#include <iostream>
using namespace std;

class WeaponBehavior
{//這是介面類別
public:
	virtual void useWeapon()=0;
};

class SwordBehavior:public WeaponBehavior
{
public:
	void useWeapon()
	{
		cout << "The weapon I use to fight is sword!" <<endl;
	}
};

class KnifeBehavior:public WeaponBehavior
{
public:
	void useWeapon()
	{
		cout << "The weapon I use to fight is knife!" <<endl;
	}
};

class BowAndArrowBehavior:public WeaponBehavior
{
public:
	void useWeapon()
	{
		cout << "The weapon I use to fight is bow and arrow!" <<endl;
	}
};

class AxeBehavior:public WeaponBehavior
{
public:
	void useWeapon()
	{
		cout << "The weapon I use to fight is axe!" <<endl;
	}
};

class Character
{
protected://這裡要封裝，但是要讓子類別存取
	WeaponBehavior* ptr_Weapon;//此為合成, 非繼承
public:
	void fight()
	{
		//這裡不做useWeapon()，交給子類別去實踐
		//weapon->useWeapon();
	}
	void setWeapon(WeaponBehavior* ptr_w)
	{
		ptr_Weapon = ptr_w;
	}
	int CharacterInt;
};

class King:public Character
{
public:
	King()
	{//自訂建構子, 設定預設武器
		Character::ptr_Weapon = new SwordBehavior();//搞很久,原來沒有public 繼承
	}
	void fight()
	{
		cout << "I am King" <<endl;
		ptr_Weapon->useWeapon();
	}
};

class Queen:public Character
{
public:
	Queen()
	{//自訂建構子, 設定預設武器
		Character::ptr_Weapon = new KnifeBehavior();
	}
	void fight()
	{
		cout << "I am Queen" <<endl;
		ptr_Weapon->useWeapon();
	}
};

class Knight:public Character
{
public:
	Knight()
	{//自訂建構子, 設定預設武器
		Character::ptr_Weapon = new BowAndArrowBehavior();
	}
	void fight()
	{
		cout << "I am Knight" <<endl;
		ptr_Weapon->useWeapon();
	}
};

class Troll:public Character
{
public:
	Troll()
	{//自訂建構子, 設定預設武器
		Character::ptr_Weapon = new AxeBehavior();
	}
	void fight()
	{
		cout << "I am Troll" <<endl;
		ptr_Weapon->useWeapon();
	}
};

int main(void)
{
	King King;
	Queen Queen;
	Knight Knight;
	Troll Troll;

	SwordBehavior		static_obj_SwordBehavior;
	KnifeBehavior		static_obj_KnifeBehavior;
	BowAndArrowBehavior static_obj_BowAndArrowBehavior;
	AxeBehavior			static_obj_AxeBehavior;

	cout << "\n====== King show! ======" <<endl;
	King.fight();
	King.setWeapon(&static_obj_KnifeBehavior);
	King.fight();

	cout << "\n====== Queen show! ======" <<endl;
	Queen.fight();
	Queen.setWeapon(&static_obj_BowAndArrowBehavior);
	Queen.fight();

	cout << "\n====== Knight show! ======" <<endl;
	Knight.fight();
	Knight.setWeapon(&static_obj_AxeBehavior);
	Knight.fight();

	cout << "\n====== Troll show! ======" <<endl;
	Troll.fight();
	Troll.setWeapon(&static_obj_SwordBehavior);
	Troll.fight();

	system("PAUSE");
	

}