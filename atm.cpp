#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

string PIN = "1111";
int error = 0; //if error hits 5 times, then access denied. 

void create_account();
void select_account();
void check_PIN();

//a key of accounts vector
int act_num;

class Account{
	private: 
		string name;
		int balance;
	public:
		Account(string n) {balance = 0; name = n;}
		string showname(){
			return name;
		}
		void deposit(){
			int amount;
			cout<<endl;
			cout<<"How much do you want to deposit? Enter : ";
			cin>>amount;
			balance += amount;
		}
		void withdraw(){
			int amount2;
			cout<<endl;
			cout<<"How much do you want to withdraw? Enter : ";
			cin>>amount2;
			if(balance>amount2){
				balance -= amount2;
			}
			else{
				if(amount2 != 0){

					cout<<endl;
					cout<<"Sorry. There is not enough money to withdraw. Type it again."<<endl;
					withdraw();
				}

			}
		}
		void show_balance(){
			cout<<endl;
			cout<<"Your current balance of this account( "<<act_num+1<<" ) is "<<balance<<endl;
		}
};

//multiple objects of class Account
vector<Account> accounts;

int main(){
	//Insert card -> PIN number -> select account -> see balance, deposit, withdraw
	//1 dollar bills accepted. only integer
	string ans1;
	string account_ans;

	//Insert a card
	cout<<endl<<endl;
	cout<<"********************"<<endl;
	cout<<"********************"<<endl;
	cout<<"Welcome to BR Bank ATM."<<endl;
	cout<<"********************"<<endl;
	cout<<"********************"<<endl;
	cout<<"To start a service, please insert your card."<<endl;
	cout<<"Type (Yes or No) : ";
	cin>>ans1;
	cout<<endl<<endl;

	//put a card then enter  PIN number
	if(ans1 == "Yes" || ans1 == "YES" || ans1 == "yes"){
		cout<<"Success..."<<endl<<endl;
		cout<<"Now please enter your PIN number ( 4 digits ) : ";
		check_PIN();
		cout<<endl<<endl;
	}
	else{
		cout<<"Thank you for using BR bank ATM."<<endl;
		return 0;
	}
	if(error==5){
		return 0;
	}

	//show how many accounts that the user have
	cout<<endl<<endl;
	cout<<"You have "<<accounts.size()<<"account(s)."<<endl;
	cout<<"If you want to create then type 1, else type any number"<<endl;
	int a;
	cin>>a;
	if(a==1)
		create_account();

	//if you do not choose to create one, but it is mandatory to use our service
	select_account();

	//operations
	int option;
	while(1){
		cout<<endl;
		cout<<"Now what do you want to do with your account "<<accounts[act_num].showname()<<" ? ";
		cout<<endl;
		cout<<"********************"<<endl;
		cout<<"********************"<<endl;
		cout<<"1. show my balance"<<endl;
		cout<<"2. deposit"<<endl;
		cout<<"3. withdraw"<<endl;
		cout<<"4. reselect the account"<<endl;
		cout<<"5. create an account"<<endl;
		cout<<"To exit, enter any number"<<endl;
		cout<<"********************"<<endl;
		cout<<"********************"<<endl;
		cout<<"Type in number : ";
		cin>>option;
		cout<<endl<<endl;
		switch(option){
			case 1:
				accounts[act_num].show_balance();
				break;
			case 2:
				accounts[act_num].deposit();
				break;
			case 3:
				accounts[act_num].withdraw();
				break;
			case 4:
				select_account();
				break;
			case 5:
				create_account();
				break;
			default:
				cout<<"Thank you for using BR bank ATM"<<endl;
				return 0;
		}
	}
	return 0;
}

void create_account(){
	std::string s = "user account"+to_string(accounts.size()+1);
	accounts.push_back(s);
	cout<<endl<<endl;
	cout<<"New account user account"<<accounts.size()<<" is created"<<endl;
}

void select_account(){
	int c;
	cout<<"You have "<<accounts.size()<<"account(s)."<<endl<<endl;
	if(accounts.size() == 0){
		cout<<"You have no account. We will make you one :)"<<endl<<endl;
		create_account();
	}
	else{
		cout<<"Your current accounts are as below"<<endl<<endl;
		cout<<"********************"<<endl;
		for(int i=0;i<accounts.size();i++){
			cout<<accounts[i].showname()<<endl;
		}cout<<"********************"<<endl<<endl;
		cout<<"please select your account. type in number(1 - "<<accounts.size()<<") : ";
		cin>>c;
		if(c>accounts.size()){                    //if it is out of range
			cout<<endl;
			cout<<"Invalid account. Do it again"<<endl;
			select_account();
		}
		else{
			act_num = c-1;
		}
		
		cout<<endl<<endl;
	}
}

//Check if the given PIN number is correct or not
//if the user put wrong PIN for 5 times, then access is denied
void check_PIN(){
	string ans2;
	cin>>ans2;
	if(ans2 == "1111"){
		cout<<"Welcome, USER1."<<endl;
	}
	else{
		error++;
		if(error>4){
			cout<<"Access Denied"<<endl;
			cout<<"Ask to local bank to re-activate your account";
		}
		else{
			cout<<"Wrong PIN number for "<<error<<" time(s). Please type it again"<<endl<<endl;
			cout<<"If you miss 5 times, then your access would be denied"<<endl<<endl;
			cout<<"Now please put your PIN number : ";
			check_PIN();
			cout<<endl;
		}
	}
}


