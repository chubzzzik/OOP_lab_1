#pragma once

#include<string>

class Product{
    private:
    int id;
    std::string name;
    int price;
    int quantity;
    double weight;
    std::string category;
    public:
    virtual Product* clone() = 0;

};