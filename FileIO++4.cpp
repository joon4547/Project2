#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//���� �б� �غ�
	ifstream in("a.txt");
	char buf[100];

	if (in.is_open()) {
		while (!in.eof()) {
			//�� �� �� �ִ� 100�� ���� �о���δ�.
			in.getline(buf, 100);
			cout << buf << endl;
		}
	}
	else {
		cout << "������ ã�� �� �����ϴ�" << endl;
	}

	return 0;
}