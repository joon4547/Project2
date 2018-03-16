#include <iostream>
#include <string>
using namespace std;

class starcraft
{
private:
	char unit[100];
	int hp;
	int damage;
public:
	starcraft(char[], int, int);
	void show();
};

starcraft::starcraft(char a[100], int b, int c)
{
	strcpy(unit, a);
	hp = b;
	damage = c;
}

void starcraft::show()
{
	cout << "name : " << unit << "\nhp : " << hp << "\ndamage = " << damage << endl;
}

void main()
{
	starcraft marine("marine\0", 40, 6);
	starcraft zergling("zergling\0", 35, 5);
	starcraft hydralisk("hydralisk\0", 80, 10);

	marine.show();

	starcraft *p = &zergling;
	p->show();
	p = &hydralisk;
	p->show();
}