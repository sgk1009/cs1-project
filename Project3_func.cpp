	
	#include "Project3_header.h"
	
	//function for account name
	string getName(string userName){
	bool check=true; //to stop/continue all the loops
	do
	{
		cout<<"Enter your name:";
		cin.ignore();
		getline(cin,userName);
			for(int nameIndex=0;nameIndex<userName.length();++nameIndex)
			{
				
				if(!isalpha(userName.at(nameIndex))&&!isspace(userName.at(nameIndex))) //checks for special characters
				{
					check=false;
					cout<<"Your name can only contain letters or spaces.PLease try again."<<endl;
					break; //stops loop
				}
				else
				{
					check=true; //keeps the loop going
				}
				
			}
	
	}while(!check);
	userName.at(0)=toupper(userName.at(0)); //capitalize's the first initial
	for(int i=1;i<userName.length();++i)
	{
		if(isspace(userName.at(i-1))) //finds spaces and then capatilizes the letter before
		{
			userName.at(i)=toupper(userName.at(i));
		}
	}
	return userName;
	}
	
	
	string getAccountNumber(){
	string accountNum; //account number 
	bool check=true; //to stop/continue all the loops
	cout<<"Enter your account number:";
	do
	{ 
	getline(cin,accountNum);
	if(accountNum.length()!=size) //checks the length of the account number
	{
		cout<<"Your account number is a 6-digit number.Enter again:";
		check=false;
	}
	else{
		for(int i=0;i<size;++i)
		{
			if(isdigit(accountNum.at(i))!=0)
			{
			check=true;
			}
			else
			{
			cout<<"Account number can only contain digits.Enter again:";
			check=false;
			break;
			}
		}
	}
	}while(!check);
	return accountNum;
	}


	int getNumberofTransactions(string fileName){
		int place;
		int transNum;
		ifstream inFS;
		
		inFS.open(fileName);
		
		if(inFS.fail()){
			cout<<"File "<<fileName<<" could not open."<<endl;
			exit(1);
		}
		
		while(!inFS.eof()){
			inFS>>place;
			transNum++;
		}
		inFS.close();
		return transNum;
	}
	

	int getNumberofAccounts(string fileName){
		int numAccount;
		int place;
		ifstream inFS;
		
		inFS.open(fileName);
		
		if(inFS.fail()){
			cout<<"File "<<fileName<<" could not open."<<endl;
			exit(1);
		}
		
		while(!inFS.eof()){
			inFS>>place;
			numAccount++;
		}
		inFS.close();
		return numAccount;
	}
	
	
	void addAccount(){
		string userName; //the name of the account holder
		string accountNum; //account number 
		string accName; //updated userName
		ofstream outFS;
		
		outFS.open("account_data",ios::app);
		
		if(outFS.fail()){
			cout<<"File account_data could not open."<<endl;
			exit(1);
		}
		
		accName=getName(userName);
		getAccountNumber();
		
		outFS<<accName<<","<<accountNum<<endl;
		outFS.close();
		
	}
	
	
	void removeAccount(string removeAcctNum){
		bool remove=false;
		int numAccount;
		string fileName="account_data";
		ifstream fin;
		numAccount=getNumberofAccounts(fileName);
		Account *acctarray=new Account[numAccount];
		
		fin.open("account_data");
		
		if(fin.fail()){
			cout<<"Failed to open file account_data.dat"<<endl;
			exit(1);
		}
		
		for(int i=0;i<numAccount;++i)
		{
			getline(fin,acctarray[i].name,',');
			fin>>acctarray[i].number;
			
			if(acctarray[i].number ==removeAcctNum)
			{
				remove= true;
			}
		}
		fin.close();
		
		if(remove)
		{
			ofstream fout;
			fout.open("account_data.dat");
			
			if(fout.fail())
			{
				cout<<"Failed to open file account_data.dat"<<endl;
				exit(1);
			}
			for(int i=0;i<numAccount;++i)
			{
				if(acctarray[i].number != removeAcctNum)
				{
					fout<<acctarray[i].name<<","<<acctarray[i].number;
				}
			}
			fout<<endl;
			fout.close();
		}
		else
		{
			cout<<"Account does not exist."<<endl;
		}
		delete [] acctarray;
	}
	
	
	double getCurrentBalance(string balanceNum, typeAccount acctChoice){
		char type;
		double currBalance=0;
		double tempTransaction;
		
		 if(acctChoice==Business)
		 {
			 type='b';
		 }
		 else{
			 type='p';
		 }
		 
		 balanceNum.push_back(type);
		 
		 ifstream fin;
		 
		 fin.open(balanceNum);
		 
		 if(fin.fail()){
			cout<<"Failed to open file."<<endl;
			exit(1);
		}
		 
		 while(!fin.eof())
		 {
			 fin>>tempTransaction;
			 currBalance+=tempTransaction;
		 }
		 
		 fin.close();
		 if(acctChoice==0){ 
		 cout<<"Business Balance:$"<<fixed<<setprecision(2)<<currBalance<<endl;
		 }
		 else{
			 cout<<"Personal Balance:$"<<fixed<<setprecision(2)<<currBalance<<endl;
		 }
		return currBalance;
	}
	
	
	void writeTransactions(string transacNum, typeAccount acctChoice){
	char type;
	double transaction;
	 if(acctChoice==Business)
		 {
			 type='b';
		 }
		 else{
			 type='p';
		 }
		 
		transacNum+=type;
		 
		 ofstream fout;
		 
		 fout.open(transacNum,ios::app);
		 if(fout.fail()){
			cout<<"Failed to open file."<<endl;
			exit(1);
		}
		 
		cout<<"Enter your desried transaction:";
		cin>>transaction;
		fout<<transaction<<endl;
		
		fout.close();
	}
	
	
	void displayAccount(string displayNum){
		int choice;
		char yesNo;
		bool sort;
		char type;
		double temp;
		typeAccount acctChoice;
		int transNum;
		
		do{
		cout<<"Which account to display?0 for Business, 1 for Personal:";
		cin>>choice;
		acctChoice=static_cast<typeAccount>(choice);
		switch(acctChoice){
			case Business:
			do{
				type='b';
				displayNum+=type;
				getNumberofTransactions(displayNum);
				double *displayarray= new double[transNum];
				ifstream fin;
				
				fin.open(displayNum);
				if(fin.fail()){
					cout<<"Failed to open file."<<endl;
					exit(1);
				}
				
				for(int i=0;i<transNum;i++){
					fin>>displayarray[i];
				}	
				fin.close();
				cout<<"Would you like to sort the transactions? Y/N:";
				cin>>yesNo;
				yesNo=toupper(yesNo);
				if(yesNo=='Y')
				{
				for(int i=0;i<transNum;++i){
					for(int j=0;j<transNum;++j){
						if(displayarray[i]>displayarray[j]){
							temp=displayarray[i];
							displayarray[i]=displayarray[j];
							displayarray[j]=temp;
						}
					}
				}
				for(int i=0;i<transNum;++i)
				{
					cout<<"$"<<fixed<<setprecision(2)<<displayarray[i]<<endl;
				}
				}
				else
				{
				for(int i=0;i<transNum;++i)
				{
					cout<<"$"<<fixed<<setprecision(2)<<displayarray[i]<<endl;
				}
				}
				
			}while(yesNo !='Y' && yesNo != 'N');
			
			break;
			case Personal:
			do{
				type='p';
				displayNum+=type;
				getNumberofTransactions(displayNum);
				double *displayarray= new double[transNum];
				ifstream fin;
				
				fin.open(displayNum);
				
				if(fin.fail()){
					cout<<"Failed to open file."<<endl;
					exit(1);
				}
				
				for(int i=0;i<transNum;i++){
					fin>>displayarray[i];
				}
				fin.close();					
				cout<<"Would you like to sort the transactions? Y/N:";
				cin>>yesNo;
				yesNo=toupper(yesNo);
				if(yesNo=='Y')
				{
				for(int i=0;i<transNum;++i){
					for(int j=0;j<transNum;++j){
						if(displayarray[i]>displayarray[j]){
							temp=displayarray[i];
							displayarray[i]=displayarray[j];
							displayarray[j]=temp;
						}
					}
				}
				for(int i=0;i<transNum;++i)
				{
					cout<<"$"<<fixed<<setprecision(2)<<displayarray[i]<<endl;
				}
				}
				else
				{
					for(int i=0;i<transNum;++i)
				{
					cout<<"$"<<fixed<<setprecision(2)<<displayarray[i]<<endl;
				}
				}
			}while(yesNo !='Y' && yesNo != 'N');
			break;
			default:
			cout<<"Wrong choice.Enter again:";
			break;
		}
		}while(choice !=0 && choice !=1);
	}

	
	void processAccount(string processNum){
	int choice;
	double transaction; 
	typeAccount acctChoice;
	char transaction2; //wether or not there will be a desired transaction
	bool check=true; //to stop/continue all the loops
	
	do
	{
		do
		{
			cout<<"Which account would you like to access?0 for Business, 1 for Personal:";
			cin>>choice;
			acctChoice=static_cast<typeAccount>(choice);
		switch(acctChoice)
		{
			case Business:
			
			writeTransactions(processNum,acctChoice);
			getCurrentBalance(processNum,acctChoice);
			check=true;
			
			break;
			
			case Personal: 
			
			writeTransactions(processNum,acctChoice);
			getCurrentBalance(processNum,acctChoice);
			check=true;
			
			break;
			
			default: //wrong letter input
				cout<<"Invalid choice,Please try again."<<endl;
				check=false;
			break;
		}
	
		}while(!check);
		cout<<"Would you like to do another transaction? Y/N:";
		cin>>transaction2;
		transaction2=toupper(transaction2);
		if(transaction2=='Y')
		{
			check=false;//keeps the loop going
		}
		else if(transaction2=='N')
		{
			check=true;
			break;//ends the loop
		}
	}while(!check);
}
	
	
