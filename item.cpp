#include "item.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

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
    if(unit != "kg" || unit != "g" || unit != "package"){
       throw out_of_range("Invalid unit.");
    }
    this->unit = unit;
}
string Item::get_unit() const{
    return unit;
} 

void Item::byitem(std::string itemname, int amount, Bank& bank) {
    if (amount <= 0) {
        throw out_of_range("Amount must be positive.");
    }

    double totalCost = price * amount;
    
    if (bank.get_balance() < totalCost) {
        throw out_of_range("Insufficient balance in the bank account.");
    }

    bank.withdraw(totalCost);

    this->amount += amount;

    if (amount >= 5) {
        this->amount += 1;
        cout << "Congratulations! You've received 1 extra " << itemname << " as a gift!" << endl;
    }

    cout << "Purchased " << amount << " of " << itemname << " for " << totalCost << " " << bank.get_currencyType() << endl;
}