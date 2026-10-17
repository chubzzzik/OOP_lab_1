#pragma once

class ProductFactory{
    public:
    virtual void createProduct() = 0;
};

// ===ELECTRONICS_FACTORIES===
class SmartphoneFactory:public ProductFactory{

};

class LaptopFactory:public ProductFactory{
    
};

// ===CLOTHING_FACTORIES===
class TShirtFactory:public ProductFactory{
    
};

class JacketFactory:public ProductFactory{
    
};

// ===FOOD_FACTORIES===
class MilkFactory:public ProductFactory{
    
};

class BreadFactory:public ProductFactory{
    
};
