#include <iostream>
using namespace std;

class Employee {
protected:
    string name, empID;
    double salary;
public:
    Employee(string n, string id, double sal) : name(n), empID(id), salary(sal) {}
    virtual double calculateMonthlyPay() { return salary; }
    virtual void display() {
        cout << "Name: " << name << ", ID: " << empID << ", Salary: " << salary << endl;
    }
};

class Professor : public Employee {
    string department;
public:
    Professor(string n, string id, double sal, string dept) : Employee(n, id, sal), department(dept) {}
    double calculateMonthlyPay() override { return salary + (0.1 * salary); }
    void display() override {
        Employee::display();
        cout << "Department: " << department << ", Total Pay: " << calculateMonthlyPay() << endl;
    }
};

class AdminStaff : public Employee {
    string position;
public:
    AdminStaff(string n, string id, double sal, string pos) : Employee(n, id, sal), position(pos) {}
    double calculateMonthlyPay() override { return salary + (0.05 * salary); }
    void display() override {
        Employee::display();
        cout << "Position: " << position << ", Total Pay: " << calculateMonthlyPay() << endl;
    }
};

class Janitor : public Employee {
    int hoursWorked;
public:
    Janitor(string n, string id, double sal, int hours) : Employee(n, id, sal), hoursWorked(hours) {}
    double calculateMonthlyPay() override { return hoursWorked * 500; }
    void display() override {
        Employee::display();
        cout << "Hours Worked: " << hoursWorked << ", Total Pay: " << calculateMonthlyPay() << endl;
    }
};

int main() {
    Professor prof("Alice", "P101", 50000, "Computer Science");
    AdminStaff admin("Bob", "A201", 30000, "Clerk");
    Janitor janitor("Charlie", "J301", 0, 160);

    prof.display();
    admin.display();
    janitor.display();

    return 0;
}
