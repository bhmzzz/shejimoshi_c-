#include<iostream>
#include<list>
using namespace std;
//抽象的观察者
class AbstractHero {
public:
	virtual void Update() = 0;
};
//具体观察者
class HeroA : public AbstractHero {
public:
	HeroA() {
		cout << "英雄正在打boss" << endl;
	}
	virtual void Update()
	{
		cout << "英雄停止攻击" << endl;
	}
};

class HeroB : public AbstractHero {
public:
	HeroB() {
		cout << "英雄正在打boss" << endl;
	}
	virtual void Update()
	{
		cout << "英雄停止攻击" << endl;
	}
};

class HeroC : public AbstractHero {
public:
	HeroC() {
		cout << "英雄正在打boss" << endl;
	}
	virtual void Update()
	{
		cout << "英雄停止攻击" << endl;
	}
};

class HeroD : public AbstractHero {
public:
	HeroD() {
		cout << "英雄正在打boss" << endl;
	}
	virtual void Update()
	{
		cout << "英雄停止攻击" << endl;
	}
};

//抽象观察目标
class AbstractBoss {
public:
	virtual void addHero(AbstractHero* hero) = 0;
	virtual void deleteHero(AbstractHero* hero) = 0;
	virtual void notify() = 0;//通知所有观察者
};

//具体的观察者
class BOSSA : public AbstractBoss {
public:
	virtual void addHero(AbstractHero* hero) {
		pherolist.push_back(hero);
	}
	virtual void deleteHero(AbstractHero* hero) {
		pherolist.remove(hero);
	}
	virtual void notify() {
		for (list<AbstractHero*>::iterator it = pherolist.begin(); it != pherolist.end(); it++)
		{
			(*it)->Update();
		}
	}
private:
	list<AbstractHero*> pherolist;
};

void test01()
{
	//创建观察者
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	//创建观察目标
	AbstractBoss* bossA = new BOSSA;
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);

	cout << "hero c阵亡" << endl;
	bossA->deleteHero(heroC);

	cout << "boss死了，通知其他英雄待机" << endl;
	bossA->notify();
}

int main()
{
	test01();
	return 0;
}