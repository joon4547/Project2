#include <iostream>
#include <string.h>
using namespace std;

class Marine
{
	static int total_marine_num;

	int hp;
	int coord_x, coord_y;	
	bool is_dead;

	const int default_damage; //기본 공격력
								

public:
	Marine(): hp(50), coord_x(0), coord_y(0), default_damage(5), 
		is_dead(false){	total_marine_num++;	}
	Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), 
		is_dead(false){	total_marine_num++;	}
	Marine(int x, int y, int defalt_damage) : coord_x(x), coord_y(y), hp(50), default_damage(defalt_damage), 
		is_dead(false){	total_marine_num++;	}

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();

	~Marine() { total_marine_num--; }
};


int Marine::total_marine_num = 0;

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack()
{
	return default_damage;
}

void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
}

void Marine::show_status()
{
	cout << "***Marine***" << endl;
	cout << "Location : ( " << coord_x << ", " << coord_y << " )"<< endl;
	cout << "HP : " << hp << endl;
	cout << " 현재 총 마린 수 : " << total_marine_num << endl;
}

void create_marine()
{
	Marine marine3(10, 10, 4);
	marine3.show_status();
}

int main(void)
{
	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	create_marine();
	
	cout << endl << " 마린 1이 마린 2를 공격! " << endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
	
}