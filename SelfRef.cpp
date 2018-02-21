#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;

public:
	SelfRef(int n) : num(n) //3,5,6,8
	{
		cout << "객체 생성" << endl;
	}
	SelfRef& Adder(int n)	//2//1//2 // 함수 Adder에서는 선언된 반환형과 반환의 내용을 함께 봐야한다.
	{
		num += n;
		return *this; //반환의 내용이 *this인데, 이는 이 문장을 실행하는 객체 자신의 포인터가 아닌, 객체 자신을 반환하겟다는 뜻이다.
					  //반환형이 참조형 SelfRef&으로 선언되었다. 따라서 객체 자신을 참조할 수 있는 "참조의 정보(참조 값)"가 반환된다. 
	}
	SelfRef& ShowTwoNumber() //13행에 정의된 함수와 마찬가지로 객체 자신을 참조할 수 있는 참조값을 반환하도록 되어있다.
	{
		cout << num << endl;
		return *this;
	}
};
int main(void)
{
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);  //객체 obj의 Adder함수를 호출하였다. 그런데 이 함수는 객체 자신의 참조 값을 반환한다.
								  //즉, 객체 obj의 참조 값을 반환한다. 따라서 참조자 ref는 객체 obj를 참조하게 된다.
	obj.ShowTwoNumber();	//29행에서 일어나는 일의 확인을 위해서 객체에 저장되어 있는 값을 출력하고있다.
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	//먼저 ref의 Adder함수가 호출된다.
															//Adder함수는 참조 값을 반홤하므로, 반환된 참조 값을 이용해서 다시 ShowTwoNumber 함수를 호출하게 된다.
															//마찬가지로 반환되는 참조 값을 이용해 다시 Adder 함수를 호출하고, 또 이어서 ShowTwoNumber 함수를 호출한다.
															//두 함수Adder와 ShowTwoNmber가 객체의 참조값을 반환하기 때문에 구성이 가능한 문장이다.
	return 0;

}


