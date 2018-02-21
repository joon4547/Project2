#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num = " << num << ", ";
		cout << "address= " << this << endl;
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple * GetThisPointer()
	{
		return this;		//this를 반환한다. 문장을 실행하는 객체의 포인터를 반환하라는 뜻. 반환형도 SoSimple* 형으로 선언 되어 있음.
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple * ptr1 = sim1.GetThisPointer(); //객체 sim1에 의해 반환된 this를 ptr1에 저장하고 있다. 이떄 this는 Sosimple의 포인터이므로 SoSimple형 포인터 변수에 저장해야 됨.
	cout << ptr1 << ", ";					//ptr1에 저장된 주소값 출력
	ptr1->ShowSimpleData();					//ptr1이 가리키는 객체의 ShowSimpleData 함수를 호출하고있다.

	SoSimple sim2(200);
	SoSimple * ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}

//소스코드와 실행결과를 통해서 this는 객체 자신의 주소 값을 의미한다는 사실을 확인 및 이해했을 것이다.
//이렇듯 this포인터는 그 주소 값과자료형이 정해져 있지 않은 포인터이다.
//0x12FF번지에 할당된 SoSimple객체 내에서 사용되면, this 는 SoSimple형의 포인터이면서 그 값은 0x12ff를 의미하게되고,
//0x52AA번지에 할당된 SoComplex객체 내에서 사용이 되면, this는 SoComplex형의 포인터이면서 그 값은 0x52AA를 의미하게 된다.