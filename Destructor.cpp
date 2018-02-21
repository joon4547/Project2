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
		name = new char[len];					//동적할당 
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()									//소멸자
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