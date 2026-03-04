#include "Vehicle.h"

// Engine implementation
Engine::Engine()
{
    engine_num = "N/A";
    horsepow = 0;
    fueltype = "N/A";
    enginecapacity = 0;
    transmission = "N/A";
}
Engine::Engine(string engnum, int pow, string ftype, int engcap, string trans)
{
    engine_num = engnum;
    horsepow = pow;
    fueltype = ftype;
    enginecapacity = engcap;
    transmission = trans;
}

void Engine::startengine()
{
    cout << "Engine Is Started" << endl;
}

void Engine::stopengine()
{
    cout << "Engine Stopped" << endl;
}

void Engine::displayengine() const
{
    cout << "Engine Number: " << engine_num << endl;
    cout << "Horse Power: " << horsepow << endl;
    cout << "Fuel Type: " << fueltype << endl;
    cout << "Engine Capacity: " << enginecapacity << endl;
    cout << "Transmission: " << transmission << endl;
}

double Engine::powertocapratio() const
{
    if (enginecapacity == 0)
        return 0;
    return (double)horsepow / enginecapacity;
}

// Carfeatures implementation
Carfeatures::Carfeatures()
{
    Ac = Abs = Airbags = Sunroof = Nav = false;
}

Carfeatures::Carfeatures(bool ac, bool abs, bool airbags, bool sroof, bool navbar)
{
    Ac = ac;
    Abs = abs;
    Airbags = airbags;
    Sunroof = sroof;
    Nav = navbar;
}

void Carfeatures::display() const
{
    cout << "AC : " << Ac << endl;
    cout << "ABS : " << Abs << endl;
    cout << "AIRBAGS : " << Airbags << endl;
    cout << "SUNROOF : " << Sunroof << endl;
    cout << "NAVIGATION : " << Nav << endl;
}

void Carfeatures::addFeature(string featureName)
{
    if (featureName == "Ac")
        Ac = true;
    else if (featureName == "Abs")
        Abs = true;
    else if (featureName == "Airbags")
        Airbags = true;
    else if (featureName == "Sunroof")
        Sunroof = true;
    else if (featureName == "Nav")
        Nav = true;
}

void Carfeatures::removeFeature(string featureName)
{
    if (featureName == "Ac")
        Ac = false;
    else if (featureName == "Abs")
        Abs = false;
    else if (featureName == "Airbags")
        Airbags = false;
    else if (featureName == "Sunroof")
        Sunroof = false;
    else if (featureName == "Nav")
        Nav = false;
}

int Carfeatures::countFeatures() const
{
    int count = 0;
    if (Ac)
        count++;
    if (Abs)
        count++;
    if (Airbags)
        count++;
    if (Sunroof)
        count++;
    if (Nav)
        count++;
    return count;
}

// Vehicle implementation
int Vehicle::totalvehicle = 0;

Vehicle::Vehicle() : vehicleid(0)
{
    brand = "N/A";
    model = "N/A";
    price = 0.00;
    year = 0000;
    mileage = 0000;

    totalvehicle++;
}

Vehicle::Vehicle(int id, string b, string m, double p, int y, int mil, Engine e, Carfeatures f)
    : vehicleid(id), engine(e), features(f)
{
    brand = b;
    model = m;
    price = p;
    year = y;
    mileage = mil;

    totalvehicle++;
}

Vehicle::~Vehicle()
{
    totalvehicle--;
}

void Vehicle::displayvehicle() const
{
    cout << "Brand : " << brand << endl;
    cout << "Model : " << model << endl;
    cout << "Price : " << price << endl;
    cout << "Year : " << year << endl;
    cout << "Mileage : " << mileage << endl;
}

void Vehicle::updateprice(double pri)
{
    price = pri;
}

void Vehicle::updatemileage(int mile)
{
    mileage = mile;
}

double Vehicle::calculatedepriciation(int currentyear) const
{
    if (currentyear < year)
    {
        cout << "Error: Current year is less than vehicle year!" << endl;
        return 0;
    }

    int age = currentyear - year;
    double depreciationRate = 0.02; // 2% per year
    double depreciation = price * depreciationRate * age;

    if (depreciation > price)
        depreciation = price; // Depreciation cannot exceed price

    return depreciation;
}

void Vehicle::showtotalvehicles()
{
    cout << "Total Vehicles Listed : " << totalvehicle << endl;
}

void Vehicle::setprice(int p)
{
    price = p;
}

int Vehicle::getvehicleid() const
{
    return vehicleid;
}

string Vehicle::getbrand() const
{
    return brand;
}

string Vehicle::getmodel() const
{
    return model;
}

double Vehicle::getprice() const
{
    return price;
}

int Vehicle::getyear() const
{
    return year;
}

int Vehicle::getmileage() const
{
    return mileage;
}
