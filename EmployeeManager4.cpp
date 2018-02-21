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
	virtual int GetPay() const
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const	
	{}
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
	int workTime;	//이 달에 일한 시간의 합계
	int payPerHour;	//시간당 급여
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
	int salesResult;	//월 판매실적
	double bonusRatio;	//상여금 비율
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
		return PermanentWorker::GetPay()	//PermanentWorker의 GetPay 함수 호출 
			+ (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;	//SalesWorker의 GetPay함수가 호출됨.
	}
};

int main(void)
{
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	//정규직 등록
	handler.AddEmplyee(new PermanentWorker("KIM", 1000));
	handler.AddEmplyee(new PermanentWorker("LEE", 2500));

	//임시직 등록
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmplyee(alba);

	//영업직 등록
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);

	//이번 달 지불해야 할 급여의 정보
	handler.AddEmplyee(seller);

	//이번 달에 지불해야 할 급여의 총합.
	handler.ShowTotalSalary();
	return 0;
}