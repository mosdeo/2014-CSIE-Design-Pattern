#include<string>
#include<iostream>
using namespace std;

class Dough
{
protected:
	string description;
	int cost;
public:
	virtual string getDescription()=0;
	virtual int Cost()=0;
};

class ThinDough:public Dough
{
public:
	ThinDough()
	{
		//Dough::Dough(); //Derived Class Constructor have to call Base Class Constructor.
		Dough::description = "ThinDough";
	}
	string getDescription(){return Dough::description;}
	int Cost(){return 400;}
};

class CrushDough:public Dough
{
public:
	CrushDough()
	{
		//Dough::Dough(); //Derived Class Constructor have to call Base Class Constructor.
		Dough::description = "CrushDough";
	}
	string getDescription(){return Dough::description;}
	int Cost(){return 450;}
};

class Ingredient:public Dough
{
public:
	string getDescription(){return description;}
};


class Cheese:public Ingredient
{
private:
	Dough* ptr_dough;
public:
	Cheese(Dough* ptr_p_dough) {ptr_dough = ptr_p_dough;}
	int Cost() {return ptr_dough->Cost() + 100 ;}
	string getDescription(){return this->ptr_dough->getDescription() + " Cheese";}
};

class Mushroom:public Ingredient
{
private:
	Dough* ptr_dough;
public:
	Mushroom(Dough* ptr_p_dough) {ptr_dough = ptr_p_dough;}
	int Cost() {return ptr_dough->Cost() + 150 ;}
	string getDescription(){return this->ptr_dough->getDescription() + " Mushroom";}
};

class Clam:public Ingredient
{
private:
	Dough* ptr_dough;
public:
	Clam(Dough* ptr_p_dough) {ptr_dough = ptr_p_dough;}
	int Cost() {return ptr_dough->Cost() + 200 ;}
	string getDescription(){return this->ptr_dough->getDescription() + " Clam";}
};

class Pea:public Ingredient
{
private:
	Dough* ptr_dough;
public:
	Pea(Dough* ptr_p_dough) {ptr_dough = ptr_p_dough;}
	int Cost() {return ptr_dough->Cost() + 50 ;}
	string getDescription(){return this->ptr_dough->getDescription() + " Pea";}
};