#include <iostream>
#include <sstream>
using namespace std;

//���ڿ� ��Ʈ��

int main()
{
	istringstream ss("123");
	int x;
	ss >> x;

	cout << "�Է� ���� ������ ::" << x << endl;

	return 0;
}