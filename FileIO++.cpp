#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//���� �б� �غ�
	ifstream in("a.txt");

	string s;

	if (in.is_open()) {
		in >> s;
		cout << "�Է� ���� ���ڿ�::" << s << endl;
	}
	else{
		cout << "������ ã�� �� �����ϴ�." << endl;
	}
	return 0;
}
