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