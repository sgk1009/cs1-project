
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <fstream>
using namespace std;

	//establish all the needed variables
	const int size=6;
	enum typeAccount{Business=0,Personal=1};
	enum Menu{Add=1,Remove=2,Process=3,Display=4,Quit=5};
	struct Account{
		string name;
		string number;
	};
	
	

	string getName(string userName);
	string getAccountNumber();
	int getNumberofTransactions(string fileName);
	int getNumberofAccounts(string fileName);
	void addAccount();
	void removeAccount(string removeAcctNum);
	double getCurrentBalance(string balanceNum, typeAccount acctChoice);
	void writeTransactions(string transacNum, typeAccount acctChoice);
	void displayAccount(string displayNum);
	void processAccount(string processNum);