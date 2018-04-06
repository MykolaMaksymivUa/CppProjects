#pragma once
#include "Agency.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <random>
using namespace std;

class Client :virtual public Agency
{
protected:
	string term;
	string name;

	

	
public:
	
	Client();
	void SetFirst();
	void SetSecond();
	void SetThird();
	void SetFourth();

	virtual void Agency::showmenu()
	{
		cout << "*********************************************************************************************************" << endl;
		cout << "*                                                                                                       *" << endl;
		cout << "*                                           WELCOME to Insurance Agency                                 *" << endl;                                  
		cout << "*                                                                                                       *" << endl;
		cout << "*********************************************************************************************************" << endl;
		cout << "\t\t 1.For Current client" << endl;
		cout << "\t\t 2.For New client" << endl;
		cout << "\t\t 3.You are agent" << endl;
		cout << "\t\t 4.Exit" << endl;
	}
	int MenuForNEwClient();
	bool CheckPass();
	void DeleteDeal();
	void ContDeal(fstream &os, fstream &s);
	void ShowDocs(fstream &os, fstream &s);
	void SetType(unsigned int m_type)
	{
		type = m_type;
	}
	void AddClient(string TYPE);
	virtual void Agency::showmethodsOLD()
	{
		cout << "1.Cancel the contract" << endl;
		cout << "2.Continue contract with our Insurance Agency"<<endl;
		cout << "3.Check Contract" << endl;
		cout << "4.Exit" << endl;
		cout << "5.Clear screen" << endl;
	}
	
	~Client();
};

