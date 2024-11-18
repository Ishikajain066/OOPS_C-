#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream logfile("logfile.txt");
    ofstream errorfile("error.txt");
    string line;

    while (getline(logfile, line)) {
        if (line.find("Error") != string::npos || line.find("error") != string::npos) {
            errorfile << line << endl;
        }
    }

    logfile.close();
    errorfile.close();
    return 0;
}
