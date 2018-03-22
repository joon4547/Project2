#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//파일 읽기 준비
	ifstream in("a.txt");

	string s;

	if (in.is_open()) {
		in >> s;
		cout << "입력 받은 문자열::" << s << endl;
	}
	else{
		cout << "파일을 찾을 수 없습니다." << endl;
	}
	return 0;
}
