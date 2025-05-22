#include "bank.hpp"
#include "currency.hpp"
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
void Bank::set_balance(double balance, string currencyType){
    if(balance < 0){
        throw out_of_range("Balance can't be negative.");
    }
    if(currencyType == "EUR"){
        EUR eur(balance);
        this->balance = eur.toUSD();
    }
    else if(currencyType == "IRR"){
        IRR irr(balance);
        this->balance = irr.toUSD();
    }
    else if(currencyType == "USD"){
        this->balance = balance;
    }
}
double Bank::get_balance() const{
    if (currencyType == "EUR") {
        return balance / 1.12;
    } 
    else if (currencyType == "IRR") {
        return balance * 830000.0;
    } 
    else if (currencyType == "USD"){
        return balance; 
    }
    throw invalid_argument("Unknown currency type.");
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
        throw out_of_range("Transfer failed: amount exceeds your daily transfer limit.");
    }
    if(maxTransfer == 0){
        throw out_of_range("You have reached your max daily transfer amount.");
    }
    balance = balance + amount;
    maxTransfer = maxTransfer - amount;
}
void Bank::withdraw(double amount){
    if(amount < 0){
        throw out_of_range("You can't withdraw a negative amount.");
    }
    if(balance < amount){
        throw out_of_range("You don't have enough money.");
    }
    if(maxTransfer - amount < 0){
        throw out_of_range("Transfer failed: amount exceeds your daily transfer limit.");
    }
    if(maxTransfer == 0){
        throw out_of_range("You have reached your max daily transfer amount.");
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
        exists->set_balance(exists->get_balance() + balance, currencyType);
        throw invalid_argument("There is already an account with this account number.");
    }
    set_name(name);
    set_accountNumber(accountNumber);
    set_currencyType(currencyType);
    set_balance(balance, currencyType);
    set_bankType(bankType);
    accounts.push_back(this);
}

void Bank::print(){
    cout << "Account owner: " << name << ", account number: " << accountNumber << ", Balance: " << get_balance() << " " << currencyType << endl;
}

void Bank::print(std::vector<Bank*>& accounts, int accountNumber){
    Bank* exists = accountExists(accounts, accountNumber);
    if(exists == nullptr){
        throw invalid_argument("There is no account with this account number.");
    }
    exists->print();
}