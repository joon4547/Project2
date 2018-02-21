#include <iostream>
#include <cstring>
using namespace std;

class Employee //������� �ǹ��ϴ� Employee Ŭ���� �߰�. ��������� �̸��� �����Ƿ� �̿Ͱ��� ������� ������� ������.
{
private:
	char name[100];
public:
	Employee(char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
};

class PermanentWorker : public Employee	//EmployeeŬ���� ���.
{
private:
	int salary;	//�� �޿�
public:
	PermanentWorker(char * name, int money)
		:Employee(name), salary(money)
	{}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler	//������ ����� Employee��ü. PermanentWorker ��ü ���� Employee ��ü������ ������ �����ϴ�.
{
private:
	Employee * empList[50]; //Employee��ü�� �ּ� ���� �����ϴ� ������� ��ü�� �����Ѵ�. ���� EmployeeŬ������ ����ϴ� Ŭ������ ��ü�� �� �迭�� �Բ� ������ ����.(���Ⱑ �ٽ�)
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmplyee(Employee * emp)	//AddEmployee �Լ��� ���ڷ� Employee��ü�� �ּ� ���� �����ؾ� �Ѵ�. ���� EmployeeŬ������ ����ϴ� Worker��ü�� �ּ� ���� ������ �����ϴ�.
	{
		empList[empNum++] = emp;	
	}
	void ShowAllSalaryInfo() const
	{
		/*
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
			*/
	}
	void ShowTotalSalary() const	
	{
		int sum = 0;
	/*
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetmPay();
	*/
		cout << "salary sum : " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	//�������
	handler.AddEmplyee(new PermanentWorker("Kim", 1000));
	handler.AddEmplyee(new PermanentWorker("Lee", 1500));
	handler.AddEmplyee(new PermanentWorker("JUN", 2000));

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();
	//�̹� �޿� �����ؾ� �� �޾��� ��.
	handler.ShowTotalSalary();
	return 0;
}