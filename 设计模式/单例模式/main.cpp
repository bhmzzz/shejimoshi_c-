#include<iostream>
using namespace std;

//���ʵ�ֵ���
class A {
private:
	A() {
		a = new A;
	}
public:
	static A* getInstance()
	{
		return a;
	}
private:
	static A* a;
};

A* A::a = NULL;

//���� ��Ϊ����ʽ ����ʽ
class Singleton_lazy {
private:
	Singleton_lazy() {}
public:
	static Singleton_lazy* GetInstance() {
		if (pSingleton == nullptr)
		{
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
private:
	static Singleton_lazy* pSingleton;
};

Singleton_lazy*  Singleton_lazy::pSingleton = nullptr;

//����ʽ
class Singleton_hungry {
private:
	Singleton_hungry() {}
public:
	static Singleton_hungry* GetInstance() {
		return pSingleton;
	}
#if 0
	static void freeSpace() {
		if (pSingleton != nullptr)
			delete pSingleton;
	}
#endif

	class Garbo {
		~Garbo() {
			if (pSingleton != nullptr) {
				delete pSingleton;
			}
		}
	};
private:
	static Singleton_hungry* pSingleton;
	static Garbo garbo;
};

Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

void test02() {
	Singleton_hungry::freeSpace();
}

int main()
{
	A::getInstance();
	return 0;
}

//1�����캯��˽�л�
//2�����Ӿ�̬˽�еĵ�ǰ���ָ�����
//3���ṩ��̬����ӿڣ��������û���õ�������