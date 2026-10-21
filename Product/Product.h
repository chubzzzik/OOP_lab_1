#pragma once

#include"Attributes.h"
#include<string>

class Warehouse;

class Product{
    private:
    int id;
    static int nextId_;
    std::string name;
    Price price_;
    Quantity quantity_;
    Weight weight_;
    std::string category;
    
    public:
    Product(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight, const std::string& category);
    virtual ~Product() = default;
    virtual Product* clone() = 0;
    virtual void transferTo(Warehouse& other) = 0;
    void changeQuantity(int delta);
    void setPrice(const Price& newPrice);
    int getId() const;
    const std::string& getCategory() const;
    const Price& getPrice() const;
    const std::string& getName() const;
    const Quantity& getQuantity() const;
    const Weight& getWeight() const;
};