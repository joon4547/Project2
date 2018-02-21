#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos)
{
	x = xpos;
	y = ypos;
}

int Point::GetX() const		//const 함수
{
	return x;
}

int Point::GetY() const
{
	return y;
}

bool Point::SetX(int xpos)
{
	if (0 > xpos || xpos > 100)
	{
		cout << "벗어난 범위의 값 전달 " << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	y = ypos;
	return true;
}

//맴버변수를 private로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서, 안전한 형태로 맴버 변수의 접근을 유도하는 것이 바로 '정보은닉'이며 이는 좋은 클래스가 되기 위한 기본 조건이된다.'
//엑세스 함수는 맴버변수를 private으로 선언하면서 클래스 외무에서의 맴버변수 접근을 목적으로 정의되는 함수들.