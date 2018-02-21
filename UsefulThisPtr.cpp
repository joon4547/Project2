#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;	//this->num1 은 맴버변수를, num1은 매개변수를 의미한다. 매개변수 num1을 통해서 전달된 값이 맴버변수 num1에 저장된다.
		this->num2 = num2;
	}
	/*
	TwoNumber(int num1, int num2)
		:num1(num1), num2(num2)				//이니셜라이져는 this포인터에 사용 불가. 
	{
		//empty
	}
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;		//this포인터를 사용함으로써, 맴버변수에 접근함을 명확히 하였다. 그러나 일반적으로 이러한 경우에는 This포인트를 생락해서 표현한다.
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}