#include <iostream>
using namespace std;

class Test
{
	char c;

public:
	Test(char _c)
	{
		c = _c;
			cout << "������ ȣ��" << c << endl;
	}
	~Test()
	{
		cout << "�Ҹ��� ȣ��" << c << endl;
	}
};

void simple_function()
{
	Test b('b');
}
int main()
{
	Test a('a');
	simple_function();
}