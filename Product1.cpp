#include "Product.h"

void fillData(Product& product)
{
    std::cout << "Enter product name: " << std::endl;
    std::cin.getline(product.name, 30);

    std::cout << "Enter manufacturer: " << std::endl;
    std::cin.getline(product.manufacturer, 30);

    std::cout << "Enter price: " << std::endl;
    std::cin >> product.price;

    std::cout << "Enter group: " << std::endl;
    std::cin.getline(product.group, 30);

    std::cout << "Enter arrival date: " << std::endl;
    std::cin >> product.arrivalDate.day >> product.arrivalDate.month >> product.arrivalDate.year;

    std::cout << "Enter expiry date: " << std::endl;
    std::cin >> product.expiryDate.day >> product.expiryDate.month >> product.expiryDate.year;
}

void addProduct(Product storage[], int& currentSize) {
    if (currentSize < 10) {
        fillData(storage[currentSize]);
        currentSize++;
        std::cout << "Product added successfully \n";
        std::cout << "Max storage size 10 \n";
        std::cout << "Current storage size" << currentSize;
    }
    else {
        std::cout << "Storage is full. Cannot add more products\n";
    }
}

void removeProduct(Product storage[], int& currentSize, int index) {
    if (index >= 0 && index < currentSize) {
        for (int i = index; i < currentSize - 1; ++i) {
            storage[i] = storage[i + 1];
        }
        currentSize--;

        std::cout << "Product removed successfully \n";
        std::cout << "Current storage size: " << currentSize;
    }
    else {
        std::cout << "Invalid index\n";
    }
}

void replaceProduct(Product storage[], int currentSize, int index) {
    if (index >= 0 && index < currentSize) {
        std::cout << "Enter new data for the product:\n";
        fillData(storage[index]);
        std::cout << "Product replaced successfully\n";
    }
    else {
        std::cout << "Invalid index\n";
    }
}

void printProduct(const Product& product) { 
    std::cout << "Name: " << product.name << std::endl;
    std::cout << "Manufacturer: " << product.manufacturer << std::endl;
    std::cout << "Price: " << product.price << std::endl;
    std::cout << "Group: " << product.group << std::endl;
    std::cout << "Arrival Date: " << product.arrivalDate.day << "." << product.arrivalDate.month << "." << product.arrivalDate.year << std::endl;
    std::cout << "Expiry Date: " << product.expiryDate.day << "." << product.expiryDate.month << "." << product.expiryDate.year << std::endl;
}

void printAllProducts(const Product storage[], int currentSize) {
    std::cout << "All products:\n";
    for (int i = 0; i < currentSize; ++i) {
        printProduct(storage[i]);
        std::cout << "\n";
    }
}


void searchByManufacturer(Product storage[], int currentSize, const char* searchManufacturer) {
    for (int i = 0; i <= currentSize; ++i) {
        if (strcmp(storage[i].manufacturer, searchManufacturer) == 0) {
            std::cout << "Product found at index " << i << std::endl;
            return;
        }
    }

    std::cout << "Product with manufacturer '" << searchManufacturer << "' not found" << std::endl;
}

void searchByGroup(Product storage[], int currentSize, const char* searchGroup) {
    for (int i = 0; i < currentSize; ++i) {
        if (strcmp(storage[i].group, searchGroup) == 0) {
            std::cout << "Product found at index " << i << std::endl;
            return;
        }
    }
        
    std::cout << "Product with group '" << searchGroup << "' not found" << std::endl;
        
}

void searchByPrice(Product storage[], int currentSize, double searchPrice) {
    for (int i = 0; i < currentSize; ++i) {
        if (storage[i].price == searchPrice) {
            std::cout << "Product found at index " << i << std::endl;
            return;
        }
    }
       
    std::cout << "Product with price '" << searchPrice << "' not found" << std::endl;
        
    
}

void searchByArrivalDate(Product storage[], int currentSize, const Date& searchDate) {
    for (int i = 0; i < currentSize; ++i) {
        if (storage[i].arrivalDate.day == searchDate.day &&
            storage[i].arrivalDate.month == searchDate.month &&
            storage[i].arrivalDate.year == searchDate.year) {
            std::cout << "Product found at index " << i << std::endl;
            return;
        }
    }

    std::cout << "Product with arrival date not found" << std::endl;
        
    
}

void searchByExpiryDate(Product storage[], int currentSize, const Date& searchDate) {
    for (int i = 0; i < currentSize; ++i) {
        if (storage[i].expiryDate.day == searchDate.day &&
            storage[i].expiryDate.month == searchDate.month &&
            storage[i].expiryDate.year == searchDate.year) {
            std::cout << "Product found at index " << i << std::endl;
            return;
        }
    }
        
    std::cout << "Product with expiry date not found" << std::endl;
        
    
}

void sortByPrice(Product storage[], int currentSize) {
    for (int i = 0; i < currentSize - 1; ++i) {
        for (int j = 0; j < currentSize - 1 - i; ++j) {
            if (storage[j].price > storage[j + 1].price) {
                Product temp = storage[j];
                storage[j] = storage[j + 1];
                storage[j + 1] = temp;
            }
        }
    }
}

void sortByGroup(Product storage[], int currentSize) {
    for (int i = 0; i < currentSize - 1; ++i) {
        for (int j = 0; j < currentSize - 1 - i; ++j) {
            if (strcmp(storage[j].group, storage[j + 1].group) > 0) {
                Product temp = storage[j];
                storage[j] = storage[j + 1];
                storage[j + 1] = temp;
            }
        }
    }
}