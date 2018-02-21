#include <iostream>

using namespace std;
#pragma warning ( disable : 4996 )

//정규직 직원의관리를 목적으로 정의된 클래스
class PermanentWorker
{
private:
	char name[100];
	int salary;	//매달 지불해야하는 급여액
public:
	PermanentWorker(char * name, int money)
		: salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay()const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name : " << name << endl;
		cout << "salary : " << GetPay() << endl << endl;
	}
};

//지정된 객체의 급여 정보를 출력하기 위한 함수를 맴버로 지님. 컨트롤 클래스
class EmployeeHandler
{
private:
	PermanentWorker * empList[50];
	int empNum; 
public:
	EmployeeHandler() : empNum(0)
	{}
	//새로운 직원 정보 등록
	void AddEmployee(PermanentWorker* emp) 
	{
		empList[empNum++] = emp;
	}
	//모든 직원의 이번 달 급여 정보 출력
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	//이번 달 급여의 총액 출력
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

int main(void)
{
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();

	return 0;
}