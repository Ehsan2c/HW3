#include "item.hpp"
#include "fruit.hpp"
#include "seasoning.hpp"
#include "snack.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<Item*> items;

    Item* it = new Fruit;
    it->addItem(items, "apple", 5, 120);
    
    it = new Fruit;
    it->addItem(items, "banana", 4, 200);

    for(Item* item : items){
        item->print();
    }
    for(Item* item : items){
        delete item;
    }

    
    return 0;
}