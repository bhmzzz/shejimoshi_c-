#include<iostream>
#include<vector>
using namespace std;
//�����ط��� �ֽ�����֪ʶԭ��
class AbstractBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;

};

//¥��A
class BuildingA : public AbstractBuilding {
public:
	BuildingA()
	{
		mQuilty = "��Ʒ��";
	}
	virtual void sale()
	{
		cout << "¥��A" << mQuilty << "������" << endl;
	}
	virtual string getQuality()
	{
		return mQuilty;
	}
public:
	string mQuilty;
};

//¥��B
class BuildingB : public AbstractBuilding {
public:
	BuildingB()
	{
		mQuilty = "��Ʒ��";
	}
	virtual void sale()
	{
		cout << "¥��B" << mQuilty << "������" << endl;
	}

	virtual string getQuality()
	{
		return mQuilty;
	}
public:
	string mQuilty;
};

//�ͻ��˵��á�
void test01()
{
	BuildingA* ba = new BuildingA;
	if (ba->mQuilty == "��Ʒ��")
	{
		ba->sale();
	}
	BuildingB* bb = new BuildingB;
	if (bb->mQuilty == "��Ʒ��")
	{
		bb->sale();
	}
}

//�н���
class Mediator {
public:
	Mediator()
	{
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		 building = new BuildingB;
		 vBuilding.push_back(building);
	}

	//�����ṩ�ӿ�
	AbstractBuilding* findMyBuilding(string quality)
	{
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if ((*it)->getQuality() == quality)
				return *it;
			else
				return nullptr;
		}
	}

	~Mediator()
	{
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if (*it != NULL)
				delete* it;
		}
	}
public:
	vector<AbstractBuilding*> vBuilding;

};

void test02()
{
	Mediator* mediator = new Mediator;
	AbstractBuilding* building =  mediator->findMyBuilding("��Ʒ��");
	if (building != nullptr)
	{
		building->sale();
	}
	else {
		cout << "û��������¥��" << endl;
	}
}

int main()
{
	test01();
	return 0;
}