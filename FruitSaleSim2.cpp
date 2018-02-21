#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApple;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) //������ �߰�. 56�࿡�� �� �����ڸ� ������� ��ü�� �����ϰ� �ִ�.
	{
		APPLE_PRICE = price;
		numOfApple = num;
		myMoney = money;
	}
	int SaleApple(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApple -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "���� ��� : " << numOfApple << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money) //������ �߰�
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApple(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
};
int main(void)
{
	FruitSeller seller(1000, 20, 0); //�����ڷ� ��ü ����.
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}