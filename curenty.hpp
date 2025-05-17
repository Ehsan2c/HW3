#ifndef CURRENCY_HPP
#define CURRENCY_HPP

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Currency {
protected:
    double value;

public:
    Currency(double val = 0.0) : value(val) {}

    virtual string getName() const ;
    virtual double toUSD() const ;
    virtual double getConversionRate() const ;

    double getValue() const { return value; }
    void setValue(double val) { value = val; }

    Currency& operator+=(const Currency& other) {
        double converted = other.toUSD() / this->getConversionRate();
        value += converted;
        return *this;
    }

    Currency& operator-=(const Currency& other) {
        double converted = other.toUSD() / this->getConversionRate();
        value -= converted;
        return *this;
    }

    bool operator==(const Currency& other) const {
        return fabs(this->toUSD() - other.toUSD()) < 1e-6;//این تابع فابز مقدار بدون علامت عدد را میدهد و برای جلوگیری از خطا اگر اختلاف دو عدد خیلی کم باشد مساوی در نظر میگیرم
    }

    bool operator!=(const Currency& other) const {
        return !(*this == other);
    }

    bool operator<(const Currency& other) const {
        return this->toUSD() < other.toUSD();
    }

    bool operator>(const Currency& other) const {
        return this->toUSD() > other.toUSD();
    }

    bool operator<=(const Currency& other) const {
        return !(*this > other);
    }

    bool operator>=(const Currency& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Currency& c) {//این عملگر غیر عضو محسوب میشه پس دو پارامتر لازمه
        os << c.getValue() << " " << c.getName();
        return os;
    }
};


class USD : public Currency {
public:
    USD(double val = 0.0) : Currency(val) {}
    string getName() const { return "USD"; }
    double toUSD() const { return value; }
    double getConversionRate() const { return 1.0; }
};

class EUR : public Currency {
public:
    EUR(double val = 0.0) : Currency(val) {}
    string getName() const { return "EUR"; }
    double toUSD() const { return value * 1.1; } 
    double getConversionRate() const { return 1.1; }
};

class IRR : public Currency {
public:
    IRR(double val = 0.0) : Currency(val) {}
    string getName() const { return "IRR"; }
    double toUSD() const { return value / 830000.0; } 
    double getConversionRate() const { return 1.0 / 830000.0; }
};

#endif
