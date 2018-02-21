#include <iostream>
using namespace std;

class AAA  //AAA obj1;
{
public:
	AAA()
	{
		cout << "empty object" << endl; //��ü ������ ������ �����ڰ� ȣ��Ǵ��� Ȯ���ϱ����ؼ� ������ ��¹�.
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB  //BBB obj2(obj1, 20);
{
private:
	AAA &ref;		//�����ڰ� �ɹ������� ����Ǿ���. ���� �̴ϼȶ������� ���ؼ� �ʱ�ȭ�� �ؾ��Ѵ�.
	const int &num; //const�����ڰ� ����Ǿ���. ���� �̴ϼȶ������� ���ؼ� ������ ����ε� �ʱ�ȭ�� �����ϴ�.

public:
	BBB(AAA &r, const int &n)
		:ref(r), num(n)			//�����ڵ��� �̴ϼȶ������� ���� �ʱ�ȭ�� ����.
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

//�̴ϼȶ������� Ư¡�� ����Լ��� �����ڸ� ������ �� �ְ� �մϴ�