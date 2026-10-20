#pragma once

#include"Product.h"
#include<vector>
#include<memory>

class WarehouseIterator{
    private:
    std::vector<std::unique_ptr<Product>>::iterator current_;
    std::vector<std::unique_ptr<Product>>::iterator end_;
    public:
    WarehouseIterator(const std::vector<std::unique_ptr<Product>>::iterator& current, const std::vector<std::unique_ptr<Product>>::iterator& end);
    WarehouseIterator& operator++();
    Product& operator*() const;
    bool operator!=(const WarehouseIterator& other) const; 
    bool operator==(const WarehouseIterator& other) const;
};

class ConstWarehouseIterator{
    private:
    std::vector<std::unique_ptr<Product>>::const_iterator current_;
    std::vector<std::unique_ptr<Product>>::const_iterator end_;
    public:
    ConstWarehouseIterator(const std::vector<std::unique_ptr<Product>>::const_iterator& current, const std::vector<std::unique_ptr<Product>>::const_iterator& end);
    ConstWarehouseIterator& operator++();
    const Product& operator*() const;
    bool operator!=(const ConstWarehouseIterator& other) const;
    bool operator==(const ConstWarehouseIterator& other) const;
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
    WarehouseIterator begin();
    WarehouseIterator end();
    ConstWarehouseIterator begin() const;
    ConstWarehouseIterator end() const;
};