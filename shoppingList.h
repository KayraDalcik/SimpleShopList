#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <vector>
#include <fstream>
#include <string>
#include "Food.h"
#include "Electronics.h"
#include "Clothing.h"
using namespace std;

class ShoppingList {
private:
    vector<Food> foods;
    vector<Electronics> electronics;
    vector<Clothing> clothing;

public:
    ShoppingList() {}

    ~ShoppingList() {}

    void addFood(const Food& f) { foods.push_back(f); }
    void addElectronics(const Electronics& e) { electronics.push_back(e); }
    void addClothing(const Clothing& c) { clothing.push_back(c); }

    void removeFood(const string& name) {
        for (auto it = foods.begin(); it != foods.end(); ++it) {
            if (it->getName() == name) {
                foods.erase(it);
                break;
            }
        }
    }

    void removeElectronics(const string& name) {
        for (auto it = electronics.begin(); it != electronics.end(); ++it) {
            if (it->getName() == name) {
                electronics.erase(it);
                break;
            }
        }
    }

    void removeClothing(const string& name) {
        for (auto it = clothing.begin(); it != clothing.end(); ++it) {
            if (it->getName() == name) {
                clothing.erase(it);
                break;
            }
        }
    }

    void displayAll() const {
        cout << "Food Items:\n";
        for (const auto& f : foods) f.display();
        cout << "Electronics Items:\n";
        for (const auto& e : electronics) e.display();
        cout << "Clothing Items:\n";
        for (const auto& c : clothing) c.display();
    }

    double totalCost() const {
        double total = 0.0;
        for (const auto& f : foods) total += f.totalCost();
        for (const auto& e : electronics) total += e.totalCost();
        for (const auto& c : clothing) total += c.totalCost();
        return total;
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& f : foods)
            file << "Food," << f.getName() << "," << f.getQuantity() << "," << f.getPricePerUnit() << "\n";
        for (const auto& e : electronics)
            file << "Electronics," << e.getName() << "," << e.getQuantity() << "," << e.getPrice() << "," << e.getBrand() << "\n";
        for (const auto& c : clothing)
            file << "Clothing," << c.getName() << "," << c.getQuantity() << "," << c.getPrice() << "," << c.getSize() << "\n";
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) return;
        string type, name, extra;
        int quantity;
        double price;

        while (file.good()) {
            getline(file, type, ',');
            if (type == "Food") {
                getline(file, name, ',');
                file >> quantity;
                file.ignore();
                file >> price;
                file.ignore();
                addFood(Food(name, quantity, price));
            }
            else if (type == "Electronics") {
                getline(file, name, ',');
                file >> quantity;
                file.ignore();
                file >> price;
                file.ignore();
                getline(file, extra);
                addElectronics(Electronics(name, quantity, price, extra));
            }
            else if (type == "Clothing") {
                getline(file, name, ',');
                file >> quantity;
                file.ignore();
                file >> price;
                file.ignore();
                getline(file, extra);
                addClothing(Clothing(name, quantity, price, extra));
            }
        }
    }
};

#endif
