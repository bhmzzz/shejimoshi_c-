#include<iostream>
using namespace std;

class AbstractFruit {
public:
	virtual void ShowName() = 0;
};

class Apple : public AbstractFruit {
public:
	void ShowName()
	{
		cout << "Æ»¹û" << endl;
	}
};

class Bnanal : public AbstractFruit {
public:
	void ShowName()
	{
		cout << "Ïã½¶" << endl;
	}
};

class Pear : public AbstractFruit {
public:
	void ShowName()
	{
		cout << "Àæ" << endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
};

class AppleFactory : public AbstractFactory {
public:
	AbstractFruit* CreateFruit()
	{
		return new Apple;
	}
};

class BnanaFactory :public AbstractFactory {
public:
	AbstractFruit* CreateFruit()
	{
		return new Bnanal;
	}
};

class PearFactory :public AbstractFactory {
public:
	AbstractFruit* CreateFruit()
	{
		return new Pear;
	}
};

void test01()
{
	AbstractFactory* factory = nullptr;
	AbstractFruit* furit = nullptr;

	factory = new AppleFactory;
	furit = factory->CreateFruit();
	furit->ShowName();
	delete furit;
	delete factory;
}