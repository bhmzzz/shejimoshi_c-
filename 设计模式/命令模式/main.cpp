#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;

//协议处理类
class HandleClientProtocol {
public:
	//处理增加金币
	void AddMoney() {
		cout << "给玩家增加金币" << endl;
	}
	//处理增加钻石
	void AddDiamond() {
		cout << "给玩家增加钻石" << endl;
	}
	//处理玩家装备
	void AddEquipment() {
		cout << "给玩家穿装备" << endl;
	}
	//处理玩家升级
	void AddLevel() {
		cout << "给玩家升级" << endl;
	}
};

//命令接口
class AbstractCommand {
public:
	virtual void handle() = 0;//处理客户端请求的接口
};

//处理增加金币请求
class AddMoneyCommand : public AbstractCommand {
public:
	AddMoneyCommand(HandleClientProtocol* Protocol)
	{
		pProtocol = Protocol;
	}
	virtual void handle() 
	{
		pProtocol->AddMoney();
	}
private:
	HandleClientProtocol* pProtocol;
};

class AddDiammondCommand : public AbstractCommand {
public:
	AddDiammondCommand(HandleClientProtocol* Protocol)
	{
		pProtocol = Protocol;
	}
	virtual void handle()
	{
		pProtocol->AddDiamond();
	}
private:
	HandleClientProtocol* pProtocol;
};

class AddEquipmentCommand : public AbstractCommand {
public:
	AddEquipmentCommand(HandleClientProtocol* Protocol)
	{
		pProtocol = Protocol;
	}
	virtual void handle()
	{
		pProtocol->AddEquipment();
	}
private:
	HandleClientProtocol* pProtocol;
};

class AddLevelCommand : public AbstractCommand {
public:
	AddLevelCommand(HandleClientProtocol* Protocol)
	{
		pProtocol = Protocol;
	}
	virtual void handle()
	{
		pProtocol->AddLevel();
	}
private:
	HandleClientProtocol* pProtocol;
};


//服务器程序
class Server {
public:
	void addRequest(AbstractCommand* command)
	{
		mCommand.push(command);
	}
	void startHandle()
	{
		while (!mCommand.empty())
		{
			AbstractCommand* command = mCommand.front();
			command->handle();
			Sleep(2000);
			mCommand.pop();
		}
	}
private:
	queue<AbstractCommand*> mCommand;
};

void test01()
{
	HandleClientProtocol* protocol = new HandleClientProtocol;
	//客户端增加金币的请求
	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
	//客户端增加钻石的请求
	AbstractCommand* adddiamond = new AddDiammondCommand(protocol);

	Server* server = new Server;
	server->addRequest(addmoney);
	server->addRequest(adddiamond);

	server->startHandle();
}

int main()
{
	test01();
	return 0;
}

