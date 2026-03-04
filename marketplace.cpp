#include "Marketplace.h"

// Constructors
marketplace::marketplace() : country("Pakistan")
{
    totalvehicles = 0;
    totalBuyers = 0;
    totalSellers = 0;
}

marketplace::marketplace(int total) : country("Pakistan")
{
    totalvehicles = total;
    totalBuyers = 0;
    totalSellers = 0;
}

// Buyer / Seller registration
void marketplace::registerbuyer(buyer b)
{
    if (totalBuyers < 100)
    {
        buyers[totalBuyers++] = new buyer(b);
        cout << "Buyer Registered Successfully.\n";
    }
}

void marketplace::registerseller(seller s)
{
    if (totalSellers < 100)
    {
        sellers[totalSellers++] = new seller(s);
        cout << "Seller Registered Successfully.\n";
    }
}

// Vehicle management
void marketplace::addVehicle(Vehicle v)
{
    if (totalvehicles < 200)
    {
        vehicles[totalvehicles++] = new Vehicle(v);
        cout << "Vehicle Added Successfully.\n";
    }
}

// Destructor
marketplace::~marketplace()
{
    for (int i = 0; i < totalvehicles; i++)
        delete vehicles[i];

    for (int i = 0; i < totalBuyers; i++)
        delete buyers[i];

    for (int i = 0; i < totalSellers; i++)
        delete sellers[i];
}

// Vehicle search functions
void marketplace::searchbybrand(string brandName)
{
    bool found = false;
    for (int i = 0; i < totalvehicles; i++)
    {
        if (vehicles[i]->getbrand() == brandName)
        {
            vehicles[i]->displayvehicle();
            found = true;
        }
    }
    if (!found)
        cout << "No Vehicle Found Of This Brand.\n";
}

void marketplace::searchByModel(const string &modelName)
{
    bool found = false;
    for (int i = 0; i < totalvehicles; i++)
    {
        if (vehicles[i]->getmodel() == modelName)
        {
            vehicles[i]->displayvehicle();
            cout << "---------------------\n";
            found = true;
        }
    }
    if (!found)
        cout << "No vehicles found for model: " << modelName << endl;
}

void marketplace::searchByPrice(double minPrice, double maxPrice)
{
    bool found = false;
    for (int i = 0; i < totalvehicles; i++)
    {
        double price = vehicles[i]->getprice();
        if (price >= minPrice && price <= maxPrice)
        {
            vehicles[i]->displayvehicle();
            cout << "---------------------\n";
            found = true;
        }
    }
    if (!found)
        cout << "No vehicles found in price range " << minPrice << " - " << maxPrice << endl;
}

void marketplace::searchByYear(int minYear, int maxYear)
{
    bool found = false;
    for (int i = 0; i < totalvehicles; i++)
    {
        int yr = vehicles[i]->getyear();
        if (yr >= minYear && yr <= maxYear)
        {
            vehicles[i]->displayvehicle();
            cout << "---------------------\n";
            found = true;
        }
    }
    if (!found)
        cout << "No vehicles found in year range " << minYear << " - " << maxYear << endl;
}

void marketplace::searchByMileage(int minMileage, int maxMileage)
{
    bool found = false;
    for (int i = 0; i < totalvehicles; i++)
    {
        int mil = vehicles[i]->getmileage();
        if (mil >= minMileage && mil <= maxMileage)
        {
            vehicles[i]->displayvehicle();
            cout << "---------------------\n";
            found = true;
        }
    }
    if (!found)
        cout << "No vehicles found in mileage range " << minMileage << " - " << maxMileage << endl;
}

// Display / Delete Vehicles
void marketplace::displayallvehicles()
{
    if (totalvehicles == 0)
    {
        cout << "No Vehicles Available.\n";
        return;
    }
    for (int i = 0; i < totalvehicles; i++)
    {
        vehicles[i]->displayvehicle();
        cout << "---------------------\n";
    }
}

void marketplace::deleteVehicleListing(int vehicleId)
{
    for (int i = 0; i < totalvehicles; i++)
    {
        if (vehicles[i]->getvehicleid() == vehicleId)
        {
            delete vehicles[i];
            for (int j = i; j < totalvehicles - 1; j++)
                vehicles[j] = vehicles[j + 1];
            totalvehicles--;
            cout << "Vehicle Deleted Successfully.\n";
            return;
        }
    }
    cout << "Vehicle Not Found.\n";
}