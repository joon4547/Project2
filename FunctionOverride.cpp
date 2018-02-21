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
	tptr->MyFunc();			//�� ������ �� ������ �̿��ؼ� MyFunc�Լ��� ȣ���ϰ� �ִ�.
							//���� �������� �������̵� �� Third Ŭ������ MyFunc�� ȣ���.
	delete tptr;
	
	//////////���� ���� ����

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

//������ ���� �ش��ϴ� Ŭ������ ���ǵ� �ɹ����� ������ ����.
//C++�����Ϸ��� �����͸� �̿��� ������ ���ɼ� ���θ� �Ǵ��� ��, �������� �ڷ����� �������� �Ǵ�����, ���� ����Ű�� ��ü�� �ڷ����� �������� �Ǵ����� �ʴ´�.