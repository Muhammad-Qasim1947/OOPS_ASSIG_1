#include <iostream>
using namespace std;

// class 1
class Engine
{
private:
    string engine_num;
    int horsepow;
    string fueltype;
    int enginecapacity;
    string transmission;

public:
    Engine()
    {
        engine_num = "N/A";
        horsepow = 0;
        fueltype = "N/A";
        enginecapacity = 0;
        transmission = "N/A";
    }

    Engine(string engnum, int pow, string ftype, int engcap, string trans)
    {
        engine_num = engnum;
        horsepow = pow;
        fueltype = ftype;
        enginecapacity = engcap;
        transmission = trans;
    }

    void startengine()
    {
        cout << "Engine Is Started" << endl;
    }

    void stopengine()
    {
        cout << "Engine Stopped" << endl;
    }

    void displayengine() const
    {
        cout << "Engine Number : " << engine_num << endl;
        cout << "Horse Power : " << horsepow << endl;
        cout << "Fuel Type : " << fueltype << endl;
        cout << "Engine Capacity : " << enginecapacity << endl;
        cout << "Transmission : " << transmission << endl;
    }

    double powertocapratio() const
    {
        if (enginecapacity == 0)
            return 0;
        return (double)horsepow / enginecapacity;
    }
};

// class 2
class Carfeatures
{
private:
    bool Ac, Abs, Airbags, Sunroof, Nav;

public:
    Carfeatures()
    {
        Ac = Abs = Airbags = Sunroof = Nav = false;
    }

    Carfeatures(bool ac, bool abs, bool airbags, bool sroof, bool navbar)
    {
        Ac = ac;
        Abs = abs;
        Airbags = airbags;
        Sunroof = sroof;
        Nav = navbar;
    }

    void display() const
    {
        cout << "AC : " << Ac << endl;
        cout << "ABS : " << Abs << endl;
        cout << "AIRBAGS : " << Airbags << endl;
        cout << "SUNROOF : " << Sunroof << endl;
        cout << "NAVIGATION : " << Nav << endl;
    }

    void addFeature(string featureName)
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

    void removeFeature(string featureName)
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

    int countFeatures() const
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
};

// class 3
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
    Vehicle() : vehicleid(0)
    {
        brand = "N/A";
        model = "N/A";
        price = 0.00;
        year = 0000;
        mileage = 0000;

        totalvehicle++;
    }

    Vehicle(int id, string b, string m, double p, int y, int mil, Engine e, Carfeatures f) : vehicleid(id), engine(e), features(f)
    {
        brand = b;
        model = m;
        price = p;
        year = y;
        mileage = mil;

        totalvehicle++;
    }

    void displayvehicle() const
    {
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Price : " << price << endl;
        cout << "Year : " << year << endl;
        cout << "Mileage : " << mileage << endl;
    }

    void updateprice(double pri)
    {
        price = pri;
    }

    void updatemileage(int mile)
    {
        mileage = mile;
    }

    double calculatedepriciation(int currentyear) const
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

    static void showtotalvehicles()
    {
        cout << "Total Vehicles Listed : " << totalvehicle << endl;
    }

    ~Vehicle()
    {
        totalvehicle--;
    }

    void setprice(int p)
    {
        price = p;
    }

    int getvehicleid() const
    {
        return vehicleid;
    }

    string getbrand() const
    {
        return brand;
    }

    string getmodel() const
    {
        return model;
    }

    double getprice() const
    {
        return price;
    }

    int getyear() const
    {
        return year;
    }

    int getmileage() const
    {
        return mileage;
    }
};

int Vehicle ::totalvehicle = 0;

// class 4
class user
{
private:
    const int userid;
    string name;
    string email;
    string phone;
    string password;
    string city;

    static int totalusers;

public:
    user() : userid(0)
    {
        name = "N/A";
        email = "N/A";
        phone = "0000";
        password = "N/A";
        city = "N/A";

        totalusers++;
    }

    user(int id, string n, string e, int ph, string pass, string c) : userid(id)
    {
        name = n;
        email = e;
        phone = ph;
        password = pass;
        city = c;

        totalusers++;
    }

    void updateprofile(string n, string e, int ph, string pass, string c)
    {
        name = n;
        email = e;
        phone = ph;
        password = pass;
        city = c;
    }

    void login(string enteremail, string enterpass) const
    {
        if (enteremail == email && enterpass == password)
        {
            cout << "Login Successfull" << endl;
        }
        else
        {
            cout << "Wrong Email Or Password" << endl;
        }
    }

    void logout() const
    {
        cout << "Logged Out" << endl;
    }

    static void showtotalusers()
    {
        cout << "Total Users Are : " << totalusers << endl;
    }

    int getUserId() const
    {
        return userid;
    }

    void display()
    {
        cout << "User ID: " << userid << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
    }
};

int user ::totalusers = 0;

// class 5,
class buyer
{
private:
    const int userId;
    string name;
    string email;
    string phone;
    string password;
    string city;

    int buyerid;
    Vehicle *favourites[50];
    int totalfav;
    double budgetlimit;
    string preferredbrand;
    int messagesentcount;

public:
    buyer() : userId(0)
    {
        name = "N/A";
        email = "N/A";
        phone = "N/A";
        password = "N/A";
        city = "N/A";

        totalfav = 0;
        budgetlimit = 0;
        preferredbrand = "N/A";

        messagesentcount = 0;
    }

    buyer(int id, string n, string e, int ph, string pass, string c, int budget, string prefBrand) : userId(id)
    {
        name = n;
        email = e;
        phone = ph;
        password = pass;
        city = c;

        totalfav = 0;
        budgetlimit = budget;
        preferredbrand = prefBrand;
    }

    void display()
    {
        cout << "\nBuyer ID: " << userId << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
    }

    void updateprofile(string n, string e, string ph, string c)
    {
        name = n;
        email = e;
        phone = ph;
        city = c;
    }

    void savefavourites(Vehicle *v)
    {
        if (totalfav < 50)
        {
            favourites[totalfav++] = v;
            cout << "Vehicle ID : " << v->getvehicleid() << " Set To Favourites" << endl;
        }
        else
        {
            cout << "Favourites Limit Full" << endl;
        }
    }

    void removefavourites(int vehicleid)
    {
        for (int i = 0; i < totalfav; i++)
        {
            if (favourites[i]->getvehicleid() == vehicleid)
            {
                for (int j = i; j < totalfav - 1; j++)
                {
                    favourites[j] = favourites[j + 1];
                }
                totalfav--;
                cout << "Vehicle Of ID : " << vehicleid << " Removed From Favourites" << endl;
                return;
            }
        }
        cout << "Vehicle Not Found In Favourites" << endl;
    }

    void viewfavourites() const
    {
        if (totalfav == 0)
        {
            cout << "No Vehicle In Favourites" << endl;
        }
        else
        {
            for (int i = 0; i < totalfav; i++)
            {
                favourites[i]->displayvehicle();
            }
        }
    }

    void sendmessage(int sellerid, string message)
    {
        cout << "Message Sent To Seller Id " << sellerid << " : " << message << endl;
        messagesentcount++;
    }

    void viewPreferences() const
    {
        cout << "Budget Limit: " << budgetlimit << endl;
        cout << "Preferred Brand: " << preferredbrand << endl;
    }
};

// class 6
class seller
{
private:
    int sellerid;
    Vehicle *vehiclelisted[50];
    int totallisting;
    double rating;
    int totalsales;
    bool isverified;

public:
    seller()
    {
        sellerid = 0;
        totallisting = 0;
        rating = 0.00;
        totalsales = 0;
        isverified = false;
    }

    seller(int id, double rate, int sales, bool verified)
    {
        sellerid = id;
        rating = rate;
        totalsales = sales;
        isverified = verified;
        totallisting = 0;
    }

    void addvehicle(Vehicle *v)
    {
        if (totallisting < 50)
        {
            vehiclelisted[totallisting++] = v;
            cout << "Vehicle Added Successfully" << endl;
        }
        else
        {
            cout << "Listing Limit Reached" << endl;
        }
    }

    void updateprice(int vehicleid, int price)
    {
        for (int i = 0; i < totallisting; i++)
        {
            if (vehiclelisted[i]->getvehicleid() == vehicleid)
            {
                vehiclelisted[i]->setprice(price);
                cout << "Price Updated" << endl;
                return;
            }
        }
        cout << "Vehicle Not Found" << endl;
    }

    void deletevehicle(int vehicleid)
    {
        for (int i = 0; i < totallisting; i++)
        {
            if (vehiclelisted[i]->getvehicleid() == vehicleid)
            {
                for (int j = i; j < totallisting - 1; j++)
                {
                    vehiclelisted[j] = vehiclelisted[j + 1];
                }
                totallisting--;
                cout << "Vehicle Deleted Successfully" << endl;
                return;
            }
        }
        cout << "Vehicle Not Found" << endl;
    }

    void viewlisting()
    {
        if (totallisting == 0)
        {
            cout << "No Vehicle Listed" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < totallisting; i++)
            {
                vehiclelisted[i]->displayvehicle();
            }
        }
    }
};

// class 7
class admin
{
private:
    int adminid;
    string name;
    int totalapprovedlisting;
    int totalremovedlisting;
    string role;

public:
    admin()
    {
        adminid = 0;
        name = "N/A";
        totalapprovedlisting = 0;
        totalremovedlisting = 0;
        role = "N/A";
    }

    admin(int id, string n, string r)
    {
        adminid = id;
        name = n;
        totalapprovedlisting = 0;
        totalremovedlisting = 0;
        role = r;
    }

    void approvelisting(Vehicle *v)
    {
        if (v != nullptr)
        {
            cout << "Vehicle ID : " << v->getvehicleid() << " Approved Successfull" << endl;
            totalapprovedlisting++;
        }
        else
        {
            cout << "Invalid Vehicle" << endl;
        }
    }

    void removedlisting(Vehicle *v)
    {
        if (v != nullptr)
        {
            cout << "Vehicle ID : " << v->getvehicleid() << " Removed By Admin" << endl;
            totalremovedlisting++;
        }
        else
        {
            cout << "Invalid Vehicle" << endl;
        }
    }

    void blockseller(int sellerid)
    {
        cout << "Seller ID : " << sellerid << " Blocked" << endl;
    }

    void viewalllisting(Vehicle *vehicle[], int total)
    {
        if (total == 0)
        {
            cout << "No Listing Available" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < total; i++)
            {
                vehicle[i]->displayvehicle();
                cout << "----------------------\n";
            }
        }
    }
};

// class 8
class message
{
private:
    const int messageid;
    int senderid;
    int receiverid;
    string text;
    string datetime;
    bool isread;

public:
    message() : messageid(0)
    {
        senderid = 0;
        receiverid = 0;
        text = "N/A";
        datetime = "N/A";
        isread = false;
    }

    message(int id, int sid, int rid, string t, string dt, bool read) : messageid(id)
    {
        senderid = sid;
        receiverid = rid;
        text = t;
        datetime = dt;
        isread = read;
    }

    message(const message &m)
        : messageid(m.messageid)
    {
        senderid = m.senderid;
        receiverid = m.receiverid;
        text = m.text;
        datetime = m.datetime;
        isread = m.isread;
    }

    void sendmessage()
    {
        cout << "Message Sent From " << senderid << " to " << receiverid << endl;
    }

    void deletemessage()
    {
        cout << "Message ID " << messageid << " deleted.\n";
    }

    void displayMessage() const
    {
        cout << "Message ID: " << messageid << endl;
        cout << "From: " << senderid << endl;
        cout << "To: " << receiverid << endl;
        cout << "Text: " << text << endl;
        cout << "Date/Time: " << datetime << endl;
        cout << "Status: " << (isread ? "Read" : "Unread") << endl;
    }

    void markAsRead()
    {
        isread = true;
        cout << "Message marked as read.\n";
    }
};

// class 9
class review
{
private:
    const int reviewid;
    int buyerid;
    int sellerid;
    int rating;
    string comment;

public:
    review() : reviewid(0)
    {
        buyerid = 0;
        sellerid = 0;
        rating = 0;
        comment = "N/A";
    }

    review(int bid, int sid, int rate, string c, int rid) : reviewid(rid)
    {
        buyerid = bid;
        sellerid = sid;
        rating = rate;
        comment = c;
    }

    void addreview(string rev)
    {
        cout << "Review : " << rev << " Added Successfully" << endl;
    }

    void updateReview(int newRating, string newComment)
    {
        rating = newRating;
        comment = newComment;
        cout << "Review Updated Successfully.\n";
    }

    void deleteReview()
    {
        cout << "Review ID " << reviewid << " Deleted.\n";
    }

    void displayReview() const
    {
        cout << "Review ID: " << reviewid << endl;
        cout << "Buyer ID: " << buyerid << endl;
        cout << "Seller ID: " << sellerid << endl;
        cout << "Rating: " << rating << endl;
        cout << "Comment: " << comment << endl;
    }
};

// class 10
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
    marketplace() : country("Pakistan")
    {
        totalvehicles = 0;
        totalBuyers = 0;
        totalSellers = 0;
    }

    marketplace(int total) : country("Pakistan")
    {
        totalvehicles = total;
        totalBuyers = 0;
        totalSellers = 0;
    }

    void registerbuyer(buyer b)
    {
        if (totalBuyers < 100)
        {
            buyers[totalBuyers++] = new buyer(b);
            cout << "Buyer Registered Successfully.\n";
        }
    }

    void registerseller(seller s)
    {
        if (totalSellers < 100)
        {
            sellers[totalSellers++] = new seller(s);
            cout << "Seller Registered Successfully.\n";
        }
    }

    void addVehicle(Vehicle v)
    {
        if (totalvehicles < 200)
        {
            vehicles[totalvehicles++] = new Vehicle(v);
            cout << "Vehicle Added Successfully.\n";
        }
    }

    ~marketplace()
    {
        for (int i = 0; i < totalvehicles; i++)
            delete vehicles[i];

        for (int i = 0; i < totalBuyers; i++)
            delete buyers[i];

        for (int i = 0; i < totalSellers; i++)
            delete sellers[i];
    }

    void searchbybrand(string brandName)
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

    void searchByModel(const string &modelName)
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

    void searchByPrice(double minPrice, double maxPrice)
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

    void searchByYear(int minYear, int maxYear)
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

    void searchByMileage(int minMileage, int maxMileage)
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

    void displayallvehicles()
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

    void deleteVehicleListing(int vehicleId)
    {
        for (int i = 0; i < totalvehicles; i++)
        {
            if (vehicles[i]->getvehicleid() == vehicleId)
            {
                delete vehicles[i];

                for (int j = i; j < totalvehicles - 1; j++)
                {
                    vehicles[j] = vehicles[j + 1];
                }

                totalvehicles--;
                cout << "Vehicle Deleted Successfully.\n";
                return;
            }
        }

        cout << "Vehicle Not Found.\n";
    }
};

int main()
{
    marketplace mp;
    int choice;

    do
    {
        cout << "\n=== Vehicle Marketplace Menu ===\n";
        cout << "1. Register Buyer\n";
        cout << "2. Register Seller\n";
        cout << "3. Add Vehicle\n";
        cout << "4. Display All Vehicles\n";
        cout << "5. Search Vehicle by Brand\n";
        cout << "6. Search Vehicle by Price\n";
        cout << "7. Delete Vehicle\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, email, city, password;
            int id, phone, budget;
            string prefBrand;

            cout << "Enter Buyer ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter Email: ";
            getline(cin, email);
            cout << "Enter Phone: ";
            cin >> phone;
            cout << "Enter Password: ";
            cin >> ws;
            getline(cin, password);
            cout << "Enter City: ";
            cin >> ws;
            getline(cin, city);
            cout << "Enter Budget Limit: ";
            cin >> budget;
            cout << "Enter Preferred Brand: ";
            cin >> ws;
            getline(cin, prefBrand);

            buyer b(id, name, email, phone, password, city, budget, prefBrand);
            mp.registerbuyer(b);
        }
        else if (choice == 2)
        {
            int id, sales;
            double rating;
            bool verified;

            cout << "Enter Seller ID: ";
            cin >> id;
            cout << "Enter Rating: ";
            cin >> rating;
            cout << "Enter Total Sales: ";
            cin >> sales;
            cout << "Is Verified? (1 for Yes, 0 for No): ";
            cin >> verified;

            seller s(id, rating, sales, verified);
            mp.registerseller(s);
        }
        else if (choice == 3)
        {
            int id, year, mileage, horsepow, engcap;
            string brand, model, engnum, fueltype, trans;
            double price;
            bool ac, abs, airbags, sunroof, nav;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Brand: ";
            cin >> ws;
            getline(cin, brand);
            cout << "Enter Model: ";
            cin >> ws;
            getline(cin, model);
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Mileage: ";
            cin >> mileage;

            cout << "Engine Number: ";
            cin >> ws;
            getline(cin, engnum);
            cout << "Horse Power: ";
            cin >> horsepow;
            cout << "Fuel Type: ";
            cin >> ws;
            getline(cin, fueltype);
            cout << "Engine Capacity: ";
            cin >> engcap;
            cout << "Transmission: ";
            cin >> ws;
            getline(cin, trans);

            Engine eng(engnum, horsepow, fueltype, engcap, trans);

            cout << "AC (1/0): ";
            cin >> ac;
            cout << "ABS (1/0): ";
            cin >> abs;
            cout << "Airbags (1/0): ";
            cin >> airbags;
            cout << "Sunroof (1/0): ";
            cin >> sunroof;
            cout << "Navigation (1/0): ";
            cin >> nav;

            Carfeatures feat(ac, abs, airbags, sunroof, nav);

            Vehicle v(id, brand, model, price, year, mileage, eng, feat);
            mp.addVehicle(v);
        }
        else if (choice == 4)
        {
            cout << "\n=== All Vehicles in Marketplace ===\n";
            mp.displayallvehicles();
        }
        else if (choice == 5)
        {
            string brand;
            cout << "Enter Brand to search: ";
            cin >> ws;
            getline(cin, brand);
            mp.searchbybrand(brand);
        }
        else if (choice == 6)
        {
            double minPrice, maxPrice;
            cout << "Enter Min Price: ";
            cin >> minPrice;
            cout << "Enter Max Price: ";
            cin >> maxPrice;
            mp.searchByPrice(minPrice, maxPrice);
        }
        else if (choice == 7)
        {
            int vid;
            cout << "Enter Vehicle ID to delete: ";
            cin >> vid;
            mp.deleteVehicleListing(vid);
        }

    } while (choice != 0);

    cout << "Exiting Marketplace. Goodbye!\n";
    return 0;
}