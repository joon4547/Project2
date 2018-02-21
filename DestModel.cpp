#include <iostream>
#include <cstring>
using namespace std;
#pragma warning ( disable : 4996 )
class Person		//����Ŭ��
{
private :
	char * name;
public:
	Person(char * myname)
	{
		name = new char[strlen(myname) + 1]; //UnivStudent�� ���� Ŭ������ Person Ŭ�����ǼҸ��ڴ� �����ڿ��� �Ҵ��� �޸� ������ �Y�ϵ��� �����ߴ�.
		strcpy(name, myname);
	}
	~Person()
	{
		delete[] name;						//UnivStudent�� ���� Ŭ������ Person Ŭ�����ǼҸ��ڴ� �����ڿ��� �Ҵ��� �޸� ������ �Y�ϵ��� �����ߴ�.
	}
	void WhatYourName() const
	{
		cout << "My name is" << name << endl;
	}
};

class UnivStudent : public Person
{
private:
	char * major;
public:
	UnivStudent(char * myname, char *mymajor)
		:Person(myname)
	{
		//UnivStudent�� �Ҹ��ڿ����� �ڽ��� �����ڿ��� �Ҵ��� �޸� ������ ���� �������� å�������ִ�. ������ ���� Ŭ������ �Ҹ��ڰ� ȣ���� �Ǹ鼭 ���� Ŭ������ �����ڿ��� �Ҵ��� �޸� ������ �����ϱ� ����
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~UnivStudent()
	{	//UnivStudent�� �Ҹ��ڿ����� �ڽ��� �����ڿ��� �Ҵ��� �޸� ������ ���� �������� å�������ִ�. ������ ���� Ŭ������ �Ҹ��ڰ� ȣ���� �Ǹ鼭 ���� Ŭ������ �����ڿ��� �Ҵ��� �޸� ������ �����ϱ� ����
		delete[]major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent st1("Kim", "Mathmatics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}