#include <iostream>
using namespace std;

class Point //���� ǥ���� �ɹ����� x,y �ε� public�������� ��𼭵� ���� ����.
{
public:
	int x; //x��ǥ�� 0�̻� 100����
	int y; //���ϵ���
};
class Rectangle  //�� �ΰ��� �簢�� ǥ���� ���������� Ŭ���� �ɹ��� ��ü�� ��.
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "�� ��� : " << '[' << upLeft.x << ", ";
		cout << upLeft.y << "]" << endl;
		cout << "�� �ϴ� : " << '[' << lowRight.x << ",";
		cout << lowRight.y << "]" << endl;
	}
};

int main(void)
{
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 }; //Ŭ�󽺸� public ���� �����ϸ� ����ü ������ �ʱ�ȭ�ϵ��� �ʱ�ȭ ����.
	Rectangle rec = { pos2, pos1 }; //��ü ���� �� �ʱ�ȭ.
	rec.ShowRecInfo();
	return 0;
}