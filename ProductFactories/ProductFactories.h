#pragma once
#include<string>
#include<memory>
#include"Product.h"

class ProductFactory{
    public:
    virtual std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int quantity, double weight) = 0;
    virtual ~ProductFactory() = default;
};

// ===ELECTRONICS_FACTORIES===
class SmartphoneFactory:public ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int quantity, double weight) override;
};

class LaptopFactory:public ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int quantity, double weight) override;
};

// ===CLOTHING_FACTORIES===
class TShirtFactory:public ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int quantity, double weight) override;
};

class JacketFactory:public ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int quantity, double weight) override;
};

// ===FOOD_FACTORIES===
class MilkFactory:public ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int quantity, double weight) override;
};

class BreadFactory:public ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int quantity, double weight) override;
};
