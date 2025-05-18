#include "nbank.hpp"
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
void Bank::set_balance(double balance){// اینو تغییر دادم
    if(balance < 0){
        throw out_of_range("Balance can't be negative.");
    }
     if (currencyType == "EUR") {
        EUR eur(balance);
        this->balance = eur.toUSD();
    } else if (currencyType == "IRR") {
        IRR irr(balance);
        this->balance = irr.toUSD();
    } else {
        this->balance = balance; 
    }
}
double Bank::get_balance() const{// اینو تغییر دادم
      if (currencyType == "EUR") {
        USD usd(balance);
        EUR eur(usd.getValue() / 1.12);
        return eur.getValue();
    } else if (currencyType == "IRR") {
        USD usd(balance);
        IRR irr(usd.getValue() * 830000.0);
        return irr.getValue();
    } else {
        return balance; 
    }
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
void Bank::withdraw(double amount){// اینو تغییر دادم
    if (amount < 0) {
        throw out_of_range("You can't withdraw a negative amount.");
    }
    double amountUSD = amount;
    if (currencyType == "EUR") {
        EUR eur(amount);
        amountUSD = eur.toUSD();
    } else if (currencyType == "IRR") {
        IRR irr(amount);
        amountUSD = irr.toUSD();
    }

    if (balance < amountUSD) {
        cout << "You don't have enough money." << endl;
        return;
    }
    if (maxTransfer - amountUSD < 0) {
        cout << "You have reached your max daily transfer amount." << endl;
        return;
    }
    balance -= amountUSD;
    maxTransfer -= amountUSD;
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

void Bank::print(){ // اینو تغییر دادم
    string currencySymbol = "USD";
    double displayBalance = balance;

    if (currencyType == "EUR") {
        USD usd(balance);
        EUR eur(usd.getValue() / 1.12);
        displayBalance = eur.getValue();
        currencySymbol = "EUR";
    } else if (currencyType == "IRR") {
        USD usd(balance);
        IRR irr(usd.getValue() * 830000.0);
        displayBalance = irr.getValue();
        currencySymbol = "IRR";
    }

    cout << "Account owner: " << name << ", account number: " << accountNumber << ", Balance: " << displayBalance << " " << currencySymbol << endl;
}

void Bank::print(std::vector<Bank*>& accounts, int accountNumber){
    Bank* exists = accountExists(accounts, accountNumber);
    if(exists == nullptr){
        cout << "There is no account with this account number." << endl; 
        return;
    }
    exists->print();//اینجاشو تغییر دادم
}