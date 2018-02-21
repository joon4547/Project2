#include <iostream>

using namespace std;

class ThisFunc {
private:
	int num;
public:
	ThisFunc * ThisPoint()
	{
		return this;  
	}
	void ShowPoint()
	{
		cout << &num << endl;
	}
};

int main(void)
{
	ThisFunc TF;
	ThisFunc * ptr = TF.ThisPoint();   //반환된 this를 ptr에 저장. 이때 this는 ThisFunc의 포인터이므로 ThisFunc의 포인터 변수에 저장해야 됨,
	cout << ptr << endl;  //ptr에 저장된 주소값 출력
	ptr->ShowPoint(); //ptr이 가리키는 객체의 SHowPoint함수를 호출.

	system("pause");
	return 0;
}
//결과는 두 출력이 같게 나온다.

//This 포인터는 해당 클래스의 포인터 이자 주소값이다.