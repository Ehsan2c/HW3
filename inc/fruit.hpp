#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "item.hpp"
#include <iostream>

class Fruit : public Item{
    public:
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount) override;
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount, double price = 0.0) override;
        virtual void print() override;
        void set_name(std::string);
        std::string get_name() const;
    private:
        std::string name;
    protected:
        virtual void set_unit(std::string) override;
};

#endif