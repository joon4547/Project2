#include <iostream>
#include <string.h>
using namespace std;

/* static 함수 */
class Marine
{
private:

	static int total_marine_num;
	//const static int i = 0;
	//이걸로는 맴버변수에서 초기화 가능.
	//모든 전역 및 static 변수들은 정의와 동시에 값이 자동으로 0 으로 초기화 되기 때문에
	//이 경우 우리가 굳이 따로 초기화 하지 않아도 되지만 클래스 static 변수들의 경우 초기화를 한번 한다.


	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage; //기본 공격력


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

	int attack(); //데미지 리턴
	void be_attacked(int damage_earn); //입는 데미지
	void move(int x, int y);	//새로운 위치

	void show_status(); //상태를 보여준다.
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};


int Marine::total_marine_num = 0;

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

//static 함수. 어떤 객체도 속해있지 않다.
void Marine::show_total_marine()
{
	cout << "전체 마린 수 : " << total_marine_num << endl;
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
	cout << "Location : ( " << coord_x << ", " << coord_y << " )" << endl;
	cout << "HP : " << hp << endl;
	cout << " 현재 총 마린 수 : " << total_marine_num << endl;
}

void create_marine()
{
	Marine marine3(10, 10, 4);
	Marine::show_total_marine();
}

int main(void)
{
	//(클래스)::(static 함수) 형식으로 호출한다. 
	//어떠한 객체도 이 함수를 소유하고있지 않기 때문에 이렇게 호출한다.
	//static 함수 내에서는 클래스의 static 변수 만을 이용할 수 밖에 없다.
	Marine::show_total_marine();
	Marine marine1(2, 3, 5);
	Marine::show_total_marine();

	Marine marine2(3, 5, 10);
	Marine::show_total_marine();

	create_marine();

	cout << endl << " 마린 1이 마린 2를 공격! " << endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

}