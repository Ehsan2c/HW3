#include "fruit.hpp"
#include <iostream>
#include <vector>

using namespace std;

void Fruit::set_unit(string unit){
    Item::set_unit(unit);
}

void Fruit::set_name(std::string name){
    this->name = name;
}
string Fruit::get_name() const{
    return name;
}

Fruit* itemExists(const std::vector<Item*>& items, const std::string name){
    for(Item* it : items){
        Fruit* fruit = dynamic_cast<Fruit*>(it);
        if(fruit && fruit->get_name() == name){
            return fruit;
        }
    }
    return nullptr;
}

void Fruit::addItem(std::vector<Item*>& items, string name, int amount){
    Fruit* exists = itemExists(items, name);
    if(exists != nullptr){
        exists->set_amount(exists->get_amount() + amount);
        return;
    }
    this->name = name;
    set_amount(amount);
    set_unit("Kg");
    items.push_back(this);
}

void Fruit::addItem(std::vector<Item*>& items, string name, int amount, double price){
    Fruit* exists = itemExists(items, name);
    if(exists != nullptr){
        exists->set_amount(exists->get_amount() + amount);
        return;
    }
    this->name = name;
    set_amount(amount);
    set_unit("Kg");
    set_price(price);
    items.push_back(this);
}

void Fruit::print(){
    cout << "Name: " << name << ", Amount: " << get_amount() << get_unit() << ", Price: " << get_price() << endl;
}