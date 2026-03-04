#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <iostream>
#include "Vehicle.h"
#include "User.h"
using namespace std;

class marketplace
{
private:
    Vehicle *vehicles[200];
    buyer *buyers[100];
    seller *sellers[100];
    admin admins[5];

    int totalvehicles;
    const string country;
    int totalBuyers;
    int totalSellers;

public:
    marketplace();
    marketplace(int total);
    ~marketplace();

    void registerbuyer(buyer b);
    void registerseller(seller s);
    void addVehicle(Vehicle v);

    void searchbybrand(string brandName);
    void searchByModel(const string &modelName);
    void searchByPrice(double minPrice, double maxPrice);
    void searchByYear(int minYear, int maxYear);
    void searchByMileage(int minMileage, int maxMileage);

    void displayallvehicles();
    void deleteVehicleListing(int vehicleId);
};

#endif