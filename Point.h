//#ifndef __POINT_H_
//#define __POINT_H_
//
#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
	int x;
	int y;

public:
	Point(const int &xpos, const int &ypos);
	//	bool InitMembers(int xpos, int ypos);
	int GetX() const;	//이 함수 내에서는 맴버 변수에 저장된 값을 변경하지 않겟다!
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};
#endif