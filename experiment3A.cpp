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
        Student(1, "ishika", 18, 85.5),
        Student(2, "mahi", 19, 90.0),
        Student(3, "manoj", 18, 75.0),
        Student(4, "ram", 19, 88.0),
        Student(5, "shyam", 18, 92.0),
        Student(6, "naresh", 19, 81.5),
        Student(7, "kv", 18, 78.5),
        Student(8, "karan", 19, 84.0),
        Student(9, "kank", 18, 89.5),
        Student(10, "manvi", 19, 95.0)
    };

    for (int i = 0; i < 10; ++i) {
        students[i].display();
    }

    return 0;
}