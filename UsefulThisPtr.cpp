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
		this->num1 = num1;	//this->num1 �� �ɹ�������, num1�� �Ű������� �ǹ��Ѵ�. �Ű����� num1�� ���ؼ� ���޵� ���� �ɹ����� num1�� ����ȴ�.
		this->num2 = num2;
	}
	/*
	TwoNumber(int num1, int num2)
		:num1(num1), num2(num2)				//�̴ϼȶ������� this�����Ϳ� ��� �Ұ�. 
	{
		//empty
	}
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;		//this�����͸� ��������ν�, �ɹ������� �������� ��Ȯ�� �Ͽ���. �׷��� �Ϲ������� �̷��� ��쿡�� This����Ʈ�� �����ؼ� ǥ���Ѵ�.
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}