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
	virtual int GetPay() const
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const	
	{}
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
		
		for (int i = 0; i < empNum; i++)
		empList[i]->ShowSalaryInfo();
		
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		
		for (int i = 0; i < empNum; i++)
		sum += empList[i]->GetPay();
		
		cout << "salary sum : " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;	//�� �޿� ���� �ð��� �հ�
	int payPerHour;	//�ð��� �޿�
public:
	TemporaryWorker(char * name, int pay)
		:Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime*payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;	//�� �ǸŽ���
	double bonusRatio;	//�󿩱� ����
public:
	SalesWorker(char * name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPat() const
	{
		return PermanentWorker::GetPay()	//PermanentWorker�� GetPay �Լ� ȣ�� 
			+ (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;	//SalesWorker�� GetPay�Լ��� ȣ���.
	}
};

int main(void)
{
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	//������ ���
	handler.AddEmplyee(new PermanentWorker("KIM", 1000));
	handler.AddEmplyee(new PermanentWorker("LEE", 2500));

	//�ӽ��� ���
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmplyee(alba);

	//������ ���
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);

	//�̹� �� �����ؾ� �� �޿��� ����
	handler.AddEmplyee(seller);

	//�̹� �޿� �����ؾ� �� �޿��� ����.
	handler.ShowTotalSalary();
	return 0;
}