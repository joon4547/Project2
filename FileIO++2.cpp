#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//파일 읽기 준비
	ifstream in("a.txt", ios::binary);
	string s;

	int x;
	if (in.is_open()) {
		in.read((char*)(&x), 4);
		cout << hex << x << endl;
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	return 0;
}