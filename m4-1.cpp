#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMeoney;

public:
	void InitMembers(int pirce, int num, int money)
	{
		APPLE_PRICE = pirce;
		numOfApples = num;
		myMeoney = money;
	}
	int SaleApples(int money)
	{
		if (money < 0)
		{
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�" << endl;
			return 0;
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMeoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "���� ��� : " << numOfApples << endl;
		cout << "�Ǹ� ���� : " << myMeoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0)
		{
			cout << " �߸��� ������ ���޵Ǿ� ���Ÿ� ����մϴ� ." << endl;
			return;
		}

		numOfApples += seller.SaleApples(money);
		myMoney -= money;			
	}
	void ShowBuyRseult() const
	{
		cout << "���� �ݾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyRseult();
	return 0;
}