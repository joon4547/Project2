#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//�������� �б�
int main()
{
	//���� �б� �غ�
	ifstream in("a.txt", ios::binary);
	string s;

	char e[10];

	//int x;
	if (in.is_open()) 
	{
		//int ������ ��ġ 4����Ʈ char �迭�̶� �����ϰ� �ؼ� �̸� ������.
		//�ι�° ���ڷ� �ݵ�� �� ����Ʈ�� ���� �� ����.
		//in.read((char*)(&x), 4);
		in.read(e, 10);
		cout << hex << e << endl;
	}
	else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}

	return 0;
}