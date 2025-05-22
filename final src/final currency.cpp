#include "currency.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Currency::Currency(double val){
    setValue(val);
}

double Currency::getValue() const {
    return value; 
}

void Currency::setValue(double val) { 
        if(val >= 0)
            value = val;
        else throw out_of_range("value can't be negative.");
}

void Currency::create(std::vector<Currency*>& vec, double value, const string& type) {
    if (type == "USD") vec.push_back(new USD(value));
    else if (type == "EUR") vec.push_back(new EUR(value));
    else if (type == "IRR") vec.push_back(new IRR(value));
    else throw invalid_argument("Unknown currency type.");
}

bool Currency::operator==(const Currency& other) const {
    return this->toUSD() == other.toUSD();
}
bool Currency::operator!=(const Currency& other) const {
    return !(*this == other);
}
bool Currency::operator<(const Currency& other) const {
    return this->toUSD() < other.toUSD();
}
bool Currency::operator>(const Currency& other) const {
    return this->toUSD() > other.toUSD();
}
bool Currency::operator<=(const Currency& other) const {
    return !(*this > other);
}
bool Currency::operator>=(const Currency& other) const {
    return !(*this < other);
}

double Currency::operator*(const Currency& other) const {
    return this->toUSD() * other.toUSD();
}
double Currency::operator/(const Currency& other) const {
    if (other.toUSD() == 0) throw runtime_error("Division by zero.");
    return this->toUSD() / other.toUSD();
}
double Currency::operator+(const Currency& other) const {
    return this->toUSD() + other.toUSD();
}
double Currency::operator-(const Currency& other) const {
    return this->toUSD() - other.toUSD();
}

void Currency::print(){
    cout << "Value: " << value << " " << getName() << endl;
}



USD::USD(double val){
    setValue(val);
}

string USD::getName() const{
    return "USD";
}

double USD::toUSD() const{
    return value; 
}

EUR::EUR(double val){
    setValue(val);
}

string EUR::getName() const{
    return "EUR";
}

double EUR::toUSD() const{
    return value * 1.12; 
} 

IRR::IRR(double val){
    setValue(val);
}

string IRR::getName() const{
    return "IRR";
}

double IRR::toUSD() const{
    return value / 830000.0; 
} 