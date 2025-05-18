#ifndef SEASONING_HPP
#define SEASONING_HPP

#include "item.hpp"
#include <iostream>

class Seasoning : public Item{
    public:
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount) override;
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount, double price = 0.0) override;
        virtual void print() override;

        Item& operator++() override;     
        Item* operator++(int) override;
    private:
        std::string name;
    protected:
        virtual void set_unit(std::string) override;

        void print(std::ostream& output) const override;
};

#endif