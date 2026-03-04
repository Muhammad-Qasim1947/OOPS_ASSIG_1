#ifndef USER_H
#define USER_H

#include <iostream>
#include "Vehicle.h"
using namespace std;

// User Class
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
    user();
    user(int id, string n, string e, int ph, string pass, string c);
    void updateprofile(string n, string e, int ph, string pass, string c);
    void login(string enteremail, string enterpass) const;
    void logout() const;
    static void showtotalusers();
    int getUserId() const;
    void display();
};

// Buyer Class
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
    buyer();
    buyer(int id, string n, string e, int ph, string pass, string c, int budget, string prefBrand);
    void display();
    void updateprofile(string n, string e, string ph, string c);
    void savefavourites(Vehicle *v);
    void removefavourites(int vehicleid);
    void viewfavourites() const;
    void sendmessage(int sellerid, string message);
    void viewPreferences() const;
};

// Seller Class
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
    seller();
    seller(int id, double rate, int sales, bool verified);
    void addvehicle(Vehicle *v);
    void updateprice(int vehicleid, int price);
    void deletevehicle(int vehicleid);
    void viewlisting();
};

// Admin Class
class admin
{
private:
    int adminid;
    string name;
    int totalapprovedlisting;
    int totalremovedlisting;
    string role;

public:
    admin();
    admin(int id, string n, string r);
    void approvelisting(Vehicle *v);
    void removedlisting(Vehicle *v);
    void blockseller(int sellerid);
    void viewalllisting(Vehicle *vehicle[], int total);
};

#endif