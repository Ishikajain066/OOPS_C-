#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& c) { return Complex(real + c.real, imag + c.imag); }
    Complex operator-(const Complex& c) { return Complex(real - c.real, imag - c.imag); }
    friend ostream& operator<<(ostream& out, const Complex& c) { out << c.real << " + " << c.imag << "i"; return out; }
    friend istream& operator>>(istream& in, Complex& c) { in >> c.real >> c.imag; return in; }
};

int main() {
    Complex c1, c2, sum, diff;
    cin >> c1 >> c2;
    sum = c1 + c2;
    diff = c1 - c2;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    return 0;
}
