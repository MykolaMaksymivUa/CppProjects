#include "Database.h"



Database::Database()
{

}

void Database::PrintTypes()
{
	string line;
	ifstream myfile;
	myfile.open("TypeOfInsurance.txt"); 
		if(myfile.is_open()) 
		{
			while (!myfile.eof())
			{
				getline(myfile, line);
				cout << line << endl;
			}
		}
		else
		{
			cout << "file not found";
		}
	myfile.close();
}




Database::~Database()
{
}
