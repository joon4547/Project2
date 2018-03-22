#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//string 에 정의된 getlien사용.
int main()
{
	//파일 읽기 준비
	ifstream in("a.txt");
	char buf[100];

	if (in.is_open()) {
		while (!in.eof()) {
			//한 줄 씩 최대 100자 까지 읽어들인다.
			//buf에 최대 100글자 까지 입력 받는다. 
			in.getline(buf, 100);
			//아래처럼 하면 마침표가 나올 때 까지 입력받게 된다.
			//in.getline(buf, '.'); 
			cout << buf << endl;
		}
	}
	else {
		cout << "파일을 찾을 수 없습니다" << endl;
	}

	return 0;
}

//주의할 점은 getline함수는 개행 문자(혹은 지정한 문자)가 나오기 전에 지정한 버퍼의 크기가 다 차게 된다면 failbit를 키게 됩니다.
//따라서 버퍼의 크기를 너무 작게 만든다면 정상적으로 데이터를 받을 수 없게 됩니다.
//따라서 getline을 사용하기 전에 이와 같은 조건을 꼭 확인해야 합니다.