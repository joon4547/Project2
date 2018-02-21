#include <iostream>

using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl; //객체 생성시 실제로 생성자가 호출.
	}
};


int main(void)
{
	AAA ob1;
	return 0;
}