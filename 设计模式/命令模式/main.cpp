#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;

//Э�鴦����
class HandleClientProtocol {
public:
	//�������ӽ��
	void AddMoney() {
		cout << "��������ӽ��" << endl;
	}
	//����������ʯ
	void AddDiamond() {
		cout << "�����������ʯ" << endl;
	}
	//�������װ��
	void AddEquipment() {
		cout << "����Ҵ�װ��" << endl;
	}
	//�����������
	void AddLevel() {
		cout << "���������" << endl;
	}
};

//����ӿ�
class AbstractCommand {
public:
	virtual void handle() = 0;//����ͻ�������Ľӿ�
};

//�������ӽ������
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


//����������
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
	//�ͻ������ӽ�ҵ�����
	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
	//�ͻ���������ʯ������
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

