#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*파일 전체 읽기*/
int main()
{
	//파일 읽기 준비
	ifstream in("a.txt");
	string s;

	if (in.is_open()) {

		//파일 위치 지정자를 파일 끝으로 옮긴다.
		in.seekg(0, ios::end);
		
		//그리고 그 위치를 읽는다. (파일의 크기)
		//tellg 함수는 위치 지정자의 시작저므로부터의 위치를 반환
		//지금은 끝으로 이동되있어서 파일의 크기(바이트 단위)로 반환.
		//문자열에 그 만큼의 크기를 할당해줌.
		int size = in.tellg();

		//그 크기의 문자열을 할당한다.
		s.resize(size);

		//위치 지정자를 다시 파일 맨 앞으로 옮긴다.
		//파일을 읽어야 하는데 파일 위치 지정자를 끝으로 옮겨 놓았기 때문에 이긱 위해서 다시 처음으로 옮겨주어야 한다.
		in.seekg(0, ios::beg);

		//파일 전체 내용을 읽어서 문자열에 저장한다.
		in.read(&s[0], size);

		cout << s << endl;
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	return 0;
}