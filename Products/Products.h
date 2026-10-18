#pragma once

#include"Categories.h"

// ===ELECTRONICS===
class Smartphone:public Electronics{
    public:
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

class Laptop:public Electronics{
    public:
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

// ===CLOTHING===
class TShirt:public Clothing{
    public:
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

class Jacket:public Clothing{
    public:
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

// ===FOOD===
class Milk:public Food{
    public:
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};

class Bread:public Food{
    public:
    Product* clone() override;
    void transferTo(Warehouse& other) override;
};