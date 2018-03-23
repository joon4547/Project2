#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ofstream 연산자 오버로딩 하기
class Human
{
	string name;
	int age;

public:
	Human(const string& name, int age) : name(name), age(age) {}
	string get_info() {
		return "Name :: " + name + " / Age :: " + to_string(age);
	}

	friend ofstream& operator << (ofstream& o, Human& h);	
};

ofstream& operator << (ofstream& o, Human& h) {
	o << h.get_info();
	return o;
}

int main()
{
	//파일 쓰기 준비
	ofstream out("test.txt");

	Human h("이재범", 60);
	out << h << endl;

	return 0;
}