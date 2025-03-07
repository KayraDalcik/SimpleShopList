#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include <string>
#include <iostream>
using namespace std;

class Electronics {
private:
    string name;
    int quantity;
    double price;
    string brand;

public:
    Electronics(string n = "", int q = 0, double p = 0.0, string b = "")
        : name(n), quantity(q), price(p), brand(b) {}

    ~Electronics() {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getBrand() const { return brand; }
    double totalCost() const { return quantity * price; }

    void display() const {
        cout << "Electronics: " << name << ", Quantity: " << quantity
            << ", Price: $" << price << ", Brand: " << brand
            << ", Total Cost: $" << totalCost() << endl;
    }
};

#endif
