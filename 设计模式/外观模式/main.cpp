#include<iostream>
using namespace std;

class TV {
public:
	void On() {
		cout << "开" << endl;
	}
	void Off() {
		cout << "关" << endl;
	}
};

class Light {
public:
	void On() {
		cout << "开" << endl;
	}
	void Off() {
		cout << "关" << endl;
	}
};

class Audio {
public:
	void On() {
		cout << "开" << endl;
	}
	void Off() {
		cout << "关" << endl;
	}
};

class Mircophone {
public:
	void On() {
		cout << "开" << endl;
	}
	void Off() {
		cout << "关" << endl;
	}
};

class DVD {
public:
	void On() {
		cout << "开" << endl;
	}
	void Off() {
		cout << "关" << endl;
	}
};

class Gamemachine {
public:
	void On() {
		cout << "开" << endl;
	}
	void Off() {
		cout << "关" << endl;
	}
};

class SelectMode {
public:
	SelectMode() {
		pTv = new TV;;
		pLight = new Light;
		pAudio = new Audio;
		pMircophone = new Mircophone;
		pDvd = new DVD;
	}

	void OnKTV()
	{
		pTv->On();
		pLight->Off();
		pAudio->On();
		pMircophone->On();
		pDvd->On();
	}
	void OffKTV()
	{
		pTv->Off();
		pLight->On();
		pAudio->Off();
		pMircophone->Off();
		pDvd->Off();
	}

	~SelectMode()
	{
		delete pTv;
		delete pLight;
		delete pAudio;
		delete pMircophone;
		delete pDvd;
	}
private:
	TV* pTv;
	Light* pLight;
	Audio* pAudio;
	Mircophone* pMircophone;
	DVD* pDvd;
};

void test01() {
	SelectMode* ktv = new SelectMode;
	ktv->OnKTV();
}

int main()
{
	test01();
	return 0;
}