#include <iostream>
#include <string>
using namespace std;

class Transportation {
public:
    double calculateCost(double weight) {
        if (weight >= 0.1 && weight <= 1) {
            return 5 + (2 * weight);
        } else if (weight > 1 && weight <= 10) {
            return 10 + (1.5 * weight);
        } else if (weight > 10 && weight <= 50) {
            return 20 + (1 * weight);
        }
        return 0;
    }

    double calculateCost(double length, double width, double height) {
        double volume = length * width * height / 1000000;
        if (volume < 0.1) {
            return 10 + (0.5 * volume);
        } else if (volume < 0.5) {
            return 15 + (0.25 * volume);
        } else {
            return 25 + (0.1 * volume);
        }
    }

    double calculateCost(string packageType, double weight) {
        if (packageType == "Ground") {
            if (weight >= 0.1 && weight <= 1) {
                return 5 + (2 * weight);
            } else if (weight > 1 && weight <= 10) {
                return 10 + (1.5 * weight);
            } else if (weight > 10 && weight <= 50) {
                return 20 + (1 * weight);
            }
        } else if (packageType == "Air") {
            if (weight >= 0.1 && weight <= 1) {
                return 10 + (3 * weight);
            } else if (weight > 1 && weight <= 10) {
                return 20 + (2 * weight);
            } else if (weight > 10 && weight <= 50) {
                return 30 + (1.5 * weight);
            }
        } else if (packageType == "Express") {
            if (weight >= 0.1 && weight <= 1) {
                return 15 + (4 * weight);
            } else if (weight > 1 && weight <= 10) {
                return 30 + (3 * weight);
            } else if (weight > 10 && weight <= 50) {
                return 40 + (2 * weight);
            }
        }
        return 0;
    }
};

int main() {
    Transportation transport;

    double weight = 5.5;
    cout << "Cost based on weight (" << weight << " kg): $" << transport.calculateCost(weight) << endl;

    double length = 150;
    double width = 50;
    double height = 30;
    cout << "Cost based on dimensions (" << length << "x" << width << "x" << height << " cm): $" 
         << transport.calculateCost(length, width, height) << endl;

    string packageType = "Express";
    double packageWeight = 7.5;
    cout << "Cost for " << packageType << " package with weight (" << packageWeight << " kg): $" 
         << transport.calculateCost(packageType, packageWeight) << endl;

    return 0;
}