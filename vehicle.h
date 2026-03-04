#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

// Engine Class
class Engine
{
private:
    string engine_num;
    int horsepow;
    string fueltype;
    int enginecapacity;
    string transmission;

public:
    Engine();
    Engine(string engnum, int pow, string ftype, int engcap, string trans);
    void startengine();
    void stopengine();
    void displayengine() const;
    double powertocapratio() const;
};

// Carfeatures Class
class Carfeatures
{
private:
    bool Ac, Abs, Airbags, Sunroof, Nav;

public:
    Carfeatures();
    Carfeatures(bool ac, bool abs, bool airbags, bool sroof, bool navbar);
    void display() const;
    void addFeature(string featureName);
    void removeFeature(string featureName);
    int countFeatures() const;
};

// Vehicle Class
class Vehicle
{
private:
    const int vehicleid;
    string brand;
    string model;
    double price;
    int year;
    int mileage;
    Engine engine;
    Carfeatures features;

    static int totalvehicle;

public:
    Vehicle();
    Vehicle(int id, string b, string m, double p, int y, int mil, Engine e, Carfeatures f);
    void displayvehicle() const;
    void updateprice(double pri);
    void updatemileage(int mile);
    double calculatedepriciation(int currentyear) const;
    static void showtotalvehicles();
    ~Vehicle();
    void setprice(int p);
    int getvehicleid() const;
    string getbrand() const;
    string getmodel() const;
    double getprice() const;
    int getyear() const;
    int getmileage() const;
};

#endif