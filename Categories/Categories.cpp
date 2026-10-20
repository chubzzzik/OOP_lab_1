#include"Categories.h"


Electronics::Electronics(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Product(name,price,quantity,weight,"electronics"){}

Clothing::Clothing(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Product(name,price,quantity,weight,"clothing"){}

Food::Food(const std::string& name, const Price& price, const Quantity& quantity, const Weight& weight):Product(name,price,quantity,weight,"food"){}