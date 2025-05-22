#include "snack.hpp"
#include <iostream>

using namespace std;

void Snack::set_unit(string unit){
    Item::set_unit(unit);
}

Snack* itemExists(const std::vector<Item*>& items, const std::string name){
    for(Item* it : items){
        Snack* snack = dynamic_cast<Snack*>(it);
        if(snack && snack->get_name() == name){
            return snack;
        }
    }
    return nullptr;
}

void Snack::addItem(std::vector<Item*>& items, string name, int amount){
    Snack* exists = itemExists(items, name);
    if(exists != nullptr){
        exists->set_amount(exists->get_amount() + amount);
        return;
    }
    set_name(name);
    set_amount(amount);
    set_unit("package");
    items.push_back(this);
}

void Snack::addItem(std::vector<Item*>& items, string name, int amount, double price){
    Snack* exists = itemExists(items, name);
    if(exists != nullptr){
        exists->set_amount(exists->get_amount() + amount);
        return;
    }
    set_name(name);
    set_amount(amount);
    set_unit("package");
    set_price(price);
    items.push_back(this);
}

void Snack::print(){
    if(get_amount() == 0){
        return;
    }
    cout << "Name: " << get_name() << ", Amount: " << get_amount() << get_unit() << ", Price: " << get_price() << endl;
}

Item& Snack::operator++(){
    set_amount(get_amount() + 1);
    return *this;
}

Item* Snack::operator++(int){
    Snack* temp = new Snack(*this);
    set_amount(get_amount() + 1);
    return temp;
}

void Snack::print(std::ostream& output) const{
    output << "Name: " << get_name() << endl
            << "Price: " << get_price() << " USD" << endl
            << "Amount: " << get_amount() << " " << get_unit() << endl;
}