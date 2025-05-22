#include "item.hpp"
#include "fruit.hpp"
#include "seasoning.hpp"
#include "snack.hpp"
#include "bank.hpp"
#include "currency.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<Item*> items;

    try{
    Item* it = new Fruit;
    it->addItem(items, "apple", 5, 200);
    (*it)++;
    ++(*it);
    
    it = new Fruit;
    it->addItem(items, "banana", 4, 150);

    cout << *it << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

    for(Item* item : items){
        item->print();
    }
    cout << endl;

    vector<Bank*> accounts;

    try{
    Bank* account = new Bank;
    account->createAccount(accounts, "Ehsan", 254, "USD", 1500, "personal");
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

    for(Bank* account : accounts){
        account->print();
    }
    cout << endl;

    try{
        items[0]->buyItem(items, accounts, "apple", 5, 254);
        items[0]->buyItem(items, accounts, "banana", 1, 254);
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }

    cout << endl;
    for(Item* item : items){
        item->print();
    }
    cout << endl;
    for(Bank* account : accounts){
        account->print();
    }
    Bank bank;
    bank.print(accounts, 254);

    
    vector<Currency*> currencies;
    
    try{
        Currency::create(currencies, 1.12, "USD");
        Currency::create(currencies, 500, "EUR");
        Currency::create(currencies, 1, "EUR");
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }
    
    cout << endl;
    for(Currency* c : currencies){
        c->print();
    }
    
    cout << *currencies.at(0) * *currencies.at(1) << endl;
    if(*currencies.at(0) == *currencies.at(2)){
        cout << "Equal" << endl;
    }
    else{
        cout << "Not equal" << endl;
    }
    
    for(Item* item : items){
        delete item;
    }
    for(Bank* account : accounts){
        delete account;
    }
    for(Currency* c : currencies){
        delete c;
    }
    
    return 0;
}