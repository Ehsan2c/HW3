#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <vector>
#include "bank.hpp"

class Item{
    friend class Bank;
    public:    
        friend std::ostream& operator<<(std::ostream& output, const Item& item);

        virtual void addItem(std::vector<Item*>& items, std::string name, int amount) = 0;
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount, double price = 0.0) = 0;
        void buyItem(std::vector<Item*>& items, std::vector<Bank*>& accounts, std::string itemName, int amount, int accountNumber);
        virtual void print() = 0;

        void set_name(std::string);
        std::string get_name() const;

        virtual Item& operator++() = 0;   
        virtual Item* operator++(int) = 0;
    private:
        std::string name;
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

        virtual void print(std::ostream& output) const = 0;
};

#endif