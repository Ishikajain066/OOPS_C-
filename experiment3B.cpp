#include <iostream>
#include <vector>
using namespace std;

class Patient {
    public:
        string name;
        int age;
        string disease;
        int roomNumber;

        Patient(string n, int a, string d, int r) : name(n), age(a), disease(d), roomNumber(r) {}
};

class Hospital {
    private:
        vector<Patient*> patients;

    public:
        void addPatient(string name, int age, string disease, int roomNumber) {
            Patient* newPatient = new Patient(name, age, disease, roomNumber);
            patients.push_back(newPatient);
        }

        void displayPatients() {
            for (Patient* patient : patients) {
                cout << "Name: " << patient->name << ", Age: " << patient->age
                     << ", Disease: " << patient->disease << ", Room: " << patient->roomNumber << endl;
            }
        }

        void searchPatient(string name) {
            for (Patient* patient : patients) {
                if (patient->name == name) {
                    cout << "Found Patient - Name: " << patient->name << ", Age: " << patient->age
                         << ", Disease: " << patient->disease << ", Room: " << patient->roomNumber << endl;
                    return;
                }
            }
            cout << "Patient not found!" << endl;
        }

        void deletePatient(string name) {
            for (auto it = patients.begin(); it != patients.end(); ++it) {
                if ((*it)->name == name) {
                    delete *it;
                    patients.erase(it);
                    cout << "Patient " << name << " deleted." << endl;
                    return;
                }
            }
            cout << "Patient not found!" << endl;
        }

        ~Hospital() {
            for (Patient* patient : patients) {
                delete patient;
            }
        }
};

int main() {
    Hospital hospital;
    int choice;
    string name, disease;
    int age, roomNumber;

    do {
        cout << "\nHospital Management System:" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Display All Patients" << endl;
        cout << "3. Search Patient by Name" << endl;
        cout << "4. Delete Patient" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Disease: ";
                cin >> disease;
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                hospital.addPatient(name, age, disease, roomNumber);
                break;
            case 2:
                hospital.displayPatients();
                break;
            case 3:
                cout << "Enter Name to Search: ";
                cin >> name;
                hospital.searchPatient(name);
                break;
            case 4:
                cout << "Enter Name to Delete: ";
                cin >> name;
                hospital.deletePatient(name);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}