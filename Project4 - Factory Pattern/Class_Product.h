#include<iostream>
using namespace std;

//************ 以下是產品類別 ************//
class Character
{//此為所有產品的基礎類別
public:
	string weapon;
	virtual string getName()
	{
		return "based class:ERROR";
	}
};

class Paris_King:public Character
{
public:
	Paris_King()
	{
		weapon = "sword";
	}
	virtual string getName()
	{
		return "Paris_King";
	};
};

class Paris_Queen:public Character
{
public:
	Paris_Queen()
	{
		weapon = "knife";
	}
	virtual string getName()
	{
		return "Paris_Queen";
	};
};

class Paris_Troll:public Character
{
public:
	Paris_Troll()
	{
		weapon = "Axe";
	}
	virtual string getName()
	{
		return "Paris_Troll";
	};
};

class Paris_Knight:public Character
{
public:
	Paris_Knight()
	{
		weapon = "sword";
	}
	virtual string getName()
	{
		return "Paris_Knight";
	};
};

class Paris_Archer:public Character
{
public:
	Paris_Archer()
	{
		weapon = "Bow";
	}
	virtual string getName()
	{
		return " Paris_Archer";
	};
};



class London_King:public Character
{
public:
	London_King()
	{
		weapon = "sword";
	}
	virtual string getName()
	{
		return "London_King";
	};
};

class London_Queen:public Character
{
public:
	London_Queen()
	{
		weapon = "knife";
	}
	virtual string getName()
	{
		return "London_Queen";
	};
};

class London_Troll:public Character
{
public:
	London_Troll()
	{
		weapon = "Axe";
	}
	virtual string getName()
	{
		return "London_Troll";
	};
};

class London_Knight:public Character
{
public:
	London_Knight()
	{
		weapon = "sword";
	}	
	virtual string getName()
	{
		return "London_Knight";
	};
};

class London_Archer:public Character
{
public:
	London_Archer()
	{
		weapon = "Bow";
	}
	virtual string getName()
	{
		return "London_Archer";
	};
};

//************ 以上是產品類別 ************//