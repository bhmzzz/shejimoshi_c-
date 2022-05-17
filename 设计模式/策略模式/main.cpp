#include<iostream>
using namespace std;

//抽象武器 武器策略
class WeaponStrategy {
public:
	virtual void UseWeapon() = 0;
};

class Knife : public WeaponStrategy {
public:
	virtual void UseWeapon()
	{
		cout << "是用匕首" << endl;
	}
};

class AK47 : public WeaponStrategy {
public:
	virtual void UseWeapon()
	{
		cout << "是用AK47" << endl;
	}
};

class Character {
public:
	void setWeapon(WeaponStrategy* weapon)
	{
		pWeapon = weapon;
	}
	void throwWeapon()
	{
		pWeapon->UseWeapon();
	}
private:
	WeaponStrategy* pWeapon;
};

void test01()
{
	Character* character = new Character;

	WeaponStrategy* knife = new Knife;
	WeaponStrategy* Ak47 = new AK47;
	character->setWeapon(knife);
	character->throwWeapon();

	character->setWeapon(Ak47);
	character->throwWeapon();

	delete knife;
	delete Ak47;
	delete character;

}

int main()
{
	test01();
	return 0;
}