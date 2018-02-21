#include <iostream>

using namespace std;

class ThisFunc {
private:
	int num1;
	int num2;
public:
	ThisFunc(int num1, int num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	void ShowData()
	{
		cout << "num1 : " << this->num1 << endl;
		cout << "num2 : " << num2 << endl;
	}
};

int main(void)
{
	ThisFunc TF(100, 200);
	TF.ShowData();

	system("pause");
	return 0;
}
