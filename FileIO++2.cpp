#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//���� �б� �غ�
	ifstream in("a.txt", ios::binary);
	string s;

	int x;
	if (in.is_open()) {
		in.read((char*)(&x), 4);
		cout << hex << x << endl;
	}
	else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}

	return 0;
}