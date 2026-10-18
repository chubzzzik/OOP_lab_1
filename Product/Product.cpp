#include"Product.h"

int Product::nextId_ = 1;

void Product::changeQuantity(int delta){
    quantity_.change(delta);
}

void Product::setPrice(const Price& newPrice){
    price_ = newPrice;
}

int Product::getId() const{
    return id;
}

const std::string& Product::getCategory() const{
    return category;
}

const Price& Product::getPrice() const{
    return price_;
}