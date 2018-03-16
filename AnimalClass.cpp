#include <iostream>
using namespace std;

class Animal
{
private:
	int food;
	int weight;

public:
	void set_animal(int _food, int _weight)
	{
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc)
	{
		food += inc;
		weight += (inc / 3);
	}
	void view_stat()
	{
		cout << "이 동물의 food   : " << food << endl;
		cout << "이 동물의 weight : " << weight << endl;
	}
}; // 세미콜론 잊지 말자!

int main()
{
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}