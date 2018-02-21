#include <iostream>
#include <cstring>
using namespace std;
#pragma warning ( disable : 4996 )
class MyFriendInfo //기본 클래스
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(char * fname, int fage)
		: age(fage)
	{
		name = new char[strlen(fname) + 1];
		strcpy(name, fname);
	}
	void ShowMyFriendInfo()
	{
		cout << "이름:" << name << endl;
		cout << "나이:" << age << endl;
	}
	~MyFriendInfo()
	{
		delete[]name;
	}
};

class MyFriendDetailInfo :public MyFriendInfo	//유도 클래스
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(char * fname, int fage, char * faddr, char * fphone)
		: MyFriendInfo(fname, fage)
	{
		addr = new char[strlen(faddr) + 1];		
		phone = new char[strlen(fphone) + 1];
		strcpy(addr, faddr);
		strcpy(phone, fphone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소:" << addr << endl;
		cout << "번호:" << phone << endl;
	}
};

int main(void)
{
	MyFriendDetailInfo Fr1("Shin", 28, "인천 광역시", "12345678");
	MyFriendDetailInfo Fr2("Lee", 28, "성남시", "12345678");
	Fr1.ShowMyFriendDetailInfo();
	Fr2.ShowMyFriendDetailInfo();

	return 0;
}