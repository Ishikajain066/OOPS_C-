#include <iostream>
using namespace std;

class Student {
    private:
        int rollNo;
        string name;
        int age;
        float marks;

    public:
        Student(int r, string n, int a, float m) : rollNo(r), name(n), age(a), marks(m) {}

        void display() {
            cout << "Roll No: " << rollNo << ", Name: " << name 
                 << ", Age: " << age << ", Marks: " << marks << endl;
        }
};

int main() {
    Student students[10] = {
        Student(1, "John", 18, 85.5),
        Student(2, "Alice", 19, 90.0),
        Student(3, "Bob", 18, 75.0),
        Student(4, "Charlie", 19, 88.0),
        Student(5, "David", 18, 92.0),
        Student(6, "Eva", 19, 81.5),
        Student(7, "Frank", 18, 78.5),
        Student(8, "Grace", 19, 84.0),
        Student(9, "Helen", 18, 89.5),
        Student(10, "Ivy", 19, 95.0)
    };

    for (int i = 0; i < 10; ++i) {
        students[i].display();
    }

    return 0;
}