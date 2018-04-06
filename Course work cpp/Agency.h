#pragma once
#include <iostream>
#include <string>
using namespace std;
class Agency
{
protected:
	int ID, GlobalData;
	double vznos, price;
	unsigned int  age, machine;
	string type;
public:
	Agency();
	virtual void showmenu() = 0;
	virtual void showmethodsOLD() = 0;
	~Agency();
};

