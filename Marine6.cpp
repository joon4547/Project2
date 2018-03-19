#include <iostream>
using namespace std;

//상수 멤버 함수
//자기 자신을 가리키는 포인터 this
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
		is_dead(false){
		total_marine_num++;
	}
	//좌표에 마린 생성
	Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5),
		is_dead(false){
		total_marine_num++;
	}
	//마린 데미지
	Marine(int x, int y, int defalt_damage) : coord_x(x), coord_y(y), hp(50), default_damage(defalt_damage),
		is_dead(false){
		total_marine_num++;
	}

	void move(int x, int y); //새로운 위치
	int attack() const;//데미지를 리턴
	Marine& be_attacked(int damage_enrn); //입는 데미지
	
	void show_satus();
	static void show_total_marine();
	~Marine(){ total_marine_num--; }
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine()
{
	cout << "현재 마린의 수 :" <<total_marine_num << endl;
}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack() const
{
	return default_damage;
}

Marine& Marine::be_attacked(int damage_enrn)
{
	this->hp -= damage_enrn;
	if (this->hp <= 0)
		this->is_dead = true;

	return *this;
}

void Marine::show_satus()
{
	cout << "*** Marine ***" << endl;
	cout << "Location : < " << coord_x << ", " << coord_y << " > " << endl;
	cout << "HP : " << hp << endl;
	cout << "현재 총 마린 수 " << total_marine_num << endl;
}

int main(void)
{
	Marine marine1(2, 3, 5);
	marine1.show_satus();

	Marine marine2(3, 5, 10);
	marine2.show_satus();

	cout << endl << "마린 1이 마린 2를 공격 " << endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_satus();
	marine2.show_satus();
}