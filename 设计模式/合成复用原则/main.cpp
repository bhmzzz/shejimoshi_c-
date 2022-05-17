#include<iostream>
using namespace std;

class AbstractCar {
public:
	virtual void run() = 0;
};

class DaZhong : public AbstractCar {
public:
	virtual void run() {
		cout << "大众启动..." << endl;
	}
};

class Tuolaji : public AbstractCar {
public:
	virtual void run() {
		cout << "拖拉机启动..." << endl;
	}
};

//针对具体类，不使用继承
/*
class Person : public Tuolaji{
public:
	void Doufeng()
	{
		run();
	}
};

class PersonB : public DaZhong {
public:
	void Doufeng()
	{
		run();
	}
};
*/

//可以使用组合
class Person {
public:
	void setCar(AbstractCar* car)
	{
		this->car = car;
	}
	void Doufeng()
	{
		car->run();
		if (this->car != nullptr)
			delete car;
	}
public:
	AbstractCar* car;
};

void test02()
{
	Person* p = new Person;
	p->setCar(new DaZhong);
	p->Doufeng();

	p->setCar(new Tuolaji);
	p->Doufeng();
	delete p;
}

//继承和组合 优先使用组合。
int main()
{
	test02();

	return 0;
}