#include "Client.h"



Client::Client() :Agency() {
	
};
int Client::MenuForNEwClient()
{
	cout << "1.Print contract" << endl;
	cout << "2.Back to insurance types menu" << endl;
	cout << "3.Exit" << endl;

	int chose;
	unsigned int newclientchoice;
pointnewclientchoice:cout << "Please,enter your choice:";
	cin >> newclientchoice;
	if (newclientchoice == 1)
	{
		fstream infile("Database.txt", ios::in);
		fstream outfile("docs.txt");
		ShowDocs(infile, outfile);
		infile.close();
		outfile.close();
		goto pointnewclientchoice;
	}
	if (newclientchoice == 2)
		chose = 2;
	if (newclientchoice == 3)
		chose = 3;
	return chose;
}

void Client::DeleteDeal()
{
	std::ifstream file_in;

	file_in.open("Database.txt");

	if (!file_in)
	{
		std::cerr << "Cann't enter the file : Database.txt" << std::endl;
		
	}

	
	int i_number_line_delete = ID; //для зберігання  номера строки яку треба удалити


	int i_number_line_now = 0; //рахунок строк
	std::string line; //для зберігання строки
	std::string line_file_text; //для зберігання текста файла

	while (getline(file_in, line))
	{
		i_number_line_now++;

		if (!(i_number_line_now == i_number_line_delete))
		{
			line_file_text.insert(line_file_text.size(), line); /*дабавити строку*/
																/*добавити перенос на наступну строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");

		}
	}

	file_in.close();

	//перезапис файлу без строки

	std::ofstream file_out;

	file_out.open("Database.txt", std::ios::trunc | std::ios::binary); //відкрити і обрізать

																   //записати

	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();
	cout << "Deal was canceled!" << endl;
}

void Client::ContDeal(fstream &os, fstream &s)
{
	int k;
	cout << "Enter ID again:";
	cin >> k;
	int plus;
	cout << "Enter please a number of years:";
	cin >> plus;
	while (!os.eof())
	{

		os >> ID;
		os >> name;
		os >> type;
		os >> term;

		if (ID == k && !os.eof())
		{
			int date = stoi(term) + plus;
			s << "   "<<ID  << "     " << name<<"                 "<< type<<"           " << date << "/" << term << endl;//setw2,setw4,setw18,setw11
			os.close();
			s.close();

		}

	}

}

void Client::SetFirst()
{
	
	cout << "/t Welcome to the insurance company. Please fill in the application .\n \t______________________________ Your application______________________________" << endl;
	cout << "Your name:";
	cin >> name;
	cout << "Price of goods (property) in hryvnias:";
	cin >> price;
	cout << "The term, during which you are subject to insurance:";
	cin >> GlobalData;
	cout << "You have to pay, depending on conditions, insurance tax:";
	cin >> vznos;
	cout << "__________________________________________________________________________________________" << endl;
	
}

void Client::SetSecond()
{
	cout << "/t Welcome to the insurance company. Please fill in the application .\n \t______________________________ Your application______________________________" << endl;
	cout << "Your name:";
	cin.get();
	getline(cin, name);
	cout << "Your physical age:";
	cin >> age;
	cout << "The term, during which you are subject to insurance:";
	cin >> GlobalData;
	cout << "You have to pay, depending on conditions, insurance tax:";
	cin >> vznos;
	cout << "__________________________________________________________________________________________" << endl;

	

}

void Client::SetThird()
{
	cout << "/t Welcome to the insurance company. Please fill in the application .\n \t______________________________ Your application______________________________" << endl;
	cout << "Your name:";
	cin.get();
	getline(cin, name);
	cout << "Enter the year of issue of the car:";
	cin >> machine;
	cout << "The term, during which your auto are subject to insurance:";
	cin >> GlobalData;
	cout << "You have to pay, depending on conditions, insurance tax:";
	cin >> vznos;
	cout << "__________________________________________________________________________________________" << endl;

}

void Client::SetFourth()
{
	cout << "/t Welcome to the insurance company. Please fill in the application .\n \t______________________________ Your application______________________________" << endl;
	cout << "Your name:";
	cin.get();
	getline(cin, name);
	cout << "Estimation of real estate that is subject to insurance in hryvnias:";
	cin >> price;
	cout << "The term, during which you are subject to insurance:";
	cin >> GlobalData;
	cout << "You have to pay, depending on conditions, insurance tax:";
	cin >> vznos;
	cout << "__________________________________________________________________________________________" << endl;

}

void Client::AddClient(string TYPE)
{
	srand(time(NULL));
	type = TYPE;
	ofstream file("Database.txt",ios::app);
	int year = 2017;
	ID = (rand() % 10)+7;
	string const monthday = ".05.13.";
	file << "   " << ID << "      " << name << "                    " << type << "           " << (year + GlobalData)<< monthday << endl;
	file.close();


}

bool Client::CheckPass()
{
	cout << "Enter your ID:";
	ifstream file("Database.txt"); // открыли файл с текстом
	string s,find;
	bool password = false;
	char c;
	int tries = 3;

	while (!file.eof()) 
	{  // прочитали его и заполнили им строку
		file.get(c);
		s.push_back(c);
	}

	file.close(); // обязательно закрыли

	p1:cin >> find;

	int pos = s.find(find); // поиск

	if (pos == -1)
	{
		cout << "Not finded the same pass!Try again:" << endl;
		tries--;
		if (tries != 0)
			goto p1;
		
	}

	else
	{
		password = true;
		ID = stoi(find);
		
	}
	
	return password;
}

void Client::ShowDocs(fstream &os, fstream &s)
{
	int k;
	cout << "Enter Client's ID :";
	cin >> k;

	while (!os.eof())
	{

		os >> ID;
		os >> name;
		os >> type;
		os >> term;

		if (ID == k && !os.eof())
		{
			ID == k;
			cout << "---------------------------------------------------DOCUMENT-------------------------------------------------------------" << endl;
			cout << " Client " << name << " concluded with the insurance company \"KI\" contract. \n MR "<<name<<" choose the type of insurance " << type;
			cout << ".\n This deal are up to date. " << term <<" All rights are served."<<endl;
			cout << "Client " << name << "                                                           Insurance Agent Ivasiv Andriy" << endl;
			cout<<"------------------------------------------------------------------------------------------------------------------------" << endl;



			s << "---------------------------------------------------DOCUMENT-------------------------------------------------------------" << endl;
			s << " Client " << name << " concluded with the insurance company \"KI\" contract. \n MR " << name << " choose the type of insurance " << type;
			s << ".\n This deal are up to date " << term << ". All rights are served." << endl;
			s << "Client " << name << "                                                           Insurance Agent Ivasiv Andriy" << endl;
			s << "------------------------------------------------------------------------------------------------------------------------" << endl;
			s << endl;


		}

	}



}
Client::~Client()
{
}
