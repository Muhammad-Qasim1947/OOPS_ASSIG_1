#include "User.h"

// User Class
int user::totalusers = 0;

user::user() : userid(0)
{
    name = "N/A";
    email = "N/A";
    phone = "0000";
    password = "N/A";
    city = "N/A";
    totalusers++;
}

user::user(int id, string n, string e, int ph, string pass, string c) : userid(id)
{
    name = n;
    email = e;
    phone = ph;
    password = pass;
    city = c;
    totalusers++;
}

void user::updateprofile(string n, string e, int ph, string pass, string c)
{
    name = n;
    email = e;
    phone = ph;
    password = pass;
    city = c;
}

void user::login(string enteremail, string enterpass) const
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

void user::logout() const
{
    cout << "Logged Out" << endl;
}

void user::showtotalusers()
{
    cout << "Total Users Are : " << totalusers << endl;
}

int user::getUserId() const
{
    return userid;
}

void user::display()
{
    cout << "User ID: " << userid << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "City: " << city << endl;
}

// Buyer Class
buyer::buyer() : userId(0)
{
    name = email = phone = password = city = "N/A";
    totalfav = 0;
    budgetlimit = 0;
    preferredbrand = "N/A";
    messagesentcount = 0;
}

buyer::buyer(int id, string n, string e, int ph, string pass, string c, int budget, string prefBrand) : userId(id)
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

void buyer::display()
{
    cout << "\nBuyer ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "City: " << city << endl;
}

void buyer::updateprofile(string n, string e, string ph, string c)
{
    name = n;
    email = e;
    phone = ph;
    city = c;
}

void buyer::savefavourites(Vehicle *v)
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

void buyer::removefavourites(int vehicleid)
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

void buyer::viewfavourites() const
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

void buyer::sendmessage(int sellerid, string message)
{
    cout << "Message Sent To Seller Id " << sellerid << " : " << message << endl;
    messagesentcount++;
}

void buyer::viewPreferences() const
{
    cout << "Budget Limit: " << budgetlimit << endl;
    cout << "Preferred Brand: " << preferredbrand << endl;
}

// Seller Class
seller::seller()
{
    sellerid = 0;
    totallisting = 0;
    rating = 0.00;
    totalsales = 0;
    isverified = false;
}
seller::seller(int id, double rate, int sales, bool verified)
{
    sellerid = id;
    rating = rate;
    totalsales = sales;
    isverified = verified;
    totallisting = 0;
}

void seller::addvehicle(Vehicle *v)
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

void seller::updateprice(int vehicleid, int price)
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

void seller::deletevehicle(int vehicleid)
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

void seller::viewlisting()
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

// Admin Class
admin::admin()
{
    adminid = 0;
    name = "N/A";
    totalapprovedlisting = 0;
    totalremovedlisting = 0;
    role = "N/A";
}
admin::admin(int id, string n, string r)
{
    adminid = id;
    name = n;
    totalapprovedlisting = 0;
    totalremovedlisting = 0;
    role = r;
}

void admin::approvelisting(Vehicle *v)
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

void admin::removedlisting(Vehicle *v)
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

void admin::blockseller(int sellerid)
{
    cout << "Seller ID : " << sellerid << " Blocked" << endl;
}

void admin::viewalllisting(Vehicle *vehicle[], int total)
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