#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct MyPrint {
	void operator()(int v1,int v2) {
		cout << v1 + v2 << endl;
	}
};

//定义目标接口 我要适配成什么样的
class Target {
public:
	virtual void operator()(int v) = 0;
};

//写适配器
class Adapter : public Target {
public:
	Adapter(int param):mparam(param) {}
	virtual void operator()(int v) {
		print(v, mparam);
	}
private:
	MyPrint print;
	int mparam;
};

//MyBind2nd
Adapter MyBind2nd(int v)
{
	return Adapter(v);
}

int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i+1);
	}
	for_each(v.begin(), v.end(), MyBind2nd(10));
	return 0;
}