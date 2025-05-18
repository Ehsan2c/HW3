#include "item.hpp"
#include "fruit.hpp"
#include "seasoning.hpp"
#include "snack.hpp"
#include "bank.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<Item*> items;

    try{
    Item* it = new Fruit;
    it->addItem(items, "apple", 5, 120);
    (*it)++;
    
    it = new Fruit;
    it->addItem(items, "banana", 4, 200);

    cout << *it << endl;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

    for(Item* item : items){
        item->print();
    }
    

    vector<Bank*> accounts;

    try{
    Bank* account = new Bank;
    account->createAccount(accounts, "Ehsan", 254, "USD", -1, "personal");
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

    for(Bank* account : accounts){
        account->print();
    }

    items[0]->buyItem(items, accounts, "apple", 5, 254);

    for(Item* item : items){
        item->print();
    }
    for(Bank* account : accounts){
        account->print();
    }

    for(Item* item : items){
        delete item;
    }
    for(Bank* account : accounts){
        delete account;
    }
    
    return 0;
}