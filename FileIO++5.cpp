#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//���Ͽ� ����
int main(void)
{
	//���� ���� �غ�
	//ofstream�� ������ ������ �������� ������ �ش� �ش������� �����ϰ� ���� �˴ϴ�.
	//Ư���� ������ ���� �ʴ´ٸ� �ش� ���� ������ �� �������� ���ο� �������� ���� �������� �˴ϴ�.
	ofstream out("test.txt");

	string s;
	if (out.is_open()) {
		out << "�̰� ����~~";
	}

	return 0;
}