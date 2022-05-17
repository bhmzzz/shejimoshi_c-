#include<iostream>
using namespace std;

//дһ��������
class AbstractCaculator {
public:
	virtual int getResult() = 0;
	virtual void setOperatorNumber(int a, int b) = 0;
};
//�ӷ�������
class PlusCaculator : public AbstractCaculator
{
public:
	virtual void setOperatorNumber(int a,int b)
	{
		mA = a;
		mB = b;
	}
	virtual int getResult()
	{
		return mA + mB;
	}
public:
	int mA;
	int mB;

};

//����������
class MinuteCaculator : public AbstractCaculator
{
public:
	virtual void setOperatorNumber(int a, int b)
	{
		mA = a;
		mB = b;
	}
	virtual int getResult()
	{
		return mA - mB;
	}
public:
	int mA;
	int mB;
};

//�˷�������
class MultiplyCaculator : public AbstractCaculator
{
public:
	virtual void setOperatorNumber(int a, int b)
	{
		mA = a;
		mB = b;
	}
	virtual int getResult()
	{
		return mA * mB;
	}
public:
	int mA;
	int mB;
};

void test01()
{
	AbstractCaculator* caculator = new PlusCaculator;
	caculator->setOperatorNumber(10, 20);
	cout << caculator->getResult() << endl;
}

int main()
{
	test01();
	return 0;
}