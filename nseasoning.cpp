#include "seasoning.hpp"
#include <iostream>

using namespace std;

void Seasoning::set_unit(string unit){
    Item::set_unit(unit);
}

Seasoning* itemExists(const std::vector<Item*>& items, const std::string name){
    for(Item* it : items){
        Seasoning* seasoning = dynamic_cast<Seasoning*>(it);
        if(seasoning && seasoning->get_name() == name){
            return seasoning;
        }
    }
    return nullptr;
}

void Seasoning::addItem(std::vector<Item*>& items, string name, int amount){
    Seasoning* exists = itemExists(items, name);
    if(exists != nullptr){
        exists->set_amount(exists->get_amount() + amount);
        return;
    }
    set_name(name);
    set_amount(amount);
    set_unit("g");
    items.push_back(this);
}

void Seasoning::addItem(std::vector<Item*>& items, string name, int amount, double price){
    Seasoning* exists = itemExists(items, name);
    if(exists != nullptr){
        exists->set_amount(exists->get_amount() + amount);
        return;
    }
    set_name(name);
    set_amount(amount);
    set_unit("g");
    set_price(price);
    items.push_back(this);
}

void Seasoning::print(){
    if(get_amount() == 0){
        return;
    }
    cout << "Name: " << get_name() << ", Amount: " << get_amount() << get_unit() << ", Price: " << get_price() << endl;
}

Item& Seasoning::operator++(){
    set_amount(get_amount() + 1);
    return *this;
}

Item* Seasoning::operator++(int){
    Seasoning* temp = new Seasoning(*this);
    set_amount(get_amount() + 1);
    return temp;
}

void Seasoning::print(std::ostream& output) const{
    output << "Name: " << get_name() << endl
            << "Price: " << get_price() << " USD" << endl
            << "Amount: " << get_amount() << " " << get_unit() << endl;
}