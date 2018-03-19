#include <iostream>
using namespace std;

class A
{
private:
	int x;

public:
	A(int c) : x(c) {}
	
	
	int& access_x() { return x; }//래퍼런스를 리턴하는 함수	
	int get_x() { return x; }//값을 리턴하는 함수.

	void show_x() { cout << x << endl; }
};

int main(void)
{
	A a(5);
	a.show_x(); //5

	int& c = a.access_x();  
	c = 4;
	a.show_x(); //4

	int d = a.access_x();
	d = 3;
	//int 변수에 'x의 별명'을 전달했다.
	//d가 그냥 int변수이므로 값의 복사가 일어나 d에는 x의 값(4)이 들어가게 된다.
	//당연히 d는 x의 별명이 아닌 또 다른 독립변수이기에 d=3을하면 d값만 바뀌고 x의 값은 그대로 4가 출력된다.
	a.show_x(); //4
	cout << d << endl; //3

	//아래는 오류 , 이유는 래퍼런스가 아닌 타입을 리턴하는 경우는 '값'의 복사가 이루어지기 떄문에
	//임시 객체가 생성되는데, 임시 객체의 레퍼런스를 가질 수 없기 떄문이다.(임시객체는 문장이 끝나게 되면 소멸한다.)
/*	int& e = a.get_x();
	e = 2;
	a.show_x()*/;

	int f = a.get_x();
	f = 1;
	a.show_x(); //4
	cout << "f :" << f << endl;

	//래퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는원래 변수로 치환해도 됀다.
	a.access_x() = 3; 
	a.show_x();
	//a.x = 3;과 동일 문장
}