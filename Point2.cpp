#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos)
{
	x = xpos;
	y = ypos;
}

int Point::GetX() const		//const �Լ�
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
		cout << "��� ������ �� ���� " << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	y = ypos;
	return true;
}

//�ɹ������� private�� �����ϰ�, �ش� ������ �����ϴ� �Լ��� ������ �����ؼ�, ������ ���·� �ɹ� ������ ������ �����ϴ� ���� �ٷ� '��������'�̸� �̴� ���� Ŭ������ �Ǳ� ���� �⺻ �����̵ȴ�.'
//������ �Լ��� �ɹ������� private���� �����ϸ鼭 Ŭ���� �ܹ������� �ɹ����� ������ �������� ���ǵǴ� �Լ���.