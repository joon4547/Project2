#include <iostream>
using namespace std;

int main(void)
{
	int num = 10;
	int & ref = num;

	cout << num << endl;
	cout << ref << endl;

	system("pause");
	return 0;
}