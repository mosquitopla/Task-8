#include "Product.h"
using namespace std;

int main() {
    const int maxStorageSize = 10;
    Product storage[maxStorageSize];
    int currentSize = 0;
    int choice = 0;

    while (true)
    {
        cout << "\tMenu"<< endl ;
        cout << "Enter 1 to add product" << endl;
        cout << "Enter 2 to remove product" << endl;
        cout << "Enter 3 to replace product" << endl;
        cout << "Enter 4 to search product by manufacturer" << endl;
        cout << "Enter 5 to search product by price" << endl;
        cout << "Enter 6 to search product by group" << endl;
        cout << "Enter 7 to search product by arrival date" << endl;
        cout << "Enter 8 to search product by expiry date" << endl;
        cout << "Enter 9 to sort product by price" << endl;
        cout << "Enter 10 to sort product by group" << endl;
        cout << "Enter 11 to print products" << endl;
        cin >> choice;

        if (choice == 1) {

            addProduct(storage, currentSize);
        }

        if (choice == 2) {

            int indexremove = 0;
            cout << "Enter index: ";
            cin >> indexremove;
            removeProduct(storage, currentSize, indexremove);
        }
        
        if (choice == 3) {

            int indexreplace = 0;
            cout << "Enter index: ";
            cin >> indexreplace;
            replaceProduct(storage, currentSize, indexreplace);
        }

        if (choice == 4) {

            std::cout << "Enter product manufacturer to search: ";
            char searchManufacturer[30];
            std::cin.ignore();
            std::cin.getline(searchManufacturer, 30);
            searchByManufacturer(storage, currentSize, searchManufacturer);
        }

        if (choice == 5) {

            std::cout << "Enter product price to search: ";
            double searchPrice;
            std::cin >> searchPrice;
            searchByPrice(storage, currentSize, searchPrice);
        }

        if (choice == 6) {

            std::cout << "Enter product group to search: ";
            char searchGroup[30];
            std::cin.ignore();
            std::cin.getline(searchGroup, 30);
            searchByGroup(storage, currentSize, searchGroup);
        }

        if (choice == 7) {

            std::cout << "Enter arrival date to search (day month year): ";
            Date searchDate;
            std::cin >> searchDate.day >> searchDate.month >> searchDate.year;
            searchByArrivalDate(storage, currentSize, searchDate);
        }

        if (choice == 8) {

            std::cout << "Enter expiry date to search (day month year): ";
            Date searchExpiryDate;
            std::cin >> searchExpiryDate.day >> searchExpiryDate.month >> searchExpiryDate.year;
            searchByExpiryDate(storage, currentSize, searchExpiryDate);
        }

        if (choice == 9) {

            sortByPrice(storage, currentSize);
        }

        if (choice == 10) {

            sortByGroup(storage, currentSize);
        }

        if (choice == 11) {

            printAllProducts(storage, currentSize);
        }
    }

}