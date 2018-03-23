#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ofstream ������ �����ε� �ϱ�
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
	//���� ���� �غ�
	ofstream out("test.txt");

	Human h("�����", 60);
	out << h << endl;

	return 0;
}