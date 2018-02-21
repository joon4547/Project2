#include <iostream>
#include <cstring>
using namespace std;
#pragma warning ( disable : 4996 )
namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER};	//열거형으로 switch문 사용.

	void SHowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
}
class NameCard
{
private:
	char * name;	//문자열 길이에 맞는 동적할당을 위한 포인터.
	char * company;
	char * phone;
	int position;	//enum 사용

public:
	NameCard(char * _name, char * _company, char * _phone, int pos)	//생성자
		:position(pos) //이니셜라이져를 통한 초기화
	{
		name = new char[strlen(_name) + 1];			//길이에 맞는 공간 생성
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);						
		strcpy(company, _company);
		strcpy(phone, _phone);
	}
	void ShowNameCardInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "회사 : " << company << endl;
		cout << "전화번호 : " << phone << endl;
		/*cout << "직급 : " << position << endl;*/
		cout << "직급 : "; COMP_POS::SHowPositionInfo(position);
		cout << endl;
	}
	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]phone;
	}	
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010 - 1111 - 2222", COMP_POS::CLERK);		//사원
	NameCard manSENIOR("Hong", "OrangeEng", "010 - 3333 - 4444", COMP_POS::SENIOR);	//주임
	NameCard manASSIST("Kim", "SoGoodComp", "010 - 5555 - 6666", COMP_POS::ASSIST);	//대리
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manASSIST.ShowNameCardInfo();

	return 0;
}