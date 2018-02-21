#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc() { cout << "FirstFunc" << endl; }
};

class Seconed : public First
{
public:
	void MyFunc() { cout << "SeconedFunc" << endl; }
};

class Third : public Seconed
{
public:
	void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main(void)
{
	Third * tptr = new Third();
	Seconed * sptr = tptr;
	First * fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();			//각 포인터 형 변수를 이용해서 MyFunc함수를 호출하고 있다.
							//가장 마지막에 오버라이딩 된 Third 클레스의 MyFunc가 호출됨.
	delete tptr;
	
	//////////접근 가능 정의

	//tptr -> FirstFunc();  o
	//tptr->SeconedFunc();	o
	//tptr->ThirdFunc();	o	

	//sptr->FirstFunc();	o
	//sptr->SeconedFunc();	o
	///*sptr->ThirdFunc();*/x

	//fptr->FirstFunc();	o
	///*fptr->SeconedFunc();x
	//fptr->ThirdFunc();*/	x

	return 0;
}

//포인터 형에 해당하는 클래스에 정의된 맴버에만 접근이 가능.
//C++컴파일러는 포인터를 이용한 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.