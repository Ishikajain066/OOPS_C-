#include <iostream>
#include <string>
using namespace std;

class Passenger {
public:
    string name;
    int ticketNumber;

    Passenger(string n, int t) : name(n), ticketNumber(t) {}
};

class TicketReservationSystem {
private:
    Passenger* passengers[100];
    int count;

public:
    TicketReservationSystem() : count(0) {}

    void addPassenger(string name, int ticketNumber) {
        passengers[count++] = new Passenger(name, ticketNumber);
    }

    void displayPassengers() {
        for (int i = 0; i < count; i++) {
            cout << "Name: " << passengers[i]->name << ", Ticket Number: " << passengers[i]->ticketNumber << endl;
        }
    }

    Passenger* searchByTicketNumber(int ticketNumber) {
        for (int i = 0; i < count; i++) {
            if (passengers[i]->ticketNumber == ticketNumber) {
                return passengers[i];
            }
        }
        return nullptr;
    }
};

int main() {
    TicketReservationSystem system;
    system.addPassenger("Alice", 101);
    system.addPassenger("Bob", 102);
    system.addPassenger("Charlie", 103);

    system.displayPassengers();

    Passenger* result = system.searchByTicketNumber(102);
    if (result) {
        cout << "Passenger found: " << result->name << endl;
    } else {
        cout << "Passenger not found." << endl;
    }

    return 0;
}