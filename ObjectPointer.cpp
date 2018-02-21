#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public :
	void Study() { cout << "study" << endl; }
};

class PartTimeStudent : public Student
{
public:
	void Work() { cout << "Work" << endl; }
};

int main(void)
{
	Person * ptr1 = new Student();  //Student�� Person �� ��������� Person�� ������ ������ Student ��ü�� ����ų �� �ִ�.
	Person * ptr2 = new PartTimeStudent(); // PartTimeStudent�� Person�� ���� ����ϹǷ�, Person�� ������ ������ PartTimeStudent ��ü�� ����ų �� �ִ�.
	Student * ptr3 = new PartTimeStudent();		//PartTimeStudent�� Student�� ����ϹǷ�, Student�� ������ ������ PartTimeStudent��ü�� ����ų �� �ִ�.
	ptr1 ->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
	
}