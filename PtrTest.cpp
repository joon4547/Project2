#include <iostream>

using namespace std;

int main(void)
{
	int num = 10;
	int * ptr = &num;	//ptr포인터 변수에 저장된 주소값으로 이동해서 그 값을 출력해준다.

	cout << num << endl;
	cout << *ptr << endl;

	system("pause");
	return 0;
}

//포인터 변수에 * 를 찍게되면 ptr에 담긴 num의 주소값으로 이동해서 그 안에 있는 값을 출력해준다는 것.
