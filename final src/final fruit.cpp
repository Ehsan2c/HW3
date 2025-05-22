#include "fruit.hpp"
#include <iostream>
#include <vector>

using namespace std;

void Fruit::set_unit(string unit){
    Item::set_unit(unit);
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
    set_name(name);
    set_amount(amount);
    set_unit("kg");
    items.push_back(this);
}

void Fruit::addItem(std::vector<Item*>& items, string name, int amount, double price){
    Fruit* exists = itemExists(items, name);
    if(exists != nullptr){
        exists->set_amount(exists->get_amount() + amount);
        return;
    }
    set_name(name);
    set_amount(amount);
    set_unit("kg");
    set_price(price);
    items.push_back(this);
}

void Fruit::print(){
    if(get_amount() == 0){
        return;
    }
    cout << "Name: " << get_name() << ", Amount: " << get_amount() << " " << get_unit() << ", Price: " << get_price() << " USD" << endl;
}

Item& Fruit::operator++(){
    set_amount(get_amount() + 1);
    return *this;
}

Item* Fruit::operator++(int){
    Fruit* temp = new Fruit(*this);
    set_amount(get_amount() + 1);
    return temp;
}

void Fruit::print(std::ostream& output) const{
    output << "Name: " << get_name() << endl
            << "Price: " << get_price() << " USD" << endl
            << "Amount: " << get_amount() << " " << get_unit() << endl;
}