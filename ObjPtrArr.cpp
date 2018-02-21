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
	Person * parr[3];	//������ �迭 ����. ��ü�� �ּ� �� 3���� ������ �� �ִ�.
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;
		parr[i] = new Person(namestr, age);	//��ü�� �����ؼ�, �� ��ü�� �ּ� ���� �迭�� ����.
	}
	for (int i = 0; i < 3; i++)
		parr[i]->ShowPersonInfo();	
	for (int i = 0; i < 3; i++)	//�� 3ȸ�� ���� new������ ����������, �� 3ȸ�� ���� delete������ ����.
		delete parr[i];	
	return 0;

}

