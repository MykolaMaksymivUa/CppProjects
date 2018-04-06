#include "Agent.h"




Agent::Agent()
{
}

bool Agent::CheckFirst()//problems!!!!
{
	bool isHave = false;
	if (price > 10000)
	{
		if (GlobalData <= 20)
		{
			if (vznos >= (price / 100))
			{
				cout << "Congratulations, you have completed all conditions!!!" << endl;
				isHave = true;
			}
			else
			{
				cout << "You make a mistake in the application!!!" << endl;
				isHave = false;
			}
		}
		else {
			cout << "You make a mistake in the application!!!" << endl;
			isHave = false;
		}
	}
	else
	{
		if (GlobalData <= 10)
		{
			if (vznos >= ((price * 3) / 100))
			{
				cout << "Congratulations, you have completed all conditions!!!" << endl;
				isHave = true;
			}
			else {
				cout << "You make a mistake in the application!!!" << endl;
				isHave = false;
			}
		}
		else {
			cout << "You make a mistake in the application!!!" << endl;
			isHave = false;
		}


	}
	return isHave;

}
bool Agent::CheckThird()
{
	bool isHave = false;
	if ((machine >= 1995) && (machine <= 2017))
		if (GlobalData <= 2)
			if (vznos >= 1000)
			{
				cout << "Congratulations, you have completed all conditions!!!" << endl;
				isHave = true;
			}
			else
			{
				cout << "You make a mistake in the application!!!" << endl;
				isHave = false;
			}
		else {
			cout << "You make a mistake in the application!!!" << endl;
			isHave = false;
		}
	else {
		cout << "You make a mistake in the application!!!" << endl;
		isHave = false;
	}

	return isHave;
}

bool Agent::CheckFourth()
{
	bool isHave = false;

	if (vznos >= (GlobalData*0.25 * 1200))
		if (GlobalData <= 50)
		{
			cout << "Congratulations, you have completed all conditions!!!" << endl;
			isHave = true;
		}
		else {
			cout << "You make a mistake in the application!!!" << endl;
			isHave = false;
		}
	else {
		cout << "You make a mistake in the application!!!" << endl;
		isHave = false;
	}

	return isHave;
}

bool Agent::CheckSecond()
{
	bool isHave = false;
	if (age < 45)
		if (age > 7)
			if (GlobalData <= 7)
				if (vznos >= 2400)
				{
					cout << "Congratulations, you have completed all conditions!!!" << endl;
					isHave = true;
				}
				else
				{
					cout << "You make a mistake in the application!!!" << endl;
					isHave = false;
				}
			else
			{
				cout << "You make a mistake in the application!!!" << endl;
				isHave = false;
			}
		else {
			cout << "You make a mistake in the application!!!" << endl;
			isHave = false;
		}

	else {
		cout << "You make a mistake in the application!!!" << endl;
		isHave = false;
	}



	return isHave;
}

int Agent::AgentsMenu()
{
	system("cls");
	int agentschoice, vozvrat = 0;
	cout << "Please,enter your name:";
	cin >> Agentsname;
	cout << "Good day,Mr " << Agentsname << endl;
	cout << "                                             Agent's menu                                                 " << endl;
	cout << "**********************************************************************************************************" << endl;
	cout << "* 1.Delete client from Database                                                                          *" << endl;
	cout << "* 2.Add client                                                                                           *" << endl;
	cout << "* 3.Check contract                                                                                       *" << endl;
	cout << "* 4.Ñalculate insurance payment                                                                          *" << endl;
	cout << "* 5.Exit                                                                                                 *" << endl;
	cout << "**********************************************************************************************************" << endl;

	cout << "Mr " << Agentsname << " choose the direct options,which you need:";
	cin >> agentschoice;
	if (agentschoice == 1)
	{
		cout << "Enter ID of this client:";
		cin >> ID;
		cout << "ID " << ID;
		DeleteDeal();

	}
	if (agentschoice == 2)
	{
	
		ofstream file("Database.txt", ios::app);
		cout << "Enter name of client:";
		cin >> name;
		cout << "Enter client's ID:";
		cin >> ID;
		cout << "Enter type of insurance:";
		cin >> type;
		cout << "Enter date of ending contract:";
		cin >> term;
		file << "   " << ID << "      " << name << "                    " << type << "           " <<term<< endl;
		file.close();
	}
	if (agentschoice == 3)
	{
		fstream infile("Database.txt", ios::in);
		fstream outfile("docs.txt");
		ShowDocs(infile, outfile);
		infile.close();
		outfile.close();
	}
	if (agentschoice == 5)
		vozvrat = 5;
	return vozvrat;
}

Agent::~Agent()
{
}
