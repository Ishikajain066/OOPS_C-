#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    Student() {
        name = "";
        rollNumber = 0;
        marks = 0.0;
    }

    Student(string n, int r, float m) {
        name = n;
        rollNumber = r;
        marks = m;
    }

    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        marks = s.marks;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1;
    Student s2("John", 101, 89.5);
    Student s3(s2);

    cout << "Student 1: " << endl;
    s1.display();
    
    cout << "Student 2: " << endl;
    s2.display();
    
    cout << "Student 3: " << endl;
    s3.display();

    return 0;
}