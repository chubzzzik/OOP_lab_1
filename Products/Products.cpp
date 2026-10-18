#include"Products.h"
#include"Warehouse.h"

// ===ELECTRONICS===
Product* Smartphone::clone(){
    return new Smartphone(*this);
}

void Smartphone::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

Product* Laptop::clone(){
    return new Laptop(*this);
}

void Laptop::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

// ===CLOTHING===
Product* TShirt::clone(){
    return new TShirt(*this);
}

void TShirt::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

Product* Jacket::clone(){
    return new Jacket(*this);
}

void Jacket::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

// ===FOOD===
Product* Milk::clone(){
    return new Milk(*this);
}

void Milk::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

Product* Bread::clone(){
    return new Bread(*this);
}

void Bread::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}