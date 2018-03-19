#include <iostream>
using namespace std;

class MyString
{
	char * string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length; // ���ڿ� ����

	int memory_capacity; // ���� �Ҵ�� �뷮
public:
	// ���� �ϳ��� ����
	MyString(char c);
	// ���ڿ��� ���� ����
	MyString(const char* str);
	// ���� ������
	MyString(const MyString &str);
	
	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print();
	void println();

	MyString& assign(MyString& str);
	MyString& assign(const char *str);
};

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str)
{
	string_length = strlen(str);
	memory_capacity = string_length;
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

MyString::~MyString()
{
	delete[] string_content;
}

int MyString::length() const
{
	return string_length;
}

void MyString::print()
{
	for (int i = 0; i != string_length; i++)
		cout << string_content[i];
}

void MyString::println()
{
	for (int i = 0; i != string_length; i++)
		cout << string_content[i];

	cout << endl;
}

MyString& MyString::assign(MyString& str)
{
	if (str.string_length > memory_capacity) {
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�. 
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	// �׸��� ���� str.string_length + 1 ~ string_length �κ��� �ʱ�ȭ
	// ��ų �ʿ�� ����. �ֳ��ϸ� �ű� ������ �о������ �ʱ� �����̴�. 
	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char *str)
{
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		// �׷��� �ٽ� �Ҵ��� ����߸� �Ѵ�. 
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}

	string_length = str_length;
	return *this;
}

int MyString::capacity() const
{
	return memory_capacity;
}

void MyString::reserve(int size)
{
	if (size > memory_capacity) {
		char *prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		delete[] prev_string_content;
	}
	// ���� �����Ϸ��� size �� ���� capacity ���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�. 
}

int main()
{
	MyString str1("very very very long string");
	str1.reserve(30);

	cout << "Capacity : " << str1.capacity() << endl;
	cout << "String length : " << str1.length() << endl;

	str1.println();
}


