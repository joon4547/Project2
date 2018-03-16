#include <iostream>

using namespace std;

class Marine
{
	int hp;
	int coord_x, coord_y; //���� ��ġ
	int damage;
	bool is_dead;

public:
	Marine();//�⺻ ������
	Marine(int x, int y); //x, y��ǥ�� ���� ����

	int attack();	//���� ������
	void be_attacked(int damage_earn); //�Դ� ������
	void move(int x, int y);	//���ο� ��ġ

	void show_status();	//���¸� �����ش�.
};

Marine::Marine()
{
	hp = 30;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	cout << "�μ�����" << endl;
}

Marine::Marine(int x, int y)
{
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
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
	cout << "***Marine***" << endl;
	cout << "Location : ( " << coord_x << ", " << coord_y << " )" << endl;
	cout << "HP : " << hp << endl;
}

int main()
{
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();

	cout << endl << "���� 1 �� ���� 2�� ����" << endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}