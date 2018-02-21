#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3)
	{	}
};

class Derived : protected Base {}; //empty;

int main(void)
{
	Derived drv;
	cout << drv.num3 << endl; //컴파일 에러발생
	return 0;
}

//Base클래스를 Protected로 상속했기때문에 컴파일 에러 발생
//protected로 상속했기 때문에 public 멤버변수인 num3는 Derived 클래스에서 protected멤버가 된다. 
//그리고 이로 인해서 외부에서는 접근이 불가능한 멤버가 된 것이다.