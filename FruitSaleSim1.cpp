#include <iostream>

using namespace std;

class FruitSeller
{
private:	//�ɹ� ����
	int APPLE_PRICE; //����
	int numOfApples; 
	int myMoney;

public:		//�ɹ� �Լ�
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
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ� " << endl;
			return 0;
		}

		int num = money / APPLE_PRICE; // 2000 / 1000 = 2
		numOfApples -= num; // 20 - 2 = 18 
		myMoney += money; // 0 + 2000 = 2000
		return num; // num = 2 
	}
	void ShowSalesRsult() const //�� �Լ� �������� �ɹ� ������ ����� ���� �������� �ʰٴ�.
	{
		cout << "���� ��� : " << numOfApples << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl;
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
			cout << "�߸��� ������ �ԷµǾ� �ǸŸ� �����մϴ�" << endl;
			return;
		}

		numOfApples += seller.SaleApples(money);  //���� ���� �Լ� ȣ��.  return num = 2  = numOfApple 
		myMoney -= money; // 5000 - 2000 = 3000
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
};

int main(void)
{
	
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); //������ ����

	cout << "���� �Ǹ��� ��Ȳ " << endl;
	seller.ShowSalesRsult();
	cout << "���� ������ ��Ȳ " << endl;
	buyer.ShowBuyResult();
	return 0;

}

// �� �������� ��ư� ������ �� �ִ� �κ��̴�. BuyApples�� ����Ǳ��� ����� ����ϴ� �Լ��̴�.
// ��, �� �Լ� ������ ����� ���Ű� �ϼ��Ǿ�� �Ѵ�.
// �׷��ٸ� ������ ����
// ����� �����ϴµ� �־ �ʿ��� �� �ΰ����� �����ΰ�?
// FruitBuyerŬ���� �ȿ� �������� ������ �ʟG�� �� ���̴�. 
// �װ��� �ٷ� '���Ŵ��'�� '���űݾ�;�̴� �׷��� �� ���� ������ ���ڷ� ���޵ǵ��� �Լ��� ���ǵǾ���.