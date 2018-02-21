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
	Person * ptr1 = new Student();  //Student는 Person 을 상속함으로 Person형 포인터 변수는 Student 객체를 가리킬 수 있다.
	Person * ptr2 = new PartTimeStudent(); // PartTimeStudent는 Person을 간접 상속하므로, Person형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있다.
	Student * ptr3 = new PartTimeStudent();		//PartTimeStudent는 Student를 상속하므로, Student형 포인터 변수는 PartTimeStudent객체를 가리킬 수 있다.
	ptr1 ->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
	
}