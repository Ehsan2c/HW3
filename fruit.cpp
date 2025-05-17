#include "fruit.hpp"
#include <iostream>
#include <vector>

using namespace std;

void Fruit::addItem(vector<Item*>& items, string name, int amount) {
    Fruit* newFruit = new Fruit();
    newFruit->set_name(name);
    newFruit->set_amount(amount);
    newFruit->set_unit("kg");
    items.push_back(newFruit);
}

void Fruit::addItem(vector<Item*>& items, string name, int amount, double price) {
    Fruit* newFruit = new Fruit();
    newFruit->set_name(name);
    newFruit->set_amount(amount);
    newFruit->set_price(price);
    newFruit->set_unit("kg");
    items.push_back(newFruit);
}

void Fruit::print() {
    cout << "Fruit: " << name << ", Amount: " << get_amount() << " kg, Price: " << get_price() << " per kg" << endl;
}

void Fruit::set_name(string n) {
    name = n;
}

string Fruit::get_name() const {
    return name;
}

void Fruit::set_unit(string) {
    Item::set_unit("kg"); 
}