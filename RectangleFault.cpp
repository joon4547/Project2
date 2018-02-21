#include <iostream>
using namespace std;

class Point //점을 표현한 맴버변수 x,y 인데 public선언으로 어디서든 접근 가능.
{
public:
	int x; //x좌표는 0이상 100이하
	int y; //이하동문
};
class Rectangle  //점 두개로 사각형 표현이 가능함으로 클래스 맴버의 객체로 둠.
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "좌 상단 : " << '[' << upLeft.x << ", ";
		cout << upLeft.y << "]" << endl;
		cout << "우 하단 : " << '[' << lowRight.x << ",";
		cout << lowRight.y << "]" << endl;
	}
};

int main(void)
{
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 }; //클라스를 public 으로 선언하면 구조체 변수를 초기화하듯이 초기화 가능.
	Rectangle rec = { pos2, pos1 }; //객체 생성 및 초기화.
	rec.ShowRecInfo();
	return 0;
}