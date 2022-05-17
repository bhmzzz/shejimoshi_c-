#include<iostream>
#include<list>
using namespace std;
//����Ĺ۲���
class AbstractHero {
public:
	virtual void Update() = 0;
};
//����۲���
class HeroA : public AbstractHero {
public:
	HeroA() {
		cout << "Ӣ�����ڴ�boss" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��ֹͣ����" << endl;
	}
};

class HeroB : public AbstractHero {
public:
	HeroB() {
		cout << "Ӣ�����ڴ�boss" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��ֹͣ����" << endl;
	}
};

class HeroC : public AbstractHero {
public:
	HeroC() {
		cout << "Ӣ�����ڴ�boss" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��ֹͣ����" << endl;
	}
};

class HeroD : public AbstractHero {
public:
	HeroD() {
		cout << "Ӣ�����ڴ�boss" << endl;
	}
	virtual void Update()
	{
		cout << "Ӣ��ֹͣ����" << endl;
	}
};

//����۲�Ŀ��
class AbstractBoss {
public:
	virtual void addHero(AbstractHero* hero) = 0;
	virtual void deleteHero(AbstractHero* hero) = 0;
	virtual void notify() = 0;//֪ͨ���й۲���
};

//����Ĺ۲���
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
	//�����۲���
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	//�����۲�Ŀ��
	AbstractBoss* bossA = new BOSSA;
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);

	cout << "hero c����" << endl;
	bossA->deleteHero(heroC);

	cout << "boss���ˣ�֪ͨ����Ӣ�۴���" << endl;
	bossA->notify();
}

int main()
{
	test01();
	return 0;
}