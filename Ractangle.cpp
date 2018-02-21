#include <iostream>
#include "Rectangle.h"
using namespace std;


//
//bool Rectangle::INitMembers(const Point &ul, const Point &lr)
//{
//	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
//	{
//		cout << "잘못된 위치 정보 전달" << endl;
//		return false;
//	}
//	upLeft = ul;
//	lowRight = lr;
//	return true;
//}

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
	:upLeft(x1, x2), lowRight(x2, y2)
{
	//empty
}

void Rectangle::ShowRecInfo() const
{
	cout << "좌 상단 : " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단 : " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}