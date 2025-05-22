#ifndef CURRENCY_HPP
#define CURRENCY_HPP

#include <iostream>
#include <vector>

class Currency {
protected:
    double value;

public:
    Currency(double val = 0.0);

    virtual ~Currency() = default;

    virtual std::string getName() const = 0;
    virtual double toUSD() const = 0;

    double getValue() const;

    void setValue(double val);

    static void create(std::vector<Currency*>& vec, double value, const std::string& type);

    bool operator==(const Currency& other) const;
    bool operator!=(const Currency& other) const;
    bool operator<(const Currency& other) const;
    bool operator>(const Currency& other) const;
    bool operator<=(const Currency& other) const;
    bool operator>=(const Currency& other) const;

    double operator*(const Currency& other) const;
    double operator/(const Currency& other) const;
    double operator+(const Currency& other) const;
    double operator-(const Currency& other) const;

    void print();
};


class USD : public Currency {
public:
    USD(double val = 0.0);
    std::string getName() const override;
    double toUSD() const override;
};

class EUR : public Currency {
public:
    EUR(double val = 0.0);
    std::string getName() const override;
    double toUSD() const override; 
};

class IRR : public Currency {
public:
    IRR(double val = 0.0);
    std::string getName() const override;
    double toUSD() const override;
};

#endif
