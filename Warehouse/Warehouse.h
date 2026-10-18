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
    ~Warehouse();
    Warehouse(const Warehouse& other);
    Warehouse& operator=(const Warehouse& other);
    Warehouse(Warehouse&& other);
    Warehouse& operator=(Warehouse&& other);

    void addProduct();
    void removeById();
    void removeByIndex();
    void findById();
    void findByCategory();
    void findByPrice();
    void begin();
    void end();
};