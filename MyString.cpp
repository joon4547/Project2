#include <iostream>

using namespace std;

class MyString
{
private:
	char * string_content; //문자열 데이터를 가리키는 포인터.
	int string_length;  //문자열 길이.

public:
	//문자 하나로 생성
	MyString(char c);
	//문자열로 부터 생성
	//내부 변수의 내용을 바꾸지 않거나, 상수 함수들만 호출하는 함수들은 왠만하면 const함수로 정의해주는게 좋다.
	MyString(const char * str);
	//복사 생성자
	MyString(const MyString &str);
	//소멸자
	~MyString();

	int length() const;

	void print();
	void println();
};

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
}

MyString::MyString(const char * str)
{
	string_length = strlen(str);
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str[i];
}

MyString::MyString(const MyString &str)
{
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}

//내부 변수의 내용을 바꾸지 않거나 상수 함수들만 호출하는 함수들은 왠만하면 const함수로 정의해 주는 것이 좋다.
int MyString::length() const
{
	return string_length;
}

void MyString::print()
{
	for (int i = 0; i != string_length; i++)
	{	cout << string_content[i];	}
}

void MyString::println()
{
	for (int i = 0; i != string_length; i++)
		cout << string_content[i];

	cout << endl;
}

MyString::~MyString()
{
	delete[]string_content;
}

int main()
{
	MyString str1("Exicon world!");
	MyString str2(str1);

	str1.println();
	str2.println();
}
