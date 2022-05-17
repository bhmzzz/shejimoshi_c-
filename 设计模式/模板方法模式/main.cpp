#include<iostream>
using namespace std;

class DrinkTemplate {
public:
	virtual void BoildWater() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void AddSomething() = 0;

	void Make() {
		BoildWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};

class Coffee : public DrinkTemplate {
public:
	virtual void BoildWater()
	{
		cout << "煮水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void PourInCup()
	{
		cout << "咖啡倒入杯中" << endl;
	}
	virtual void AddSomething()
	{
		cout << "加料" << endl;
	}
};

class Tea : public DrinkTemplate {
public:
	virtual void BoildWater()
	{
		cout << "煮水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡茶" << endl;
	}
	virtual void PourInCup()
	{
		cout << "茶水倒入杯中" << endl;
	}
	virtual void AddSomething()
	{
		cout << "加料" << endl;
	}
};

void test01()
{
	Tea* tea = new Tea;
	tea->Make();
	cout << "-------------" << endl;
	Coffee* coffee = new Coffee;
	coffee->Make();
}

int main()
{
	test01();
	return 0;
}