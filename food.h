#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <iostream>
using namespace std;

class Food {
private:
    string name;
    int quantity;
    double pricePerUnit;

public:
    Food(string n = "", int q = 0, double p = 0.0)
        : name(n), quantity(q), pricePerUnit(p) {}

    ~Food() {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPricePerUnit() const { return pricePerUnit; }
    double totalCost() const { return quantity * pricePerUnit; }

    void display() const {
        cout << "Food: " << name << ", Quantity: " << quantity
            << ", Price per Unit: $" << pricePerUnit
            << ", Total Cost: $" << totalCost() << endl;
    }
};

#endif
