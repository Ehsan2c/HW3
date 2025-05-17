#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>

class Bank{
    public:
        Bank();

        void set_name(std::string);
        std::string get_name() const;
        void set_accountNumber(int);
        int get_accountNumber() const;
        void set_currencyType(std::string);
        std::string get_currencyType() const;
        void set_balance(double);
        double get_balance() const;
        void set_bankType(std::string);
        std::string get_bankType() const;
        void set_maxTransfer(double);
        double get_maxTransfer() const;

        void deposit(double);
        void withdraw(double);
        void createAccount(std::vector<Bank*>& accounts, std::string name, int accountNumber, std::string currencyType, double balance, std::string bankType);
    private:
        std::string name;
        int accountNumber;
        std::string currencyType;
        double balance = 0;
        std::string bankType = {"personal", "organization"};
        double maxTransfer;
};

#endif
