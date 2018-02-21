#include <iostream>

using namespace std;

class FruitSeller
{
private:	//맴버 변수
	int APPLE_PRICE; //가격
	int numOfApples; 
	int myMoney;

public:		//맴버 함수
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price; //1000
		numOfApples = num; //20
		myMoney = money;
	}
	int SaleApples(int money)
	{
		if (money < 0)
		{
			cout << "잘못된 정보가 전달되어 판매를 취소합니다 " << endl;
			return 0;
		}

		int num = money / APPLE_PRICE; // 2000 / 1000 = 2
		numOfApples -= num; // 20 - 2 = 18 
		myMoney += money; // 0 + 2000 = 2000
		return num; // num = 2 
	}
	void ShowSalesRsult() const //이 함수 내에서는 맴버 변수에 저장된 값을 변경하지 않겟다.
	{
		cout << "남은 사과 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMoney << endl;
	}
};
class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money; //5000
		numOfApples = 0;
	}

	void BuyApples(FruitSeller &seller, int money) //2000		
	{
		if (money < 0)
		{
			cout << "잘못된 정보가 입력되어 판매를 종료합니다" << endl;
			return;
		}

		numOfApples += seller.SaleApples(money);  //구매 목적 함수 호출.  return num = 2  = numOfApple 
		myMoney -= money; // 5000 - 2000 = 3000
	}
	void ShowBuyResult() const
	{
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numOfApples << endl << endl;
	}
};

int main(void)
{
	
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); //과일의 구매

	cout << "과일 판매의 현황 " << endl;
	seller.ShowSalesRsult();
	cout << "과일 구매의 현황 " << endl;
	buyer.ShowBuyResult();
	return 0;

}

// 이 예제에서 어렵게 느껴질 수 있는 부분이다. BuyApples는 사과의구매 기능을 담당하는 함수이다.
// 즉, 이 함수 내에서 사과의 구매가 완성되어야 한다.
// 그렇다면 생각해 보자
// 사과를 구매하는데 있어서 필요한 것 두가지가 무엇인가?
// FruitBuyer클래스 안에 존재하지 않지만 필욯나 것 말이다. 
// 그것은 바로 '구매대상'과 '구매금액;이다 그래서 이 둘의 정보가 인자로 전달되도록 함수가 정의되었다.