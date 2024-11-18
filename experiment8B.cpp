#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand, model;
    int year;
    double rentalPrice;
public:
    Vehicle(string b, string m, int y, double price) : brand(b), model(m), year(y), rentalPrice(price) {}
    virtual double getRentalCost(int days) { return days * rentalPrice; }
    virtual void display() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << ", Daily Rental Price: " << rentalPrice << endl;
    }
};

class Car : public Vehicle {
    int numDoors;
public:
    Car(string b, string m, int y, double price, int doors) : Vehicle(b, m, y, price), numDoors(doors) {}
    double getRentalCost(int days) override {
        double cost = Vehicle::getRentalCost(days);
        if (days > 7) cost *= 0.95;
        return cost;
    }
    void display() override {
        Vehicle::display();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class Motorcycle : public Vehicle {
    int engineDisplacement;
public:
    Motorcycle(string b, string m, int y, double price, int engine) : Vehicle(b, m, y, price), engineDisplacement(engine) {}
    double getRentalCost(int days) override {
        double cost = Vehicle::getRentalCost(days);
        if (days < 3) cost *= 0.9;
        return cost;
    }
    void display() override {
        Vehicle::display();
        cout << "Engine Displacement: " << engineDisplacement << " cc" << endl;
    }
};

class Bicycle : public Motorcycle {
    string frameMaterial;
public:
    Bicycle(string b, string m, int y, string material) : Motorcycle(b, m, y, 200, 0), frameMaterial(material) {}
    double getRentalCost(int days) override { return days * 200; }
    void display() override {
        Motorcycle::display();
        cout << "Frame Material: " << frameMaterial << endl;
    }
};

int main() {
    Car car("Toyota", "Corolla", 2020, 1500, 4);
    Motorcycle moto("Yamaha", "R15", 2021, 800, 150);
    Bicycle bike("Hero", "Ranger", 2022, "Steel");

    car.display();
    cout << "Rental Cost for 10 days: " << car.getRentalCost(10) << endl;

    moto.display();
    cout << "Rental Cost for 2 days: " << moto.getRentalCost(2) << endl;

    bike.display();
    cout << "Rental Cost for 5 days: " << bike.getRentalCost(5) << endl;

    return 0;
}
