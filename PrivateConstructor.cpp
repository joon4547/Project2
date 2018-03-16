#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA() : num(0) {}		//public 생성자가 정의됨. 따라서 클래스 외부에서는 이 생성자를 기반으로 객체를 생성해야 한다.
	AAA &CreateInitObj(int n) const	//함수 내에서 , private생성자를 이용해서 AAA객체를 생성 및 반환하고 있다.
	{
		AAA * ptr = new AAA(n);
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
private:
	AAA(int n) : num(n) {}  //num3
};
int main(void)
{
	AAA base;	//디폴트 생성자는 AAA base; 가 선언된 순간에 호출된다. num의 값에는 0이라는 값이 들어가게 될것. 
	base.ShowNum();

	AAA &obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA &obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete &obj1;
	delete &obj2;
	return 0;
}