#include "bank.hpp"
#include <iostream>

using namespace std;

void Bank::set_name(string name){
    this->name = name;
}
string Bank::get_name() const{
    return name;
}
void Bank::set_accountNumber(int accountNumber){
    if(accountNumber < 0){
        throw out_of_range("Account number can't be negative.");
    }
    this->accountNumber = accountNumber;
}
int Bank::get_accountNumber() const{
    return accountNumber;
}
void Bank::set_currencyType(string currencyType){
    if(currencyType != "USD" && currencyType != "EUR" && currencyType != "IRR"){
       throw out_of_range("Invalid currency type.");
    }
    this->currencyType = currencyType;
}
string Bank::get_currencyType() const{
    return currencyType;
}
void Bank::set_balance(double balance){
    if(balance < 0){
        throw out_of_range("Balance can't be negative.");
    }
    this->balance = balance;
}
double Bank::get_balance() const{
    return balance;
}
void Bank::set_bankType(string bankType){
    if(bankType != "personal" && bankType != "organization"){
        throw out_of_range("Invalid bank type.");
    }
    this->bankType = bankType;
    this->maxTransfer = (bankType == "personal") ? 1000 : 10000;
}
string Bank::get_bankType() const{
    return bankType;
}
void Bank::set_maxTransfer(double maxTransfer){
    if(maxTransfer != 1000 && maxTransfer != 10000){
        throw out_of_range("Invalid max transfer");
    }
    this->maxTransfer = maxTransfer;
}
double Bank::get_maxTransfer() const{
    return maxTransfer;
}


void Bank::deposit(double amount){
    if(amount < 0){
        throw out_of_range("You can't deposit a negative amount.");
    }
    if(maxTransfer - amount < 0){
        cout << "You have reached your max daily transfer amount." << endl;
        return;
    }
    balance = balance + amount;
    maxTransfer = maxTransfer - amount;
}
void Bank::withdraw(double amount){
    if(amount < 0){
        throw out_of_range("You can't withdraw a negative amount.");
    }
    if(balance < amount){
        cout << "You don't have enough money." << endl;
        return;
    }
    if(maxTransfer - amount < 0){
        cout << "You have reached your max daily transfer amount." << endl;
        return;
    }
    balance = balance - amount;
    maxTransfer = maxTransfer - amount;
}

Bank* accountExists(const std::vector<Bank*>& accounts, int accountNumber){
    for(Bank* account : accounts){
        if(account && account->get_accountNumber() == accountNumber){
            return account;
        }
    }
    return nullptr;
}
        
void Bank::createAccount(std::vector<Bank*>& accounts, std::string name, int accountNumber, std::string currencyType, double balance, std::string bankType){
    Bank* exists = accountExists(accounts, accountNumber);
    if(exists != nullptr){
        cout << "There is already an account with this account number." << endl;
        return;
    }
    if(exists != nullptr){
        exists->set_balance(exists->get_balance() + balance);
        return;
    }
    this->name = name;
    set_accountNumber(accountNumber);
    set_currencyType("USD");
    set_balance(balance);
    set_bankType(bankType);
    accounts.push_back(this);
}

void Bank::print(){
    string dollar = " dollars.";
    if(balance == 1){
        dollar = " dollar.";
    }
    cout << "Account owner: " << name << ", account number: " << accountNumber << ", Balance: " << balance << dollar << endl;
}

void Bank::print(std::vector<Bank*>& accounts, int accountNumber){
    Bank* exists = accountExists(accounts, accountNumber);
    if(exists == nullptr){
        cout << "There is no account with this account number." << endl; 
        return;
    }
    string dollar = " dollars.";
    if(exists->get_balance() == 1){
        dollar = " dollar.";
    }
    cout << "Account owner: " << exists->get_name() << ", account number: " << exists->get_accountNumber() << ", Balance: " << exists->get_balance() << dollar << endl;
}