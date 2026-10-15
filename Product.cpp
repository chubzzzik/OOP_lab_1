#pragma once

#include<string>
#include<stdexcept>
using namespace std;

class Price{
    private:
    int value;
    public:
    explicit Price(int val):value(val){
        if(val < 0){ throw invalid_argument("Price can't be negative"); }
    }
    int getValue() const{ return value; }
    void setValue(int newVal){
        if(newVal < 0){
            throw invalid_argument("Price can't be negative");
        }
        value = newVal;
    }
};

class Quantity{
    private:
    int value;
    public:
    explicit Quantity(int val):value(val){
        if(val < 0){ throw invalid_argument("Quantity can't be negative"); }
    }
    int getValue() const{ return value; }
    void setValue(int newVal){
        if(newVal < 0){ 
            throw invalid_argument("Quantity can't be negative"); 
        }
        value = newVal;
    }
};

class Weight{
    private:
    double value;
    public:
    explicit Weight(double val):value(val){
        if(val < 0){ throw invalid_argument("Weight can't be negative"); }
    }
    double getValue() const{ return value; }
    void setValue(double newVal){
        if(newVal < 0){
            throw invalid_argument("Weight can't be negative");
        }
        value = newVal;
    }
};


class Product{
    private:
    int id;
    string name;
    int price;
    int quantity;
    double weight;
    string category;
    public:
    virtual Product* clone() = 0;

};