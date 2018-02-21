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
		return this;		//this�� ��ȯ�Ѵ�. ������ �����ϴ� ��ü�� �����͸� ��ȯ�϶�� ��. ��ȯ���� SoSimple* ������ ���� �Ǿ� ����.
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple * ptr1 = sim1.GetThisPointer(); //��ü sim1�� ���� ��ȯ�� this�� ptr1�� �����ϰ� �ִ�. �̋� this�� Sosimple�� �������̹Ƿ� SoSimple�� ������ ������ �����ؾ� ��.
	cout << ptr1 << ", ";					//ptr1�� ����� �ּҰ� ���
	ptr1->ShowSimpleData();					//ptr1�� ����Ű�� ��ü�� ShowSimpleData �Լ��� ȣ���ϰ��ִ�.

	SoSimple sim2(200);
	SoSimple * ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}

//�ҽ��ڵ�� �������� ���ؼ� this�� ��ü �ڽ��� �ּ� ���� �ǹ��Ѵٴ� ����� Ȯ�� �� �������� ���̴�.
//�̷��� this�����ʹ� �� �ּ� �����ڷ����� ������ ���� ���� �������̴�.
//0x12FF������ �Ҵ�� SoSimple��ü ������ ���Ǹ�, this �� SoSimple���� �������̸鼭 �� ���� 0x12ff�� �ǹ��ϰԵǰ�,
//0x52AA������ �Ҵ�� SoComplex��ü ������ ����� �Ǹ�, this�� SoComplex���� �������̸鼭 �� ���� 0x52AA�� �ǹ��ϰ� �ȴ�.