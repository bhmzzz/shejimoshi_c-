#include<iostream>
using namespace std;

class BankWorker {
public:
	void SaveService() { cout << "办理存款业务..."; }
	void payService() { cout << "办理支付业务..."; }
	void TransService() { cout << "办理转账业务..."; }
};

//中层模块
void doSaveBussiness(BankWorker* worker) {
	worker->SaveService();
}
void dopayService(BankWorker* worker) {
	worker->payService();
}
void doTransService(BankWorker* worker) {
	worker->TransService();
}

void test01()
{
	BankWorker* worker = new BankWorker;
	doSaveBussiness(worker);
	dopayService(worker);
	doTransService(worker);
}

class AbstractWorker {
public:
	virtual void doBusiness() = 0;
};

class SaveBankWorker : public AbstractWorker {
public:
	void doBusiness()
	{
		cout << "办理存款业务...";
	}
};

class PayBankWorker : public AbstractWorker {
public:
	void doBusiness()
	{
		cout << "办理支付业务...";
	}
};

class TransBankWorker : public AbstractWorker {
public:
	void doBusiness()
	{
		cout << "办理转账业务...";
	}
};

//中层业务
void doNewBusiness(AbstractWorker* aw)
{
	aw->doBusiness();
}

void test02() {
	AbstractWorker* transfer = new TransBankWorker;
	doNewBusiness(transfer);
	delete transfer;
}

int main()
{
	test02(); 
	return 0;
}