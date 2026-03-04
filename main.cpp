#include <iostream>
#include "vehicle.h"
#include "user.h"
#include "marketplace.h"

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