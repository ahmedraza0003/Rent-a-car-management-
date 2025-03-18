#include <iostream>
#include <string>

using namespace std;

int TOTAL_CARS = 5; // Number of cars in the system

// Structure to store car details
struct Car {
    int id;
    string model;
    float rentPerDay;
    bool available;
};

// Function to display available cars
void showAvailableCars(Car cars[], int size) {
    cout << "\nAvailable Cars:\n";
    cout << "ID\tModel\t\tRent Per Day\n";
    for (int i = 0; i < size; i++) {
        if (cars[i].available) {
            cout << cars[i].id << "\t" << cars[i].model << "\t\t$" << cars[i].rentPerDay << endl;
        }
    }
}

// Function to rent a car
void rentCar(Car cars[], int size) {
    int carId;
    cout << "\nEnter Car ID to rent: ";
    cin >> carId;

    for (int i = 0; i < size; i++) {
        if (cars[i].id == carId && cars[i].available) {
            cars[i].available = false;
            cout << "You have rented: " << cars[i].model << " for $" << cars[i].rentPerDay << " per day.\n";
            return;
        }
    }
    cout << "Car not available or invalid ID!\n";
}

// Function to return a rented car
void returnCar(Car cars[], int size) {
    int carId;
    cout << "\nEnter Car ID to return: ";
    cin >> carId;

    for (int i = 0; i < size; i++) {
        if (cars[i].id == carId && !cars[i].available) {
            cars[i].available = true;
            cout << "You have returned: " << cars[i].model << ". Thank you!\n";
            return;
        }
    }
    cout << "Invalid Car ID or car was not rented!\n";
}

int main() {
    Car cars[5] = {
        {1, "Toyota Corolla", 40, true},
        {2, "Honda Civic", 50, true},
        {3, "Ford Mustang", 100, true},
        {4, "Tesla Model 3", 120, true},
        {5, "BMW X5", 150, true}
    };

    int choice;
    do {
        cout << "\n===== Rent a Car System =====\n";
        cout << "1. Show Available Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showAvailableCars(cars, TOTAL_CARS);
                break;
            case 2:
                rentCar(cars, TOTAL_CARS);
                break;
            case 3:
                returnCar(cars, TOTAL_CARS);
                break;
            case 4:
                cout << "Thank you for using the Car Rental System!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

