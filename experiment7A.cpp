#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    const string aadharCard;
    const string panCard;
    string address;
    string contactNumber;

public:
    Person(string aadhar, string pan, string addr, string contact)
        : aadharCard(aadhar), panCard(pan), address(addr), contactNumber(contact) {}

    void setAddress(string addr) {
        address = addr;
    }

    void setContactNumber(string contact) {
        contactNumber = contact;
    }

    string getAddress() const {
        return address;
    }

    string getContactNumber() const {
        return contactNumber;
    }

    void display() const {
        cout << "Aadhar Card: " << aadharCard << endl;
        cout << "PAN Card: " << panCard << endl;
        cout << "Address: " << address << endl;
        cout << "Contact Number: " << contactNumber << endl;
    }
};

int main() {
    Person p1("123456789012", "ABCDE1234F", "123 Street", "9876543210");
    p1.display();
    p1.setAddress("456 Avenue");
    p1.setContactNumber("8765432109");
    p1.display();
    return 0;
}
