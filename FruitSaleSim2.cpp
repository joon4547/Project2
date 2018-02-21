#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApple;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) //생성자 추가. 56행에는 이 생성자를 기반으로 객체를 생성하고 있다.
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
		cout << "남은 사과 : " << numOfApple << endl;
		cout << "판매 수익 : " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money) //생성자 추가
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
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 갯수 : " << numOfApples << endl << endl;
	}
};
int main(void)
{
	FruitSeller seller(1000, 20, 0); //생성자로 객체 생성.
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}