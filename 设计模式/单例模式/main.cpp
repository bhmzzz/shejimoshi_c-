#include<iostream>
using namespace std;

//如何实现单例
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

//单例 分为懒汉式 饿汉式
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

//饿汉式
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

//1、构造函数私有化
//2、增加静态私有的当前类的指针变量
//3、提供静态对外接口，可以让用户获得单例对象