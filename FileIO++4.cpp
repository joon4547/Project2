#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//string �� ���ǵ� getlien���.
int main()
{
	//���� �б� �غ�
	ifstream in("a.txt");
	char buf[100];

	if (in.is_open()) {
		while (!in.eof()) {
			//�� �� �� �ִ� 100�� ���� �о���δ�.
			//buf�� �ִ� 100���� ���� �Է� �޴´�. 
			in.getline(buf, 100);
			//�Ʒ�ó�� �ϸ� ��ħǥ�� ���� �� ���� �Է¹ް� �ȴ�.
			//in.getline(buf, '.'); 
			cout << buf << endl;
		}
	}
	else {
		cout << "������ ã�� �� �����ϴ�" << endl;
	}

	return 0;
}

//������ ���� getline�Լ��� ���� ����(Ȥ�� ������ ����)�� ������ ���� ������ ������ ũ�Ⱑ �� ���� �ȴٸ� failbit�� Ű�� �˴ϴ�.
//���� ������ ũ�⸦ �ʹ� �۰� ����ٸ� ���������� �����͸� ���� �� ���� �˴ϴ�.
//���� getline�� ����ϱ� ���� �̿� ���� ������ �� Ȯ���ؾ� �մϴ�.