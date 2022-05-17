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
		cout << "��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	virtual void PourInCup()
	{
		cout << "���ȵ��뱭��" << endl;
	}
	virtual void AddSomething()
	{
		cout << "����" << endl;
	}
};

class Tea : public DrinkTemplate {
public:
	virtual void BoildWater()
	{
		cout << "��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݲ�" << endl;
	}
	virtual void PourInCup()
	{
		cout << "��ˮ���뱭��" << endl;
	}
	virtual void AddSomething()
	{
		cout << "����" << endl;
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