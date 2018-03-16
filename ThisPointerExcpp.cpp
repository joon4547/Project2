#include <iostream>
#include <string>
using namespace std;

class same {
private:
	int num1;
	int num2;
public:
	void show();
	same(int, int);
	void equal1(int, int);
	void equal2(int, int);
};

void same::show() {
	cout << "num1 : " << num1 << "  num2 : " << num2 << endl;
}

same::same(int a, int b) : num1(a), num2(b)
{
}

void same::equal1(int num1, int num2) {
	this->num1 = num1;
	this->num2 = num2;
}

void same::equal2(int num1, int num2) {
	num1 = num1;
	num2 = num2;
}

void main() {
	same x(1, 2);
	same y(3, 4);

	x.equal1(10, 20);
	x.show();

	y.equal2(30, 40);
	y.show();
}