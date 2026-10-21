#include<iostream>
#include<limits>
#include<stdexcept>
#include<utility>
#include"Warehouse.h"
#include"ProductFactories.h"

// ===================== ОБЩИЕ ФУНКЦИИ =====================

void printProduct(const Product& p){
    std::cout << "id: " << p.getId()
              << " | " << p.getName()
              << " | категория: " << p.getCategory()
              << " | цена: " << p.getPrice().getValue()
              << " | кол-во: " << p.getQuantity().getValue()
              << " | вес: " << p.getWeight().getValue() << " кг\n";
}

// вывод через константный итератор (const begin/end)
void printWarehouse(const std::string& title, const Warehouse& warehouse){
    std::cout << "\n=== " << title << " ===\n";
    int count = 0;
    for(const auto& p : warehouse){
        printProduct(p);
        count += 1;
    }
    if(count == 0){
        std::cout << "Склад пуст\n";
    }
}

void printProducts(const std::string& title, const std::vector<Product*>& products){
    std::cout << "\n--- " << title << " ---\n";
    if(products.empty()){
        std::cout << "Ничего не найдено\n";
        return;
    }
    for(const Product* p : products){
        printProduct(*p);
    }
}

// добавляет товар на склад и возвращает его id (id выдаёт счётчик nextId_) короче чтобы не падала программа 
int addAndGetId(Warehouse& warehouse, std::unique_ptr<Product> product){
    int id = product->getId();
    warehouse.addProduct(std::move(product));
    return id;
}

// ===================== СЦЕНАРИЙ 1 =====================

void printAddMenu(){
    std::cout << "==============================\n";
    std::cout << "   ДОБАВЛЕНИЕ ТОВАРА\n";
    std::cout << "==============================\n";
    std::cout << " Электроника\n";
    std::cout << "   1. Смартфон\n";
    std::cout << "   2. Ноутбук\n";
    std::cout << " Одежда\n";
    std::cout << "   3. Футболка\n";
    std::cout << "   4. Куртка\n";
    std::cout << " Продукты\n";
    std::cout << "   5. Молоко\n";
    std::cout << "   6. Хлеб\n";
    std::cout << "------------------------------\n";
    std::cout << "   0. Закончить добавление\n";
    std::cout << "==============================\n";
    std::cout << "Ваш выбор: ";
}

std::unique_ptr<ProductFactory> chooseFactory(int choice){
    switch(choice){
        case 1: return std::make_unique<SmartphoneFactory>();
        case 2: return std::make_unique<LaptopFactory>();
        case 3: return std::make_unique<TShirtFactory>();
        case 4: return std::make_unique<JacketFactory>();
        case 5: return std::make_unique<MilkFactory>();
        case 6: return std::make_unique<BreadFactory>();
        default: return nullptr;
    }
}

template<typename T>
bool readValue(const std::string& prompt, T& value){
    std::cout << prompt;
    if(!(std::cin >> value)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

void scenario1(){
    Warehouse warehouse(10);
    std::cout << "\nСклад создан, вместимость: 10 товаров\n\n";

    while(true){
        printAddMenu();

        int choice;
        if(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nВведите число от 0 до 6\n\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(choice == 0){
            break;
        }

        std::unique_ptr<ProductFactory> factory = chooseFactory(choice);
        if(factory == nullptr){
            std::cout << "\nНет такого пункта\n\n";
            continue;
        }

        std::string name;
        int price;
        int quantity;
        double weight;

        std::cout << "Название: ";
        std::getline(std::cin, name);

        if(!readValue("Цена: ", price) ||
           !readValue("Количество: ", quantity) ||
           !readValue("Вес (кг): ", weight)){
            std::cout << "\nОшибка ввода, товар не добавлен\n\n";
            continue;
        }

        try{
            // id фабрика не использует, настоящий id берётся из nextId_
            warehouse.addProduct(factory->createProduct(0, name, price, quantity, weight));
            std::cout << "\nТовар добавлен\n\n";
        }
        catch(const std::invalid_argument& e){
            std::cout << "\nОшибка: " << e.what() << "\n\n";
        }
    }

    printWarehouse("Товары на складе", warehouse);
}

// ===================== СЦЕНАРИЙ 2 =====================

void scenario2(){
    SmartphoneFactory smartphoneFactory;
    LaptopFactory laptopFactory;
    MilkFactory milkFactory;

    Warehouse original(10);
    original.addProduct(smartphoneFactory.createProduct(0, "Smartphone", 500, 10, 0.2));
    original.addProduct(laptopFactory.createProduct(0, "Laptop", 1200, 5, 2.1));
    original.addProduct(milkFactory.createProduct(0, "Milk", 2, 20, 1.0));

    printWarehouse("Оригинал до копирования", original);

    // глубокое копирование: каждый товар клонируется через clone()
    Warehouse copy(original);

    // меняем товары только в копии
    for(auto& p : copy){
        p.changeQuantity(-2);
        p.setPrice(Price(p.getPrice().getValue() + 100));
    }

    printWarehouse("Копия после изменений", copy);
    printWarehouse("Оригинал после изменений копии", original);

    // проверка независимости
    bool independent = true;
    for(const auto& p : original){
        Product* fromOriginal = original.findById(p.getId());
        Product* fromCopy = copy.findById(p.getId());
        if(fromOriginal == fromCopy ||
           fromOriginal->getPrice().getValue() == fromCopy->getPrice().getValue() ||
           fromOriginal->getQuantity().getValue() == fromCopy->getQuantity().getValue()){
            independent = false;
        }
    }
    std::cout << "\nОригинал не изменился, копия независима: "
              << (independent ? "да" : "нет") << "\n";
}

// ===================== СЦЕНАРИЙ 3 =====================

void scenario3(){
    SmartphoneFactory smartphoneFactory;
    MilkFactory milkFactory;

    Warehouse source(10);
    int phoneId = addAndGetId(source, smartphoneFactory.createProduct(0, "Smartphone", 500, 10, 0.2));
    int milkId = addAndGetId(source, milkFactory.createProduct(0, "Milk", 2, 20, 1.0));

    // запоминаем адреса товаров до перемещения
    Product* phoneBefore = source.findById(phoneId);
    Product* milkBefore = source.findById(milkId);

    printWarehouse("Склад до перемещения", source);

    // конструктор перемещения
    Warehouse moved(std::move(source));

    printWarehouse("Новый склад после перемещения", moved);
    // source после перемещения пуст (состояние «валидное, но пустое»)
    printWarehouse("Старый склад после перемещения", source);

    bool sameAddresses = (moved.findById(phoneId) == phoneBefore) &&
                         (moved.findById(milkId) == milkBefore);
    std::cout << "\nТовары не копировались (адреса совпадают): "
              << (sameAddresses ? "да" : "нет") << "\n";

    // оператор присваивания перемещением
    Warehouse target(5);
    target = std::move(moved);

    printWarehouse("Склад после присваивания перемещением", target);
    printWarehouse("Промежуточный склад после присваивания", moved);

    sameAddresses = (target.findById(phoneId) == phoneBefore) &&
                    (target.findById(milkId) == milkBefore);
    std::cout << "\nТовары не копировались (адреса совпадают): "
              << (sameAddresses ? "да" : "нет") << "\n";
}

// ===================== СЦЕНАРИЙ 4 =====================

void scenario4(){
    SmartphoneFactory smartphoneFactory;
    LaptopFactory laptopFactory;
    TShirtFactory tShirtFactory;
    MilkFactory milkFactory;
    BreadFactory breadFactory;

    Warehouse warehouse(10);
    int phoneId = addAndGetId(warehouse, smartphoneFactory.createProduct(0, "Smartphone", 500, 10, 0.2));
    int laptopId = addAndGetId(warehouse, laptopFactory.createProduct(0, "Laptop", 1200, 5, 2.1));
    addAndGetId(warehouse, tShirtFactory.createProduct(0, "T-Shirt", 20, 50, 0.2));
    addAndGetId(warehouse, milkFactory.createProduct(0, "Milk", 2, 20, 1.0));
    addAndGetId(warehouse, breadFactory.createProduct(0, "Bread", 2, 30, 0.5));

    printWarehouse("Склад", warehouse);

    // ---- поиск ----
    std::cout << "\n--- Поиск по id " << phoneId << " ---\n";
    printProduct(*warehouse.findById(phoneId));

    printProducts("Поиск по категории food", warehouse.findByCategory("food"));
    printProducts("Поиск по цене 2", warehouse.findByPrice(Price(2)));
    printProducts("Поиск по категории toys", warehouse.findByCategory("toys"));

    try{
        warehouse.findById(-1);
    }
    catch(const std::invalid_argument& e){
        std::cout << "\nПоиск по id -1: ошибка: " << e.what() << "\n";
    }

    // ---- удаление ----
    warehouse.removeById(laptopId);
    printWarehouse("После удаления по id " + std::to_string(laptopId), warehouse);

    warehouse.removeByIndex(0);
    printWarehouse("После удаления по индексу 0", warehouse);

    try{
        warehouse.removeById(-1);
    }
    catch(const std::invalid_argument& e){
        std::cout << "\nУдаление по id -1: ошибка: " << e.what() << "\n";
    }

    try{
        warehouse.removeByIndex(100);
    }
    catch(const std::invalid_argument& e){
        std::cout << "Удаление по индексу 100: ошибка: " << e.what() << "\n";
    }
}

// ===================== СЦЕНАРИЙ 5 =====================

void scenario5(){
    SmartphoneFactory smartphoneFactory;
    LaptopFactory laptopFactory;

    Warehouse from(10);
    Warehouse to(1);   // вместимость 1, чтобы показать переполнение

    int phoneId = addAndGetId(from, smartphoneFactory.createProduct(0, "Smartphone", 500, 10, 0.2));
    int laptopId = addAndGetId(from, laptopFactory.createProduct(0, "Laptop", 1200, 5, 2.1));

    printWarehouse("Склад-источник до переноса", from);
    printWarehouse("Склад-получатель до переноса", to);

    // transferTo кладёт копию товара на другой склад, поэтому
    // из источника товар убираем отдельным вызовом
    from.findById(phoneId)->transferTo(to);
    from.removeById(phoneId);

    printWarehouse("Склад-источник после переноса", from);
    printWarehouse("Склад-получатель после переноса", to);

    // изменение остатка и цены у перенесённого товара
    Product* moved = to.findById(phoneId);
    moved->changeQuantity(-3);
    moved->setPrice(Price(450));
    printWarehouse("Склад-получатель после изменения остатка и цены", to);

    // остаток не может стать отрицательным
    try{
        moved->changeQuantity(-1000);
    }
    catch(const std::invalid_argument& e){
        std::cout << "\nИзменение остатка на -1000: ошибка: " << e.what() << "\n";
    }

    // склад-получатель заполнен
    try{
        from.findById(laptopId)->transferTo(to);
    }
    catch(const std::invalid_argument& e){
        std::cout << "Перенос в заполненный склад: ошибка: " << e.what() << "\n";
    }
    printWarehouse("Склад-источник (ноутбук остался на месте)", from);
}

// ===================== ГЛАВНОЕ МЕНЮ =====================

void printMainMenu(){
    std::cout << "\n==============================\n";
    std::cout << "   ДЕМОНСТРАЦИОННЫЕ СЦЕНАРИИ\n";
    std::cout << "==============================\n";
    std::cout << "   1. Склад, фабрики, итератор\n";
    std::cout << "   2. Копирование склада\n";
    std::cout << "   3. Перемещение склада\n";
    std::cout << "   4. Поиск и удаление товаров\n";
    std::cout << "   5. Перемещение товара (transferTo)\n";
    std::cout << "------------------------------\n";
    std::cout << "   0. Выход\n";
    std::cout << "==============================\n";
    std::cout << "Ваш выбор: ";
}

int main(){
    while(true){
        printMainMenu();

        int choice;
        if(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nВведите число от 0 до 5\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){
            case 0: return 0;
            case 1: scenario1(); break;
            case 2: scenario2(); break;
            case 3: scenario3(); break;
            case 4: scenario4(); break;
            case 5: scenario5(); break;
            default: std::cout << "\nНет такого пункта\n";
        }
    }
}