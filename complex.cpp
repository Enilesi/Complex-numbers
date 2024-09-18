#include <iostream>
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;

class ComplexNumber {
private:
    double real_part;
    double imaginary_part;

public:
    ComplexNumber(double r = 0, double i = 0) {
        real_part = r;
        imaginary_part = i;
    }

    ComplexNumber(pair<double, double> complexPair) {
        real_part = complexPair.first;
        imaginary_part = complexPair.second;
    }

    ComplexNumber(string complexString) {
        real_part = 0;
        imaginary_part = 0;

        complexString.erase(remove(complexString.begin(), complexString.end(), ' '), complexString.end());
        if (!complexString.empty() && complexString[0] == '+') {
            complexString.erase(0, 1);
        }

        if (complexString.find_first_of("1234567890") != complexString.npos) {
            int minus_pos = 40, plus_pos = 40, i_pos = 40;

            size_t len = complexString.length();

            if (complexString.find('+') != complexString.npos) plus_pos = complexString.find('+');
            if (complexString.find('-') != complexString.npos) minus_pos = complexString.find('-');
            if (complexString.find('i') != complexString.npos) i_pos = complexString.find('i');

            if (plus_pos == 40 && minus_pos == 40) {
                if (i_pos == 40) {
                    real_part = stod(complexString);
                } else {
                    imaginary_part = stod(complexString.erase(len - 1, len));
                }
            } else {  
                if (i_pos == len - 1) {
                    if (minus_pos != 40) {
                        real_part = stod(complexString.substr(0, minus_pos)); 
                        imaginary_part = stod(complexString.substr(minus_pos + 1));
                    } else if (plus_pos != 40) {
                        real_part = stod(complexString.substr(0, plus_pos));
                        imaginary_part = stod(complexString.substr(plus_pos + 1));
                    }
                } else {
                    imaginary_part = stod(complexString.substr(0, i_pos));
                    real_part = stod(complexString.substr(i_pos + 2));
                }
                if (minus_pos < i_pos && plus_pos > i_pos) {
                    imaginary_part = -imaginary_part;
                } else if (minus_pos != 40) {
                    real_part = -real_part;
                }
            }
        }
    }
    
    ComplexNumber& operator=(const pair<double, double>& complexPair) {
        real_part = complexPair.first;
        imaginary_part = complexPair.second;
        return *this;
    }

    ComplexNumber& operator=(const string& complexString) {
        *this = ComplexNumber(complexString);
        return *this;
    }

    void display() const {
        if (imaginary_part >= 0)
            cout << real_part << " + " << imaginary_part << "i" << endl;
        else
            cout << real_part << " - " << -imaginary_part << "i" << endl;
    }
};

int main() {
    ComplexNumber nr1;
    ComplexNumber nr2(5.0, 4.0);

    cout << "Before nr2: "; nr1.display();
    cout << "Before nr2: "; nr2.display();

    nr1 = make_pair(3.0, 7.0);
    cout << "After nr1: "; nr1.display();

    nr2 = "6 + 8i";
    cout << "After nr2: "; nr2.display();

    nr1 = make_pair(9.0, -5.0);
    cout << "After nr1: "; nr1.display();

    nr2 = "-4i + 10";
    cout << "After nr2: "; nr2.display();

    return 0;
}