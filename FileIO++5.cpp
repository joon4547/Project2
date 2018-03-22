#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//파일에 쓰기
int main(void)
{
	//파일 쓰기 준비
	//ofstream은 열려는 파일이 존재하지 않으면 해당 해당파일을 생성하고 열게 됩니다.
	//특별이 설정을 하지 않는다면 해당 파일 내용이 다 지워지고 새로운 내용으로 덮어 씌어지게 됩니다.
	ofstream out("test.txt");

	string s;
	if (out.is_open()) {
		out << "이걸 쓰자~~";
	}

	return 0;
}