#include <iostream>
#include <cstring>
using namespace std;
#pragma warning ( disable : 4996 )
class Person
{
private:
	char * name;
	int age;
public:
	Person(char * myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];					//�����Ҵ� 
		strcpy(name, myname);
		age = myage;
	}
	Person()  //�迭 ������ �ʿ��� ������ �߰�.
	{
		name = NULL;
		age = 0;
		cout << "called Person() " << endl;
	}
	void ShowPersonInfo(char * myname, int myage) //���ϴ� �����ͷ� �ʱ�ȭ�� ���� ���� �Լ�.
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~Person()									//�Ҹ���
	{
		delete[]name;
		cout << "called destructor! " << endl;
	}
};

int main(void)
{
	Person parr[3];
	char namestr[100];
	char * strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)		//�ݺ��� �ȿ����� �Է��� �ް� ��ü �ʱ�ȭ.
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].ShowPersonInfo(strptr, age);
	}
	for (int i = 0; i < 3; i++)
	{
		parr[i].ShowPersonInfo();
	}
	//parr[0].ShowPersonInfo();
	//parr[1].ShowPersonInfo();
	//parr[2].ShowPersonInfo();
	return 0;
	
				
	//Person man1("Lee dong woo", 29);
	//Person man2("Shin Ho Joon ", 28);
	//man1.ShowPersonInfo();
	//man2.ShowPersonInfo();
	//return 0;
}