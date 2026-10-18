#pragma once

#include"Product.h"
#include<vector>
#include<memory>

class WarehouseIterator{
    public:
    void operator++();
    void operator*();
    void operator!=(); // ошибка временная из-за недостатка аргумента в сигнатуре
};

class Warehouse{
    private:
    std::vector<std::unique_ptr<Product>> products_;
    size_t maxSize_;
    int currentSize_;

    public:
    Warehouse(size_t maxSize);
    ~Warehouse() = default;
    Warehouse(const Warehouse& other);
    Warehouse& operator=(const Warehouse& other);
    Warehouse(Warehouse&& other) noexcept;
    Warehouse& operator=(Warehouse&& other) noexcept;

    void addProduct(std::unique_ptr<Product> product);
    void removeById(int id);
    void removeByIndex(size_t index);
    Product* findById(int id);
    std::vector<Product*> findByCategory(const std::string& category);
    std::vector<Product*> findByPrice(const Price& price);
    void begin();
    void end();
};