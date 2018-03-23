#include <iostream>
#include <sstream>
using namespace std;

//문자열 스트림

int main()
{
	istringstream ss("123");
	int x;
	ss >> x;

	cout << "입력 받은 데이터 ::" << x << endl;

	return 0;
}