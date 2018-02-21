#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle
{
private:
	Point upLeft;  //ClassName objName
	Point lowRight;
public:
	/*bool INitMembers(const Point &ul, const Point &lr);*/
	Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
	void ShowRecInfo() const;
};
#endif