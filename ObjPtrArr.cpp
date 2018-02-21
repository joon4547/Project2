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
	Person * parr[3];	//포인터 배열 선언. 객체의 주소 값 3개를 저장할 수 있다.
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		parr[i] = new Person(namestr, age);	//객체를 생성해서, 이 객체의 주소 값을 배열에 저장.
	}
	for (int i = 0; i < 3; i++)
		parr[i]->ShowPersonInfo();	
	for (int i = 0; i < 3; i++)	//총 3회에 걸쳐 new연산을 진행했으니, 총 3회에 걸쳐 delete연산을 진행.
		delete parr[i];	
	return 0;

}

