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
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~Person()									//�Ҹ���
	{
		delete []name;
		cout << "called destructor! " << endl;

	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Shin Ho Joon ", 28);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}