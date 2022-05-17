#include<iostream>
using namespace std;

class AbstractApple {
public:
	virtual void ShowName() = 0;
};

class ChinaApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "�й�ƻ��" << endl;
	}
};

class AmericaApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "����ƻ��" << endl;
	}
};

class JapanApple : public AbstractApple {
public:
	virtual void ShowName() {
		cout << "����ƻ��" << endl;
	}
};

class AbstractBanana {
public:
	virtual void ShowName() = 0;
};

class ChinaBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "�й��㽶" << endl;
	}
};

class AmericaBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "�����㽶" << endl;
	}
};

class JapanBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "�����㽶" << endl;
	}
};

class AbstractPear {
public:
	virtual void ShowName() = 0;
};

class ChinaPear : public AbstractPear {
public:
	virtual void ShowName() {
		cout << "�й�Ѽ��" << endl;
	}
};

class AmericaPear : public AbstractPear {
public:
	virtual void ShowName() {
		cout << "����Ѽ��" << endl;
	}
};

class JapanPear : public AbstractPear {
public:
	virtual void ShowName() {
		cout << "����Ѽ��" << endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};

class ChinaFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new ChinaBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new ChinaPear;
	}
};

class AmericaFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new AmericaApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new AmericaBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new AmericaPear;
	}
};

class JapanFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new JapanBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new JapanPear;
	}
};

void test01()
{
	AbstractFactory* factory = nullptr;
	AbstractApple* apple = nullptr;
	AbstractBanana* banana = nullptr;
	AbstractPear* pear = nullptr;

	factory = new ChinaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();

	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	delete pear;
	delete banana;
	delete apple;
	delete factory;
}