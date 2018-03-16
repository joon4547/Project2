#include <iostream>
using namespace std;

class Test
{
	char c;

public:
	Test(char _c)
	{
		c = _c;
			cout << "생성자 호출" << c << endl;
	}
	~Test()
	{
		cout << "소멸자 호출" << c << endl;
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