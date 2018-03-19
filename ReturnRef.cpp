#include <iostream>
using namespace std;

class A
{
private:
	int x;

public:
	A(int c) : x(c) {}
	
	
	int& access_x() { return x; }//���۷����� �����ϴ� �Լ�	
	int get_x() { return x; }//���� �����ϴ� �Լ�.

	void show_x() { cout << x << endl; }
};

int main(void)
{
	A a(5);
	a.show_x(); //5

	int& c = a.access_x();  
	c = 4;
	a.show_x(); //4

	int d = a.access_x();
	d = 3;
	//int ������ 'x�� ����'�� �����ߴ�.
	//d�� �׳� int�����̹Ƿ� ���� ���簡 �Ͼ d���� x�� ��(4)�� ���� �ȴ�.
	//�翬�� d�� x�� ������ �ƴ� �� �ٸ� ���������̱⿡ d=3���ϸ� d���� �ٲ�� x�� ���� �״�� 4�� ��µȴ�.
	a.show_x(); //4
	cout << d << endl; //3

	//�Ʒ��� ���� , ������ ���۷����� �ƴ� Ÿ���� �����ϴ� ���� '��'�� ���簡 �̷������ ������
	//�ӽ� ��ü�� �����Ǵµ�, �ӽ� ��ü�� ���۷����� ���� �� ���� �����̴�.(�ӽð�ü�� ������ ������ �Ǹ� �Ҹ��Ѵ�.)
/*	int& e = a.get_x();
	e = 2;
	a.show_x()*/;

	int f = a.get_x();
	f = 1;
	a.show_x(); //4
	cout << "f :" << f << endl;

	//���۷����� �����ϴ� �Լ��� �� �Լ� �κ��� �����ϴ¿��� ������ ġȯ�ص� �´�.
	a.access_x() = 3; 
	a.show_x();
	//a.x = 3;�� ���� ����
}