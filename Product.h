#pragma once
#include <iostream>

struct Date {
    int day;
    int month;
    int year;
};

struct Product {
    char name[30];
    char manufacturer[30];
    int price;
    char group[30];
    Date arrivalDate;
    Date expiryDate;
};

void fillData(Product& product);
void addProduct(Product storage[], int& currentSize);
void removeProduct(Product storage[], int& currentSize, int index);
void replaceProduct(Product storage[], int currentSize, int index);
void printProduct(const Product& product);
void printAllProducts(const Product storage[], int currentSize);
void searchByManufacturer(Product storage[], int currentSize, const char* searchManufacturer);
void searchByPrice(Product storage[], int currentSize, double searchPrice);
void searchByGroup(Product storage[], int currentSize, const char* searchGroup);
void searchByArrivalDate(Product storage[], int currentSize, const Date& searchDate);
void searchByExpiryDate(Product storage[], int currentSize, const Date& searchDate);
void sortByPrice(Product storage[], int currentSize);
void sortByGroup(Product storage[], int currentSize);