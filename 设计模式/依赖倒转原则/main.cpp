#include<iostream>
using namespace std;

class BankWorker {
public:
	void SaveService() { cout << "������ҵ��..."; }
	void payService() { cout << "����֧��ҵ��..."; }
	void TransService() { cout << "����ת��ҵ��..."; }
};

//�в�ģ��
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
		cout << "������ҵ��...";
	}
};

class PayBankWorker : public AbstractWorker {
public:
	void doBusiness()
	{
		cout << "����֧��ҵ��...";
	}
};

class TransBankWorker : public AbstractWorker {
public:
	void doBusiness()
	{
		cout << "����ת��ҵ��...";
	}
};

//�в�ҵ��
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