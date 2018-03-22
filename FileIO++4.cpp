#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//파일 읽기 준비
	ifstream in("a.txt");
	char buf[100];

	if (in.is_open()) {
		while (!in.eof()) {
			//한 줄 씩 최대 100자 까지 읽어들인다.
			in.getline(buf, 100);
			cout << buf << endl;
		}
	}
	else {
		cout << "파일을 찾을 수 없습니다" << endl;
	}

	return 0;
}