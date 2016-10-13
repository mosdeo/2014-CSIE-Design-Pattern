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
	cout << "�]�p�Ҧ� HW4 �u�t�Ҧ� 60132057A �L����" << endl;
	cout << endl;

	//*** �H�U��while() �̩ۨ�o�ǫŧi ***//
	string KeyinOrder; //��J�����R�O
	vector<string> vs; //�s�� ����,�r�� ���Ӷ����r��}�C

	while(cout << "�п�J:"<<endl && getline(cin,KeyinOrder))
	{
		string City, strCharacter;

		//�إߨ�Ӥ��P���u�t
		CharacterFactory* LondonFactory = new LondonCharacterFactory();
		CharacterFactory* ParisFactory = new ParisCharacterFactory();

		Convert::Tolower(KeyinOrder); //Anti stupid ��j�g
		istringstream iss(KeyinOrder); //������
		copy(istream_iterator<string>(iss),istream_iterator<string>(),back_insert_iterator<vector<string>>(vs));

		for(vector<string>::iterator it=vs.begin();it!=vs.end();it++)
		{//�ϥ�STL���z��pointer, ���B(*it)�����O��string

			if(Convert::Tolower("CPP") == *it ||Convert::Tolower("Java") == *it || Convert::Tolower("game") == *it)
				continue;//����

			if(Convert::Tolower("London") == *it ||	Convert::Tolower("Paris") == *it)
				City = *it;//�s�U��������

			if(Convert::Tolower("King") == *it || Convert::Tolower("Queen") == *it || Convert::Tolower("Troll") == *it ||
			   Convert::Tolower("Knight") == *it || Convert::Tolower("Archer") == *it )
			   strCharacter = *it;//�s�U�Z�h����

			if(Convert::Tolower("exit") == *it)
			{
				delete LondonFactory;
				delete ParisFactory;
				exit(8);//�����{��
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