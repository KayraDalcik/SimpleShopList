#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <iostream>
using namespace std;

class Clothing {
private:
    string name;
    int quantity;
    double price;
    string size;

public:
    Clothing(string n = "", int q = 0, double p = 0.0, string s = "")
        : name(n), quantity(q), price(p), size(s) {}

    ~Clothing() {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getSize() const { return size; }
    double totalCost() const { return quantity * price; }

    void display() const {
        cout << "Clothing: " << name << ", Quantity: " << quantity
            << ", Price: $" << price << ", Size: " << size
            << ", Total Cost: $" << totalCost() << endl;
    }
};

#endif
