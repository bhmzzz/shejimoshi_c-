#include<iostream>
using namespace std;

class AbstractHero {
public:
	virtual void ShowStates() = 0;
public:
	int mHP;
	int mMP;
	int mAt;
	int mDf;

};

class HeroA : public AbstractHero {
public:
	HeroA() 
	{
		mHP = 0;
		mMP = 0;
		mAt = 0;
		mDf = 0;
	}
	virtual void ShowStates()
	{
		cout << "Ѫ��:" << mHP << endl;
		cout << "ħ����" << mMP << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

class AbstractEquipment : public AbstractHero {
public:
	AbstractEquipment(AbstractHero* hero)
	{
		phero = hero;
	}
	virtual void ShowStates(){
		cout << "Ѫ��:" << mHP << endl;
		cout << "ħ����" << mMP << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
public:
	AbstractHero* phero;
};

//��ͽ
class KuuangtuEquipment : public AbstractEquipment {
public:
	KuuangtuEquipment(AbstractHero* hero) : AbstractEquipment(hero) {}
	void AddKuangtu() {
		cout << "Ӣ�۴��Ͽ�ͽ" << endl;
		mHP = phero->mHP;
		mMP = phero->mMP;
		mAt = phero->mAt;
		mDf = phero->mDf = 30;

		delete phero;
	}
	virtual void ShowStates() {
		AddKuangtu();
		cout << "Ѫ��:" << mHP << endl;
		cout << "ħ����" << mMP << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

//�޾�֮��
class WujinzhiKnife : public AbstractEquipment {
public:
	WujinzhiKnife(AbstractHero* hero) : AbstractEquipment(hero) {}
	void AddKuangtu() {
		cout << "Ӣ�۴����޾�" << endl;
		mHP = phero->mHP;
		mMP = phero->mMP;
		mAt = phero->mAt + 80;
		mDf = phero->mDf;

		delete phero;
	}
	virtual void ShowStates() {
		AddKuangtu();
		cout << "Ѫ��:" << mHP << endl;
		cout << "ħ����" << mMP << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

void test01()
{
	AbstractHero* hero = new HeroA;
	hero->ShowStates();
	cout << "------------------" << endl;

	hero = new KuuangtuEquipment(hero);
	hero->ShowStates();
	hero = new WujinzhiKnife(hero);
	hero->ShowStates();
}


int main()
{
	test01();
	return 0;
}