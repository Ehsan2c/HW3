#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <vector>
#include "bank.hpp"
class Item{
    public:
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount) = 0;
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount, double price = 0.0) = 0;
        virtual void print() = 0;
        void byitem(std::string itemname,int amount, Bank & bank );
    private:
        friend  class Bank;
        double price;
        int amount;
        std::string unit;
    protected: 
        void set_price(double);
        double get_price() const;
        void set_amount(int);
        int get_amount() const;
        virtual void set_unit(std::string);
        virtual std::string get_unit() const;
};

#endif  