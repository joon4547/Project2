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
	Person()  //배열 생성시 필요한 생성자 추가.
	{
		name = NULL;
		age = 0;
		cout << "called Person() " << endl;
	}
	void ShowPersonInfo(char * myname, int myage) //원하는 데이터로 초기화를 목적 정의 함수.
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()									//소멸자
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

	for (int i = 0; i < 3; i++)		//반복문 안에서의 입력을 받고 객체 초기화.
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
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