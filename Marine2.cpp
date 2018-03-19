#include <iostream>
#include <string.h>
using namespace std;

/* Ŭ���� static �ɹ����� */
class Marine
{
	int hp; // ���� ü��
	int coord_x, coord_y; // ���� ��ġ
	int damage; // ���ݷ� 
	bool is_dead;
	char *name; // ���� �̸�
public:
	Marine(); // �⺻ ������
	Marine(int x, int y, const char* marine_name); // �̸����� ����
	Marine(int x, int y); // x, y ��ǥ�� ���� ����
	~Marine();

	int attack(); // �������� �����Ѵ�.
	void be_attacked(int damage_earn); // �Դ� ������
	void move(int x, int y); // ���ο� ��ġ
	void show_status(); // ���¸� �����ش�.
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
	damage = 5;
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
	cout << " *** Marine : " << name << " ***" << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
}

Marine::~Marine()
{
	cout << name << " �� �Ҹ��� ȣ�� ! " << endl;
	if (name != NULL)
	{
		delete[] name;
	}
}

int main()
{
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 2");
	marines[1] = new Marine(1, 5, "Marine 1");

	marines[0]->show_status();
	marines[1]->show_status();

	cout << endl << "���� 1 �� ���� 2 �� ����! " << endl;
	
	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();
	
	delete marines[0];
	delete marines[1];
}



