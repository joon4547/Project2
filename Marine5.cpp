#include <iostream>
using namespace std;

/* 자기 자신을 가리키는 포인터 this */
class Marine
{
	static int total_marine_num;
	const static int i = 0;

	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage;

public:
	//기본 생성자
	Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5),
		is_dead(false){	total_marine_num++;	}
	//좌표에 마린 생성
	Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5),
		is_dead(false){	total_marine_num++;	}
	//마린 데미지
	Marine(int x, int y, int defalt_damage) : coord_x(x), coord_y(y), hp(50), default_damage(defalt_damage),
		is_dead(false){	total_marine_num++;	}

	int attack(); //데미지를 리턴.
	Marine&be_attacked(int damage_earn); //입는 데미지
	void move(int x, int y); //새로운 위치

	void show_status();
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};

//static 맴버변수 초기화.
int Marine::total_marine_num = 0;


void Marine::show_total_marine()
{
	cout << "전체 마린 수 : " << total_marine_num << endl;
}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}
int Marine::attack()
{
	return default_damage;
}

//래퍼런스를 리턴하는 함수와 this.
//this는 객체 자신을 가리키는 포인터의 역할을 한다.
//즉, 이 멤버 함수를 호출하는 객체 자신을 가리킨다는 것. 
//실제로 모든 멤버 함수 내에서는 this 키워드가 정의되어 있으며 클래스 안에 정의된 함수 중에서
//this 키워드가 없는 함수는(당연하게도) static 함수 뿐이다.
//Marine& 를 리턴한다는 말이 도대체 무슨말일까? (래퍼런스란 별명이다)
Marine& Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;

	return *this;
}

void Marine::show_status()
{
	cout << "*** Marine *** " << endl;
	cout << "Location : ( " << coord_x << ", " << coord_y << " ) " << endl;
	cout << "HP : " << hp << endl;
	cout << "현재 총 마린 수 : " << total_marine_num << endl;
}

int main(void)
{
	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	cout << endl << "마린 1 이 마린 2를 두번 공격! " << endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}