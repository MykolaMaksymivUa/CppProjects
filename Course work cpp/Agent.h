#pragma once
#include <iostream>
#include <string>
#include "Client.h"
using namespace std;
class Agent: public Client
{
protected:
	string Agentsname;
public:
	Agent();

	int AgentsMenu();

	bool CheckFirst();
	bool CheckSecond();
	bool CheckThird();
	bool CheckFourth();
	~Agent();

};

