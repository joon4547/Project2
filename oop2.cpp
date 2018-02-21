#include <iostream>
#include <cstring>
#pragma warning ( disable : 4996 )
using namespace std;
const int NAME_LEN = 20;

void ShowMenu();            // �޴����
void MakeAccount();            // ���°����� ���� �Լ�
void DepositMoney();        // �Ա�
void WithdrawMoney();        // ���
void ShowAllAccInfo();        // �ܾ���ȸ

enum { MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
	int accID;                    // ���¹�ȣ
	int balance;                // �ܾ�
	char* cusName;                // ���̸�

public:
	Account(int ID, int money, char* name) :accID(ID), balance(money)	//������ : �̴ϼȶ�����
	{
		cusName = new char[strlen(name) + 1];    // �̸��� ���̸� Ȯ�� �� NULL ���ڸ� �����ϱ� ���� +1 �ؼ� �����Ҵ����ݴϴ�.
		strcpy(cusName, name);                    // ���ڿ��� �����ؼ� �����մϴ�.
	}
	int GetAccID() 	{ return accID; }    // ���¿� ����� ID�� ��ȯ���ݴϴ�.
	void Deposit(int money) {            // ���ڷ� ���� �ݾ��� �ܾ׿� �����ݴϴ�.
		balance += money;
	}
	int Withdraw(int money) {
		if (balance < money) return 0; // ����� �ݾ��� �޾Ƽ� �ܾװ� �� �� �ܾ��� �� ������ return���� �Լ��� ���������ϴ�.

		balance -= money;
		return money;                    // �ܾ��� �� ������ ��ݾ��� ���ְ� ��ȯ�մϴ�.
	}
	void ShowAccInfo() {                // ���� ������ ID, �̸�, �ܾ� ������ ����մϴ�.
		cout << "����ID: " << accID << endl;
		cout << "�� ��: " << cusName << endl;
		cout << "�� ��: " << balance << endl;
	}
	~Account() {                        // �����Ҵ��� �̸��� �������ݴϴ�.
		delete[] cusName;
	}
};

Account* accArr[100];                    // Account ������ ���� �迭 , ���� ������ �迭
int accNum = 0;                            // ����� Account �� , ���� ����

int main() {
	int choice;

	while (1) {
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:    MakeAccount(); break;
		case DEPOSIT:    DepositMoney(); break;
		case WITHDRAW:    WithdrawMoney(); break;
		case INQUIRE:    ShowAllAccInfo(); break;
		case EXIT: {
			for (int i = 0; i < accNum; i++)	//������ �迭�� �����Ҵ��آZ������.
				delete accArr[i];
			return 0;
		}
		default: cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu() {		//�޴�
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void MakeAccount() {	//���°���
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);            // �迭�� �����鼭�� ++�� �����°� ó���˾���..
}
void DepositMoney() {	//�Ա�
	int money;
	int id;
	cout << "[�Ա�]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "arr[" << i << "]" << endl;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}
void WithdrawMoney() {	//���
	int money;
	int id;
	cout << "[���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(money) == 0) {            // 0�� ��ȯ�Ǹ� �ܾ��� �����Ѱ̴ϴ�. 
				cout << "�ܾ׺���" << endl << endl;            // ���� ���� ��ȯ�޾Ƽ� �˻��߾��µ� ���� ������ ������� �޾� �Ǵ��ϳ׿�.
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}
void ShowAllAccInfo() {		//��������
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}