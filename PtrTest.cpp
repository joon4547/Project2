#include <iostream>

using namespace std;

int main(void)
{
	int num = 10;
	int * ptr = &num;	//ptr������ ������ ����� �ּҰ����� �̵��ؼ� �� ���� ������ش�.

	cout << num << endl;
	cout << *ptr << endl;

	system("pause");
	return 0;
}

//������ ������ * �� ��ԵǸ� ptr�� ��� num�� �ּҰ����� �̵��ؼ� �� �ȿ� �ִ� ���� ������شٴ� ��.
