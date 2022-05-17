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

class FruitFactory {
public:
	static AbstractFruit* CreateFruit(string flag)
	{
		if (flag == "apple")
		{
			return new Apple;
		}
		else if (flag == "Bnanal")
		{
			return new Bnanal;
		}
		else if (flag == "Pear")
		{
			return new Pear;
		}
	}
};

void test01() {
	FruitFactory* factory = new FruitFactory;
	AbstractFruit* apple = factory->CreateFruit("apple");
	apple->ShowName();
	delete apple;
	delete factory;
}

int main()
{

	return 0;
}