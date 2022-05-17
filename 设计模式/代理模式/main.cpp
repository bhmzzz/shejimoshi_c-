#include<iostream>
using namespace std;

//����ģʽ �ṩһ�ַ�ʽ�����ƶ���������ķ���

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface{
public:
	virtual void run()
	{
		cout << "ϵͳ����..." << endl;
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
			cout << "��֤ͨ��" << endl;
		}
		else
		{
			cout << "�û��������������Ȩ�޲���" << endl;
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

//������ҪȨ����֤���������������������ϵͳ���ṩ�û���������


void test01()
{
	MySystemProxy* proxy = new MySystemProxy("admin","admin");
	proxy->run();
}

int main()
{
	return 0;
}