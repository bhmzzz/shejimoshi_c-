#include<iostream>
#include<vector>
using namespace std;
//迪米特法则 又叫最少知识原则
class AbstractBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;

};

//楼盘A
class BuildingA : public AbstractBuilding {
public:
	BuildingA()
	{
		mQuilty = "高品质";
	}
	virtual void sale()
	{
		cout << "楼盘A" << mQuilty << "被售卖" << endl;
	}
	virtual string getQuality()
	{
		return mQuilty;
	}
public:
	string mQuilty;
};

//楼盘B
class BuildingB : public AbstractBuilding {
public:
	BuildingB()
	{
		mQuilty = "低品质";
	}
	virtual void sale()
	{
		cout << "楼盘B" << mQuilty << "被售卖" << endl;
	}

	virtual string getQuality()
	{
		return mQuilty;
	}
public:
	string mQuilty;
};

//客户端调用。
void test01()
{
	BuildingA* ba = new BuildingA;
	if (ba->mQuilty == "低品质")
	{
		ba->sale();
	}
	BuildingB* bb = new BuildingB;
	if (bb->mQuilty == "低品质")
	{
		bb->sale();
	}
}

//中介类
class Mediator {
public:
	Mediator()
	{
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		 building = new BuildingB;
		 vBuilding.push_back(building);
	}

	//对外提供接口
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
	AbstractBuilding* building =  mediator->findMyBuilding("高品质");
	if (building != nullptr)
	{
		building->sale();
	}
	else {
		cout << "没有这样的楼盘" << endl;
	}
}

int main()
{
	test01();
	return 0;
}