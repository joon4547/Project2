#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//이진수로 읽기
int main()
{
	//파일 읽기 준비
	ifstream in("a.txt", ios::binary);
	string s;

	char e[10];

	//int x;
	if (in.is_open()) 
	{
		//int 변수를 마치 4바이트 char 배열이라 생각하게 해서 이를 전달함.
		//두번째 인자로 반드시 몇 바이트를 읽을 지 전달.
		//in.read((char*)(&x), 4);
		in.read(e, 10);
		cout << hex << e << endl;
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	return 0;
}