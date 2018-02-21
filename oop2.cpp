#include <iostream>
#include <cstring>
#pragma warning ( disable : 4996 )
using namespace std;
const int NAME_LEN = 20;

void ShowMenu();            // 메뉴출력
void MakeAccount();            // 개좌개설을 위한 함수
void DepositMoney();        // 입금
void WithdrawMoney();        // 출금
void ShowAllAccInfo();        // 잔액조회

enum { MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
	int accID;                    // 계좌번호
	int balance;                // 잔액
	char* cusName;                // 고객이름

public:
	Account(int ID, int money, char* name) :accID(ID), balance(money)	//생성자 : 이니셜라이져
	{
		cusName = new char[strlen(name) + 1];    // 이름의 길이를 확인 후 NULL 문자를 포함하기 위해 +1 해서 동적할당해줍니다.
		strcpy(cusName, name);                    // 문자열을 복사해서 저장합니다.
	}
	int GetAccID() 	{ return accID; }    // 계좌에 저장된 ID를 반환해줍니다.
	void Deposit(int money) {            // 인자로 받은 금액을 잔액에 더해줍니다.
		balance += money;
	}
	int Withdraw(int money) {
		if (balance < money) return 0; // 출금할 금액을 받아서 잔액과 비교 후 잔액이 더 적으면 return으로 함수를 빠져나갑니다.

		balance -= money;
		return money;                    // 잔액이 더 많으면 출금액을 빼주고 반환합니다.
	}
	void ShowAccInfo() {                // 현재 계좌의 ID, 이름, 잔액 정보를 출력합니다.
		cout << "계좌ID: " << accID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액: " << balance << endl;
	}
	~Account() {                        // 동적할당한 이름을 해제해줍니다.
		delete[] cusName;
	}
};

Account* accArr[100];                    // Account 저장을 위한 배열 , 계좌 포인터 배열
int accNum = 0;                            // 저장된 Account 수 , 계좌 갯수

int main() {
	int choice;

	while (1) {
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:    MakeAccount(); break;
		case DEPOSIT:    DepositMoney(); break;
		case WITHDRAW:    WithdrawMoney(); break;
		case INQUIRE:    ShowAllAccInfo(); break;
		case EXIT: {
			for (int i = 0; i < accNum; i++)	//포인터 배열을 동적할당해줫음으로.
				delete accArr[i];
			return 0;
		}
		default: cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu() {		//메뉴
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void MakeAccount() {	//계좌개설
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);            // 배열에 넣으면서도 ++이 먹히는거 처음알았음..
}
void DepositMoney() {	//입금
	int money;
	int id;
	cout << "[입금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "arr[" << i << "]" << endl;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}
void WithdrawMoney() {	//출금
	int money;
	int id;
	cout << "[출금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(money) == 0) {            // 0이 반환되면 잔액이 부족한겁니다. 
				cout << "잔액부족" << endl << endl;            // 저는 값을 반환받아서 검사했었는데 값을 던지고 결과값을 받아 판단하네요.
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}
void ShowAllAccInfo() {		//계좌정보
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}