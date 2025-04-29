#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Vehicle class
class Vehicle {
protected:
    string id;
    string make;
    string model;
    int year;
    double dailyRate;
    bool rented;

public:
    // Constructor
    Vehicle(string id, string make, string model, int year, double rate)
        : id(id), make(make), model(model), year(year), dailyRate(rate), rented(false) {}
    
    // Virtual destructor
    virtual ~Vehicle() {}
    
    // Getters
    string getId() const { return id; }
    bool isAvailable() const { return !rented; }
    
    // Rental operations
    void rent() { rented = true; }
    void returnVehicle() { rented = false; }
    
    // Virtual functions
    virtual double calculateCost(int days) const { return dailyRate * days; }
    
    // Display info
    virtual void display() const {
        cout << "ID: " << id 
             << " | " << year << " " << make << " " << model
             << " | Daily Rate: $" << dailyRate
             << " | Status: " << (rented ? "Rented" : "Available") << endl;
    }
};

// Car class that inherits from Vehicle
class Car : public Vehicle {
private:
    int doors;
    string fuelType;

public:
    // Constructor
    Car(string id, string make, string model, int year, double rate, int doors, string fuel)
        : Vehicle(id, make, model, year, rate), doors(doors), fuelType(fuel) {}
    
    // Display info (override)
    void display() const override {
        Vehicle::display();
        cout << "   Features: " << doors << " doors, " << fuelType << " fuel" << endl;
    }
};

// Rental Management System
class RentalSystem {
private:
    vector<Vehicle*> inventory;

public:
    // Add vehicle to inventory
    void addVehicle(Vehicle* v) {
        inventory.push_back(v);
    }
    
    // Display all available vehicles
    void showAvailable() const {
        cout << "\n=== AVAILABLE VEHICLES ===" << endl;
        bool found = false;
        
        for (const auto& v : inventory) {
            if (v->isAvailable()) {
                v->display();
                found = true;
            }
        }
        
        if (!found) {
            cout << "No vehicles available at this time." << endl;
        }
    }
    
    // Find vehicle by ID
    Vehicle* findVehicle(const string& id) {
        for (auto& v : inventory) {
            if (v->getId() == id) {
                return v;
            }
        }
        return nullptr;
    }
    
    // Rent a vehicle
    void rentVehicle(const string& id, int days) {
        Vehicle* v = findVehicle(id);
        
        if (v && v->isAvailable()) {
            v->rent();
            double cost = v->calculateCost(days);
            cout << "Vehicle rented successfully!" << endl;
            cout << "Total cost for " << days << " days: $" << cost << endl;
        } else {
            cout << "Error: Vehicle not found or already rented." << endl;
        }
    }
    
    // Return a vehicle
    void returnVehicle(const string& id) {
        Vehicle* v = findVehicle(id);
        
        if (v && !v->isAvailable()) {
            v->returnVehicle();
            cout << "Vehicle returned successfully!" << endl;
        } else {
            cout << "Error: Vehicle not found or not currently rented." << endl;
        }
    }
};

// Main function with simple menu
int main() {
    RentalSystem system;
    
    // Add some vehicles to the system
    system.addVehicle(new Car("C001", "Toyota", "Camry", 2022, 45.00, 4, "Hybrid"));
    system.addVehicle(new Car("C002", "Honda", "Civic", 2023, 40.00, 4, "Gasoline"));
    system.addVehicle(new Car("C003", "Tesla", "Model 3", 2023, 75.00, 4, "Electric"));
    
    int choice;
    string id;
    int days;
    
    // Menu loop
    do {
        cout << "\n===== VEHICLE RENTAL SYSTEM =====" << endl;
        cout << "1. View Available Vehicles" << endl;
        cout << "2. Rent a Vehicle" << endl;
        cout << "3. Return a Vehicle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                system.showAvailable();
                break;
                
            case 2:
                system.showAvailable();
                cout << "\nEnter vehicle ID to rent: ";
                cin >> id;
                cout << "Enter number of rental days: ";
                cin >> days;
                system.rentVehicle(id, days);
                break;
                
            case 3:
                cout << "Enter vehicle ID to return: ";
                cin >> id;
                system.returnVehicle(id);
                break;
                
            case 4:
                cout << "Thank you for using our rental system. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}

