#include "snack.hpp"
#include <iostream>

using namespace std;

void Snack::set_unit(string unit){
    Item::set_unit(unit);
}

void Snack::set_name(std::string name){
    this->name = name;
}
string Snack::get_name() const{
    return name;
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
    this->name = name;
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
    this->name = name;
    set_amount(amount);
    set_unit("package");
    set_price(price);
    items.push_back(this);
}

void Snack::print(){
    cout << "Name: " << name << ", Amount: " << get_amount() << get_unit() << ", Price: " << get_price() << endl;
}
