#include"Product.h"

int Product::nextId_ = 1;

void Product::changeQuantity(int delta){
    quantity_.change(delta);
}

void Product::setPrice(const Price& newPrice){
    price_ = newPrice;
}