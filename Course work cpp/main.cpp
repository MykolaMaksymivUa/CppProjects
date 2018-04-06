#include <iostream>
#include "Client.h"
#include <fstream>
#include "Database.h"
#include "Agent.h"

using namespace std;





int main()
{
	setlocale(LC_ALL, "Ukr");
	Client obj;
	obj.showmenu();
	Database info;
	Agent agent;
	



	while (true)
	{
		int choice;

	    cin >> choice;

		if (choice == 2)//новий клієнт ----------gotovo!!!
		{
			cout << info;
			unsigned int m_type;
			newtypes:info.PrintTypes();
			cout << "_________________________________________________________________________________________________________________" << endl;
			cin >> m_type;
			obj.SetType(m_type);

			switch (m_type)
			{
			case 1:system("cls");
				cout << "You choose the type of property insurance" << endl;
				agent.SetFirst();
				if (agent.CheckFirst() == true)
				{
					agent.AddClient("property_insurance");
					if (obj.MenuForNEwClient() == 2)
						goto newtypes;
					else cout << "Error" << endl;
					if (obj.MenuForNEwClient() == 3)
						break;
					else cout << "Error" << endl;
				}
				else 
				{
					cout << "Try again fill out an application!!!" << endl;
					agent.SetFirst();
					if (agent.CheckFirst() == true)
					{
						agent.AddClient("property_insurance");
						if (obj.MenuForNEwClient() == 2)
							goto newtypes;
						else cout << "Error" << endl;
						if (obj.MenuForNEwClient() == 3)
							break;
						else cout << "Error" << endl;
					}
					else {
						cout << "Come back to the next time!!!" << endl;
						break;
					}
				}
			case 2:
				system("cls");
				cout << "You choose the type of medical insurance" << endl;
				agent.SetSecond();
				if (agent.CheckSecond() == true)
				{
					agent.AddClient("medical insurance");
					if (obj.MenuForNEwClient() == 2)
						goto newtypes;
					else cout << "Error" << endl;
					if (obj.MenuForNEwClient() == 3)
						break;
					else cout << "Error" << endl;
				}
				else
				{
					cout << "Try again fill out an application!!!" << endl;
					agent.SetSecond();
					if (agent.CheckSecond() == true)
					{
						agent.AddClient("medical insurance");
						if (obj.MenuForNEwClient() == 2)
							goto newtypes;
						else cout << "Error" << endl;
						if (obj.MenuForNEwClient() == 3)
							break;
						else cout << "Error" << endl;
					}
					else {
						cout << "Come back to the next time!!!" << endl;
						break;
					}
				}
			case 3:system("cls");
				cout << "You choose the type of KASKO insurance" << endl;
				agent.SetThird();
				if (agent.CheckThird() == true)
				{
					agent.AddClient("KASKO insurance");
					if (obj.MenuForNEwClient() == 2)
						goto newtypes;
					else cout << "Error" << endl;
					if (obj.MenuForNEwClient() == 3)
						break;
					else cout << "Error" << endl;
				}
				else
				{
					cout << "Try again fill out an application!!!" << endl;
					agent.SetThird();
					if (agent.CheckThird() == true)
					{
						agent.AddClient("KASKO insurance");
						if (obj.MenuForNEwClient() == 2)
							goto newtypes;
						else cout << "Error" << endl;
						if (obj.MenuForNEwClient() == 3)
							break;
						else cout << "Error" << endl;
					}
					else {
						cout << "Come back to the next time!!!" << endl;
						break;
					}
				}
			case 4:system("cls");
				cout << "You selected  real estate insurance" << endl;
				agent.SetFourth();
				if (agent.CheckFourth() == true)
				{
					agent.AddClient("real estate insurance");
					if (obj.MenuForNEwClient() == 2)
						goto newtypes;
					else cout << "Error" << endl;
					if (obj.MenuForNEwClient() == 3)
						break;
					else cout << "Error" << endl;
				}
				else
				{
					cout << "Try again fill out an application!!!" << endl;
					agent.SetFourth();
					if (agent.CheckFourth() == true)
					{
						agent.AddClient("real estate insurance");
						if (obj.MenuForNEwClient() == 2)
							goto newtypes;
						else cout << "Error" << endl;
						if (obj.MenuForNEwClient() == 3)
							break;
						else cout << "Error" << endl;
					}
					else {
						cout << "Come back to the next time!!!" << endl;
						break;
					}
				}
				
			default:cout << "Enter pls number!!!" << endl;
				break;
			}
			

		}

		if (choice == 1) //існуючий клієнт------gotovo
		{
			if (obj.CheckPass() == true)
			{
				int newchoice;
				pp1:obj.showmethodsOLD();
				cin >> newchoice;
				if (newchoice == 3)
				{
					fstream infile("Database.txt", ios::in);
                 	fstream outfile("docs.txt");
					obj.ShowDocs(infile, outfile);
					infile.close();
					outfile.close();
					goto pp1;
				}
				if (newchoice == 1)
				{
					obj.DeleteDeal();
					goto pp1;
				}


				if (newchoice == 2)
				{
					fstream infile("Database.txt", ios::in);
					fstream outfile("Database.txt", ios::app);
					obj.ContDeal(infile, outfile);
					cout << "Your contract extended. Thanks for your cooperation" << endl;
					goto pp1;

				}
				if (newchoice == 4)
					break;
				if (newchoice == 5)
				{
					system("cls");
					goto pp1;
				}
			}
			else cout << "Enter pls number!" << endl;;
			break;

			
			/*1)метод чекпас перевіряє пароль,якщо так-продовж роботу
			2)Випадає меню ,де К може вибрати свої методи
			
			*/
		}
		if (choice == 3)//(бета) вибір страхового агента
		{
			if (agent.AgentsMenu() == 5)
				break;
			

        }
		if (choice == 4)
			break;
	}







	system("pause");
	return 0;

}