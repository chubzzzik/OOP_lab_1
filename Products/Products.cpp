#include"Products.h"
#include"Warehouse.h"

// =====ELECTRONICS=====

// ===SMARTPHONE===
Smartphone::Smartphone(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Electronics(name,price,quantity,weight){}

Product* Smartphone::clone(){
    return new Smartphone(*this);
}

void Smartphone::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}
// ===LAPTOP===
Laptop::Laptop(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Electronics(name,price,quantity,weight){}

Product* Laptop::clone(){
    return new Laptop(*this);
}

void Laptop::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

// =====CLOTHING=====

// ===TSHIRT===
TShirt::TShirt(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Clothing(name,price,quantity,weight){}

Product* TShirt::clone(){
    return new TShirt(*this);
}

void TShirt::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

// ===JACKET===
Jacket::Jacket(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Clothing(name,price,quantity,weight){}

Product* Jacket::clone(){
    return new Jacket(*this);
}

void Jacket::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}

// =====FOOD=====

// ===MILK===
Milk::Milk(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Food(name,price,quantity,weight){}

Product* Milk::clone(){
    return new Milk(*this);
}

void Milk::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}
// ===BREAD===
Bread::Bread(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Food(name,price,quantity,weight){}

Product* Bread::clone(){
    return new Bread(*this);
}

void Bread::transferTo(Warehouse& other){
    other.addProduct(std::unique_ptr<Product>(clone()));
}