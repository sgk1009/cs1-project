	#include "Project3_header.h"



int main()
{	

	int nameIndex=0;
	
	
	
	
	int accountType; //desired account type for the switchcase
	double transaction; //transaction amount
	
	int menu;
	
	bool check=true; //to stop/continue all the loops
	Menu menuOption;
	string fileName;
	string removeAcctNum;
	string displayNum;
	string processNum;
	
	
	
		// name,euid,email,department name and course number
	cout<<"+--------------------------------------------------------+"<<endl;
	cout<<"|	Computer Science and Engineering 		 |"<<endl;
	cout<<"|	CSCE 1030 section 303 Computer Science I 	 |"<<endl;
	cout<<"+--------------------------------------------------------+"<<endl;

	do{
		do{
			
			cout<<"1.Add Account"<<endl;
			cout<<"2.Remove Account"<<endl;
			cout<<"3.Process Accounts"<<endl;
			cout<<"4.Display Account Information"<<endl;
			cout<<"5.Quit"<<endl;
			cout<<"Enter your choice:";
			cin>>menu;
			if(menu!= 1 && menu!= 2 && menu !=3 && menu !=4 && menu !=5)
			{
				cout<<"Wrong choice. Please enter again."<<endl;
			}
		}while(menu!= 1 && menu!= 2 && menu !=3 && menu !=4 && menu !=5);
	menuOption=static_cast<Menu>(menu);
	switch(menuOption){
		case Add:
		addAccount();
		check=false;
		break;
		case Remove:
		cout<<"Enter account number to remove:";
		cin>>removeAcctNum;
		removeAccount(removeAcctNum);
		check=false;
		break;
		case Process:
		cout<<"Enter account number to process:";
		cin>>processNum;
		processAccount(processNum);
		check=false;
		break;
		case Display:
		cout<<"Enter account number to display:";
		cin>>displayNum;
		displayAccount(displayNum);
		check=false;
		break;
		case Quit:
		cout<<"Goodbye!"<<endl;
		check=true;
		break;
	}
	}while(!check);
	return 0;
}
