#include "item.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void Item::set_name(string name){
    this->name = name;
}
string Item::get_name() const{
    return name;
}
void Item::set_price(double price){
    if(price < 0){
       throw out_of_range("Price can't be negative.");
    }
    this->price = price;
}
double Item::get_price() const{
    return price;
}
void Item::set_amount(int amount){
    if(amount < 0){
       throw out_of_range("Amount can't be negative.");
    }
    this->amount = amount;
}
int Item::get_amount() const{
    return amount;
}
void Item::set_unit(string unit){
    if(unit != "kg" && unit != "g" && unit != "package"){
       throw out_of_range("Invalid unit.");
    }
    this->unit = unit;
}
string Item::get_unit() const{
    return unit;
}

ostream& operator<<(ostream& output, const Item& item){
    item.print(output);
    return output;
}

Item* itemExistence(const std::vector<Item*>& items, const std::string name){
    for(Item* it : items){
        if(it && it->get_name() == name){
            return it;
        }
    }
    return nullptr;
}

void Item::buyItem(std::vector<Item*>& items, std::vector<Bank*>& accounts, std::string itemName, int amount, int accountNumber){
    if (amount <= 0) {
        throw out_of_range("Amount must be positive.");
    }

    Item* itemToBuy = itemExistence(items, itemName);
    if (itemToBuy == nullptr) {
        throw invalid_argument("Item not found.");
    }

    Bank* bank = nullptr;
    for (Bank* account : accounts) {
        if (account && account->get_accountNumber() == accountNumber) {
            bank = account;
            break;
        }
    }

    if(bank == nullptr){
        throw invalid_argument("There is no bank account with that account number.");
    }

    double totalCost = itemToBuy->get_price() * amount;
    
    if (bank->get_balance() < totalCost) {
        throw out_of_range("Insufficient balance in the bank account.");
    }

    bank->withdraw(totalCost);

    itemToBuy->set_amount(itemToBuy->get_amount() - amount);

    string s = "s ";
    if(amount == 1){
        s = " ";
    }
    cout << "Purchased " << amount  << " " << itemName << s << "for " << totalCost << " USD" << endl;

    double prize = amount / 5;
    if (prize > 0) {
        itemToBuy->set_amount(itemToBuy->get_amount() - prize);
        cout << "Congratulations! You've received " << prize << " extra " << itemName << " as a gift!" << endl;
    }
}