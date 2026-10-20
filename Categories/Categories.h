#pragma once
#include"Product.h"

class Electronics:public Product{
    public:
    Electronics(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
};

class Clothing:public Product{
    public:
    Clothing(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
};

class Food:public Product{
    public:
    Food(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
};
