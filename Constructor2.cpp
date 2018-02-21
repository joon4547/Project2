#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc1(); //함수의 원형 선언 ()친거는 원형선언에만 사용하기로 약속.
	SimpleClass mysc = sc1(); //함수를 호출하여, 이때 반환되는 객체의 값으로 mycs 객체를 초기화 하고 있다.
	mysc.ShowData();
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}