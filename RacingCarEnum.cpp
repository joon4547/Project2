#include <iostream>
using namespace std;


namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10,
	};
}

struct Car
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int carSpeed;

	void ShowCarState(const Car &car)
	{
		cout << "소유자ID:" << car.gamerID << endl;
		cout << "연료량 :" << car.fuelGauge << "%" << endl;
		cout << "현재속도 : " << car.carSpeed << "km/s" << endl;
	}
	void Accel(Car &car)
	{
		if (car.fuelGauge <= 0)
			return;
		else
			car.fuelGauge -= CAR_CONST::FUEL_STEP;

		if (car.carSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
		{
			car.carSpeed = CAR_CONST::MAX_SPD;
			return;
		}
		car.carSpeed += CAR_CONST::ACC_STEP;
	}
	void Break(Car &car)
	{
		if (car.carSpeed < CAR_CONST::BRK_STEP)
		{
			car.carSpeed = 0;
			return;
		}
		car.carSpeed -= CAR_CONST::BRK_STEP;
	}
};

int main(void)
{
	Car run99 = { "reun99", 100, 0 };
	run99.Accel(run99);
	run99.Accel(run99);
	run99.ShowCarState(run99);
	run99.Break(run99);
	run99.ShowCarState(run99);

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel(sped77);
	sped77.Break(sped77);
	sped77.ShowCarState(sped77);
	return 0;

}

