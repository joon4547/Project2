#include <iostream>
#include <cstring>
using namespace std;
#pragma warning ( disable : 4996 )
class Person		//기초클라스
{
private :
	char * name;
public:
	Person(char * myname)
	{
		name = new char[strlen(myname) + 1]; //UnivStudent의 기초 클래스인 Person 클래스의소멸자는 생성자에서 할당한 메모리 공간을 햊하도록 정의했다.
		strcpy(name, myname);
	}
	~Person()
	{
		delete[] name;						//UnivStudent의 기초 클래스인 Person 클래스의소멸자는 생성자에서 할당한 메모리 공간을 햊하도록 정의했다.
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
		//UnivStudent의 소멸자에서도 자신의 생성자에서 할당한 메모리 공간에 대한 해제만을 책임지고있다. 어차피 기초 클래스의 소멸자가 호출이 되면서 기초 클래스의 생성자에서 할당한 메모리 공간을 해제하기 때문
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~UnivStudent()
	{	//UnivStudent의 소멸자에서도 자신의 생성자에서 할당한 메모리 공간에 대한 해제만을 책임지고있다. 어차피 기초 클래스의 소멸자가 호출이 되면서 기초 클래스의 생성자에서 할당한 메모리 공간을 해제하기 때문
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