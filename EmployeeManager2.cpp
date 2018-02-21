#include <iostream>
#include <cstring>
using namespace std;

class Employee //고용인을 의미하는 Employee 클래스 추가. 모든고용인은 이름이 있으므로 이와같이 멤버들을 기반으로 정의함.
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

class PermanentWorker : public Employee	//Employee클래스 상속.
{
private:
	int salary;	//월 급여
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

class EmployeeHandler	//저장의 대상이 Employee객체. PermanentWorker 객체 역시 Employee 객체임으로 저장이 가능하다.
{
private:
	Employee * empList[50]; //Employee객체의 주소 값을 저장하는 방식으로 객체를 저장한다. 따라서 Employee클래스를 상속하는 클래스의 객체도 이 배열에 함께 저장이 가능.(여기가 핵심)
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmplyee(Employee * emp)	//AddEmployee 함수의 인자로 Employee객체의 주소 값을 전달해야 한다. 따라서 Employee클래스를 상속하는 Worker객체의 주소 값도 전달이 가능하다.
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
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	//직원등록
	handler.AddEmplyee(new PermanentWorker("Kim", 1000));
	handler.AddEmplyee(new PermanentWorker("Lee", 1500));
	handler.AddEmplyee(new PermanentWorker("JUN", 2000));

	//이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();
	//이번 달에 지불해야 할 급액의 합.
	handler.ShowTotalSalary();
	return 0;
}