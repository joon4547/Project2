#include <iostream>
#include <cstring>
using namespace std;
#pragma warning ( disable : 4996 )
namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER};	//���������� switch�� ���.

	void SHowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
}
class NameCard
{
private:
	char * name;	//���ڿ� ���̿� �´� �����Ҵ��� ���� ������.
	char * company;
	char * phone;
	int position;	//enum ���

public:
	NameCard(char * _name, char * _company, char * _phone, int pos)	//������
		:position(pos) //�̴ϼȶ������� ���� �ʱ�ȭ
	{
		name = new char[strlen(_name) + 1];			//���̿� �´� ���� ����
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);						
		strcpy(company, _company);
		strcpy(phone, _phone);
	}
	void ShowNameCardInfo()
	{
		cout << "�̸� : " << name << endl;
		cout << "ȸ�� : " << company << endl;
		cout << "��ȭ��ȣ : " << phone << endl;
		/*cout << "���� : " << position << endl;*/
		cout << "���� : "; COMP_POS::SHowPositionInfo(position);
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
	NameCard manClerk("Lee", "ABCEng", "010 - 1111 - 2222", COMP_POS::CLERK);		//���
	NameCard manSENIOR("Hong", "OrangeEng", "010 - 3333 - 4444", COMP_POS::SENIOR);	//����
	NameCard manASSIST("Kim", "SoGoodComp", "010 - 5555 - 6666", COMP_POS::ASSIST);	//�븮
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manASSIST.ShowNameCardInfo();

	return 0;
}