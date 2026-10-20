#include"Product.h"

int Product::nextId_ = 1;


Product::Product(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight, const std::string& category):name(name),price_(price),quantity_(quantity),weight_(weight),category(category){
    id = nextId_++;
}

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