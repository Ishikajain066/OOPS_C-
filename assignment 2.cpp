#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
protected:
    int productID;
    string name;
    float price;

public:
    Product(int id, const string& n, float p) : productID(id), name(n), price(p) {}

    virtual void displayProductDetails() const {
        cout << "Product Info: ID = " << productID << ", Name = " << name << ", Price = " << price;
    }

    virtual ~Product() {}
};

class Electronics : public Product {
private:
    int warrantyPeriod;

public:
    Electronics(int id, const string& n, float p, int warranty)
        : Product(id, n, p), warrantyPeriod(warranty) {}

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << ", Warranty = " << warrantyPeriod << " years" << endl;
    }
};

class Furniture : public Product {
private:
    string materialType;

public:
    Furniture(int id, const string& n, float p, const string& material)
        : Product(id, n, p), materialType(material) {}

    void displayProductDetails() const override {
        Product::displayProductDetails();
        cout << ", Material = " << materialType << endl;
    }
};

int main() {
    vector<Product*> inventory;

    inventory.push_back(new Electronics(101, "Smartphone", 500.00, 2));
    inventory.push_back(new Furniture(202, "Sofa", 300.00, "Wood"));

    for (const auto& product : inventory) {
        product->displayProductDetails();
    }

    for (auto& product : inventory) {
        delete product;
    }

    return 0;
}