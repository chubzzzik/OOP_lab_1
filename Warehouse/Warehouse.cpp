#include"Warehouse.h"
#include<stdexcept>
#include<utility>

// ===WAREHOUSEITERATOR===
WarehouseIterator::WarehouseIterator(const std::vector<std::unique_ptr<Product>>::iterator& current, const std::vector<std::unique_ptr<Product>>::iterator& end):current_(current),end_(end){}

WarehouseIterator& WarehouseIterator::operator++(){
    current_ += 1;
    return *this;
}

Product& WarehouseIterator::operator*()const{
    return *(*current_);
}

bool WarehouseIterator::operator!=(const WarehouseIterator& other) const{
    return current_ != other.current_;
}
    
bool WarehouseIterator::operator==(const WarehouseIterator& other) const{
    return current_ == other.current_;
}


// ===CONSTWAREHOUSEITERATOR===
ConstWarehouseIterator::ConstWarehouseIterator(const std::vector<std::unique_ptr<Product>>::const_iterator& current, const std::vector<std::unique_ptr<Product>>::const_iterator& end):current_(current),end_(end){}

ConstWarehouseIterator& ConstWarehouseIterator::operator++(){
    current_ += 1;
    return *this;
}

const Product& ConstWarehouseIterator::operator*() const{
    return *(*current_);
}

bool ConstWarehouseIterator::operator!=(const ConstWarehouseIterator& other) const{
    return current_ != other.current_;
}

bool ConstWarehouseIterator::operator==(const ConstWarehouseIterator& other) const{
    return current_ == other.current_;
}


// ===WAREHOUSE===
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

Warehouse::Warehouse(Warehouse&& other) noexcept:products_(std::move(other.products_)),maxSize_(other.maxSize_),currentSize_(other.currentSize_){
    other.currentSize_ = 0;
    
}

Warehouse& Warehouse::operator=(Warehouse&& other) noexcept{
    if(this == &other){
        return *this;
    }
    products_.clear();
    products_ = std::move(other.products_);
    maxSize_ = other.maxSize_;
    currentSize_ = other.currentSize_;
    other.currentSize_ = 0;
    return *this;
}

void Warehouse::addProduct(std::unique_ptr<Product> product){
    if(products_.size() >= maxSize_){
        throw std::invalid_argument("Warehouse is full");
    }
    products_.push_back(std::move(product));
    currentSize_ += 1;
}

void Warehouse::removeById(int id){
    for(size_t i = 0; i < products_.size(); i += 1){
        if(products_[i]->getId() == id){
            products_.erase(products_.begin()+i);
            currentSize_ -= 1;
            return;
        }
    }
    throw std::invalid_argument("This Id isn't exist");
}

void Warehouse::removeByIndex(size_t index){
    if(index >= products_.size()){
        throw std::invalid_argument("Index out of range");
    }
    products_.erase(products_.begin() + index);
    currentSize_ -= 1;
}

Product* Warehouse::findById(int id){
    for(size_t i = 0; i < products_.size(); i += 1){
        if(products_[i]->getId() == id){
            return products_[i].get();
        }
    }
    throw std::invalid_argument("This Id isn't exist");
}

std::vector<Product*> Warehouse::findByCategory(const std::string& category){
    std::vector<Product*> output_vector;
    for(const auto& p : products_){
        if(p->getCategory() == category){
            output_vector.push_back(p.get());
        }
    }
    return output_vector;
}

std::vector<Product*> Warehouse::findByPrice(const Price& price){
    std::vector<Product*> output_vector;
    for(const auto& p : products_){
        if(p->getPrice().getValue() == price.getValue()){
            output_vector.push_back(p.get());
        }
    }
    return output_vector;
}

WarehouseIterator Warehouse::begin(){
    return WarehouseIterator(products_.begin(),products_.end());
}

WarehouseIterator Warehouse::end(){
    return WarehouseIterator(products_.end(),products_.end());
}

ConstWarehouseIterator Warehouse::begin() const{
    return ConstWarehouseIterator(products_.begin(), products_.end());
}

ConstWarehouseIterator Warehouse::end() const{
    return ConstWarehouseIterator(products_.end(), products_.end());
}