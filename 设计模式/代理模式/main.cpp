#include<iostream>
using namespace std;

//代理模式 提供一种方式来控制对其他对象的访问

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface{
public:
	virtual void run()
	{
		cout << "系统启动..." << endl;
	}
};

class MySystemProxy : public AbstractCommonInterface {
public:
	MySystemProxy(string username,string password)
	{
		mUsername = username;
		mPassword = password;
		pSystem = new MySystem;
	}

	bool checkUsernameAndPassword()
	{
		if (mUsername == "admin" && mPassword == "admin")
		{
			return true;
		}
		return false;
	}

	virtual void run()
	{
		if (checkUsernameAndPassword() == true)
		{
			this->pSystem->run();
			cout << "验证通过" << endl;
		}
		else
		{
			cout << "用户名或者密码错误，权限不足" << endl;
		}
	}
	~MySystemProxy()
	{
		if (pSystem != nullptr)
		{
			delete pSystem;
		}
	}
public:
	MySystem* pSystem;
	string mUsername;
	string mPassword;
};

//必须有要权限验证，不是所有人能启动这个系统，提供用户名和密码


void test01()
{
	MySystemProxy* proxy = new MySystemProxy("admin","admin");
	proxy->run();
}

int main()
{
	return 0;
}