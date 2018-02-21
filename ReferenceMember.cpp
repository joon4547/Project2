#include <iostream>
using namespace std;

class AAA  //AAA obj1;
{
public:
	AAA()
	{
		cout << "empty object" << endl; //객체 생성시 실제로 생성자가 호출되는지 확인하기위해서 삽입한 출력문.
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB  //BBB obj2(obj1, 20);
{
private:
	AAA &ref;		//참조자가 맴버변수로 선언되었다. 따라서 이니셜라이져를 통해서 초기화를 해야한다.
	const int &num; //const참조자가 선언되었다. 따라서 이니셜라이져를 통해서 정수형 상수로도 초기화가 가능하다.

public:
	BBB(AAA &r, const int &n)
		:ref(r), num(n)			//참조자들을 이니셜라이져를 통한 초기화를 해줌.
	{	//empty constructor body
	}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}

//이니셜라이저의 특징은 멤버함수로 참조자를 선언할 수 있게 합니다