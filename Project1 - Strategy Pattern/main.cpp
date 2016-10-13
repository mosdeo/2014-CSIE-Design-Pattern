#include <iostream>
using namespace std;

class WeaponBehavior
{//�o�O�������O
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
protected://�o�̭n�ʸˡA���O�n���l���O�s��
	WeaponBehavior* ptr_Weapon;//�����X��, �D�~��
public:
	void fight()
	{
		//�o�̤���useWeapon()�A�浹�l���O�h���
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
	{//�ۭq�غc�l, �]�w�w�]�Z��
		Character::ptr_Weapon = new SwordBehavior();//�d�ܤ[,��ӨS��public �~��
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
	{//�ۭq�غc�l, �]�w�w�]�Z��
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
	{//�ۭq�غc�l, �]�w�w�]�Z��
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
	{//�ۭq�غc�l, �]�w�w�]�Z��
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