#include"Warehouse.h"
#include<stdexcept>

Warehouse::Warehouse(size_t maxSize):maxSize_(maxSize),currentSize_(0){
    if(maxSize == 0){
        throw std::invalid_argument("Size must be positive");
    }
}

Warehouse::Warehouse(const Warehouse& other):maxSize_(other.maxSize_),currentSize_(other.currentSize_){
    for(const auto& p : other.products_){
        products_.push_back(std::unique_ptr<Product>(p->clone()));
    }
}

Warehouse& Warehouse::operator=(const Warehouse& other){
    if(this == &other){
        return *this;
    }
    products_.clear();
    maxSize_ = other.maxSize_;
    currentSize_ = other.currentSize_;
    for(const auto& p : other.products_){
        products_.push_back(std::unique_ptr<Product>(p->clone()));
    }
    return *this;
}