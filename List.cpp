#include <iostream>
#include <string>
#include "Food.h"
#include "Electronics.h"
#include "Clothing.h"
#include "ShoppingList.h"
using namespace std;

void displayMenu() {
    cout << "Shopping List Menu:\n";
    cout << "1. Add an Item\n";
    cout << "2. Remove an Item\n";
    cout << "3. Print the List\n";
    cout << "4. Save the Shopping List to a File\n";
    cout << "5. Exit the Program\n";
    cout << "Enter your choice: ";
}

void addItem(ShoppingList& list) {
    int category;
    cout << "Select Category:\n1. Food\n2. Electronics\n3. Clothing\nEnter choice: ";
    cin >> category;
    cin.ignore();

    if (category == 1) {
        string name;
        int quantity;
        double price;
        cout << "Enter Food Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price per Unit: ";
        cin >> price;
        list.addFood(Food(name, quantity, price));
    }
    else if (category == 2) {
        string name, brand;
        int quantity;
        double price;
        cout << "Enter Electronics Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
        cout << "Enter Brand: ";
        getline(cin, brand);
        list.addElectronics(Electronics(name, quantity, price, brand));
    }
    else if (category == 3) {
        string name, size;
        int quantity;
        double price;
        cout << "Enter Clothing Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
        cout << "Enter Size: ";
        getline(cin, size);
        list.addClothing(Clothing(name, quantity, price, size));
    }
    else {
        cout << "Invalid category selection.\n";
    }
}

void removeItem(ShoppingList& list) {
    string name;
    cout << "Enter the name of the item to remove: ";
    cin.ignore();
    getline(cin, name);
    list.removeFood(name);
    list.removeElectronics(name);
    list.removeClothing(name);
}

int main() {
    ShoppingList myList;
    myList.loadFromFile("shopping_list.txt");

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addItem(myList);
            break;
        case 2:
            removeItem(myList);
            break;
        case 3:
            myList.displayAll();
            cout << "Total Cost: $" << myList.totalCost() << endl;
            break;
        case 4:
            myList.saveToFile("shopping_list.txt");
            cout << "Shopping list saved to file.\n";
            break;
        case 5:
            myList.saveToFile("shopping_list.txt");
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
