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
			cout << "잘못된 정보가 전달되어 판매를 취소합니다" << endl;
			return 0;
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMeoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "남은 사과 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMeoney << endl << endl;
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
			cout << " 잘못된 정보가 전달되어 구매를 취소합니다 ." << endl;
			return;
		}

		numOfApples += seller.SaleApples(money);
		myMoney -= money;			
	}
	void ShowBuyRseult() const
	{
		cout << "남은 금액 : " << myMoney << endl;
		cout << "사과 갯수 : " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyRseult();
	return 0;
}