#include<iostream>
using namespace std;

class AbstractCar {
public:
	virtual void run() = 0;
};

class DaZhong : public AbstractCar {
public:
	virtual void run() {
		cout << "��������..." << endl;
	}
};

class Tuolaji : public AbstractCar {
public:
	virtual void run() {
		cout << "����������..." << endl;
	}
};

//��Ծ����࣬��ʹ�ü̳�
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

//����ʹ�����
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

//�̳к���� ����ʹ����ϡ�
int main()
{
	test02();

	return 0;
}