#pragma once

#include"Categories.h"

// ===ELECTRONICS===
class Smartphone:public Electronics{
    public:
    Smartphone(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

class Laptop:public Electronics{
    public:
    Laptop(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

// ===CLOTHING===
class TShirt:public Clothing{
    public:
    TShirt(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

class Jacket:public Clothing{
    public:
    Jacket(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

// ===FOOD===
class Milk:public Food{
    public:
    Milk(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

class Bread:public Food{
    public:
    Bread(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight);
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};