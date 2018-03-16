#include <iostream>
#include <string.h>

using namespace std;

class Marine
{
	int hp;
	int coord_x, coord_y; //마린 위치
	int damage;
	bool is_dead;
	char *name; //마린 이름

public:
	Marine();//기본 생성자
	Marine(int x, int y, const char* marine_name);
	Marine(int x, int y); //x, y좌표에 마린 생성
	~Marine();

	int attack();	//리턴 데미지
	void be_attacked(int damage_earn); //입는 데미지
	void move(int x, int y);	//새로운 위치
	void show_status();	//상태를 보여준다.
};

Marine::Marine()
{
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name)
{
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);

	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;;
	is_dead = false;
}

Marine::Marine(int x, int y)
{
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}
void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack()
{
	return damage;
}

void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
}

void Marine::show_status()
{
	cout << "***Marine :"  << name << "***" << endl;
	cout << "Location : ( " << coord_x << ", " << coord_y << " )" << endl;
	cout << "HP : " << hp << endl;
}

Marine::~Marine()
{
	cout << name << "의 소멸자 호출!" << endl;
	if (name != NULL)
	{
		//name자체가 char의 배열로 동적할당 하엿기 때문에 delete역시 delete[] name으로 써주어야 한다.
		delete[]name;
	}
}

int main()
{
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 2");
	marines[1] = new Marine(3, 5, "Marine 1");

	marines[0]->show_status();
	marines[1]->show_status();

	cout << endl << "마린 1 어택 마린 2!" << endl;

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	
	delete marines[0];
	delete marines[1];


	/*Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();

	cout << endl << "마린 1 이 마린 2를 공격" << endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();*/
}