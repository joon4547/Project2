#include <iostream>
#include <string.h>
using namespace std;

/* static �Լ� */
class Marine
{
private:

	static int total_marine_num;
	//const static int i = 0;
	//�̰ɷδ� �ɹ��������� �ʱ�ȭ ����.
	//��� ���� �� static �������� ���ǿ� ���ÿ� ���� �ڵ����� 0 ���� �ʱ�ȭ �Ǳ� ������
	//�� ��� �츮�� ���� ���� �ʱ�ȭ ���� �ʾƵ� ������ Ŭ���� static �������� ��� �ʱ�ȭ�� �ѹ� �Ѵ�.


	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage; //�⺻ ���ݷ�


public:
	//�⺻ ������
	Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5),
		is_dead(false){
		total_marine_num++;
	}
	//��ǥ�� ���� ����
	Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5),
		is_dead(false){
		total_marine_num++;
	}

	//���� ������
	Marine(int x, int y, int defalt_damage) : coord_x(x), coord_y(y), hp(50), default_damage(defalt_damage),
		is_dead(false){
		total_marine_num++;
	}

	int attack(); //������ ����
	void be_attacked(int damage_earn); //�Դ� ������
	void move(int x, int y);	//���ο� ��ġ

	void show_status(); //���¸� �����ش�.
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};


int Marine::total_marine_num = 0;

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

//static �Լ�. � ��ü�� �������� �ʴ�.
void Marine::show_total_marine()
{
	cout << "��ü ���� �� : " << total_marine_num << endl;
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
	cout << " ���� �� ���� �� : " << total_marine_num << endl;
}

void create_marine()
{
	Marine marine3(10, 10, 4);
	Marine::show_total_marine();
}

int main(void)
{
	//(Ŭ����)::(static �Լ�) �������� ȣ���Ѵ�. 
	//��� ��ü�� �� �Լ��� �����ϰ����� �ʱ� ������ �̷��� ȣ���Ѵ�.
	//static �Լ� �������� Ŭ������ static ���� ���� �̿��� �� �ۿ� ����.
	Marine::show_total_marine();
	Marine marine1(2, 3, 5);
	Marine::show_total_marine();

	Marine marine2(3, 5, 10);
	Marine::show_total_marine();

	create_marine();

	cout << endl << " ���� 1�� ���� 2�� ����! " << endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

}