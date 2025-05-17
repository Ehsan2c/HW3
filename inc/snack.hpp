#ifndef SNACK_HPP
#define SNACK_HPP

#include "item.hpp"
#include <iostream>

class Snack : public Item{
    public:
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount) override;
        virtual void addItem(std::vector<Item*>& items, std::string name, int amount, double price = 0.0) override;
        virtual void print() override;
        void set_name(std::string);
        std::string get_name() const;
    private:
        static Snack* itemExists(const std::vector<Item*>& items, const std::string name);// i added this line here ali
        std::string name;
    protected:
        virtual void set_unit(std::string) override;
};

#endif
