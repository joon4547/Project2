#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;

public:
	SelfRef(int n) : num(n) //3,5,6,8
	{
		cout << "��ü ����" << endl;
	}
	SelfRef& Adder(int n)	//2//1//2 // �Լ� Adder������ ����� ��ȯ���� ��ȯ�� ������ �Բ� �����Ѵ�.
	{
		num += n;
		return *this; //��ȯ�� ������ *this�ε�, �̴� �� ������ �����ϴ� ��ü �ڽ��� �����Ͱ� �ƴ�, ��ü �ڽ��� ��ȯ�ϰٴٴ� ���̴�.
					  //��ȯ���� ������ SelfRef&���� ����Ǿ���. ���� ��ü �ڽ��� ������ �� �ִ� "������ ����(���� ��)"�� ��ȯ�ȴ�. 
	}
	SelfRef& ShowTwoNumber() //13�࿡ ���ǵ� �Լ��� ���������� ��ü �ڽ��� ������ �� �ִ� �������� ��ȯ�ϵ��� �Ǿ��ִ�.
	{
		cout << num << endl;
		return *this;
	}
};
int main(void)
{
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);  //��ü obj�� Adder�Լ��� ȣ���Ͽ���. �׷��� �� �Լ��� ��ü �ڽ��� ���� ���� ��ȯ�Ѵ�.
								  //��, ��ü obj�� ���� ���� ��ȯ�Ѵ�. ���� ������ ref�� ��ü obj�� �����ϰ� �ȴ�.
	obj.ShowTwoNumber();	//29�࿡�� �Ͼ�� ���� Ȯ���� ���ؼ� ��ü�� ����Ǿ� �ִ� ���� ����ϰ��ִ�.
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();	//���� ref�� Adder�Լ��� ȣ��ȴ�.
															//Adder�Լ��� ���� ���� ���c�ϹǷ�, ��ȯ�� ���� ���� �̿��ؼ� �ٽ� ShowTwoNumber �Լ��� ȣ���ϰ� �ȴ�.
															//���������� ��ȯ�Ǵ� ���� ���� �̿��� �ٽ� Adder �Լ��� ȣ���ϰ�, �� �̾ ShowTwoNumber �Լ��� ȣ���Ѵ�.
															//�� �Լ�Adder�� ShowTwoNmber�� ��ü�� �������� ��ȯ�ϱ� ������ ������ ������ �����̴�.
	return 0;

}


