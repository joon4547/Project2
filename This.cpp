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
	ThisFunc * ptr = TF.ThisPoint();   //��ȯ�� this�� ptr�� ����. �̶� this�� ThisFunc�� �������̹Ƿ� ThisFunc�� ������ ������ �����ؾ� ��,
	cout << ptr << endl;  //ptr�� ����� �ּҰ� ���
	ptr->ShowPoint(); //ptr�� ����Ű�� ��ü�� SHowPoint�Լ��� ȣ��.

	system("pause");
	return 0;
}
//����� �� ����� ���� ���´�.

//This �����ʹ� �ش� Ŭ������ ������ ���� �ּҰ��̴�.