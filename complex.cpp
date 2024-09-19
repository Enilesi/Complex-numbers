#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
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
        if (!complexString.empty() && complexString[0] == '+') complexString.erase(0, 1);

        if (complexString.find_first_of("1234567890") != complexString.npos) {
            int minus1_pos = 40, minus2_pos = 40, plus_pos = 40, i_pos = 40;

            if (complexString.find('i') != complexString.npos) i_pos = complexString.find('i');
            if (complexString.find('+') != complexString.npos) plus_pos = complexString.find('+');
            if (complexString.find('-') != complexString.npos) {
                minus1_pos = complexString.find_first_of('-');
                minus2_pos = complexString.find_last_of('-');
            }

            auto const ignore_zero = [](auto const& a, auto const& b) -> bool {
                if (0 == a) {
                    return false;
                } else if (0 == b) {
                    return true;
                }
                return a < b;
            };
            double min_sign = min({minus1_pos, minus2_pos, plus_pos}, ignore_zero);
            if (i_pos < min_sign) {
                imaginary_part = stod(complexString.substr(0, i_pos));
                if (i_pos + 1 != complexString.length())
                    real_part = stod(complexString.substr(min_sign));
            } else {
                real_part = stod(complexString.substr(0, min_sign));
                if (i_pos != 40)
                    imaginary_part = stod(complexString.substr(min_sign));
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

    string to_string() const {
        stringstream ss;
        if (real_part == 0 && imaginary_part == 0)
            ss << "0";
        else if (real_part == 0 && imaginary_part != 0) {
            ss << imaginary_part << "i";
        } else if (imaginary_part > 0 && real_part != 0)
            ss << real_part << " + " << imaginary_part << "i";
        else if (imaginary_part < 0 && real_part != 0)
            ss << real_part << " - " << -imaginary_part << "i";
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const ComplexNumber& number) {
        if (number.real_part == 0 && number.imaginary_part == 0)
            os << "0";
        else if (number.real_part == 0 && number.imaginary_part != 0)
            os << number.imaginary_part << "i";
        else if (number.imaginary_part > 0)
            os << number.real_part << " + " << number.imaginary_part << "i";
        else if (number.imaginary_part < 0)
            os << number.real_part << " - " << -number.imaginary_part << "i";
        return os;
    }

    ComplexNumber operator-(const ComplexNumber& number)
    {
        ComplexNumber result;
        result.real_part = real_part - number.real_part;
        result.imaginary_part = imaginary_part - number.imaginary_part;
        return result;
    }

    void display() const {
        cout << to_string() << endl;
    }



};

int main() {
    ComplexNumber nr1, nr2;
    nr1 = "5-10i";
    nr2 = "3+2i";

    cout << "Before : 5-10i, 3+2i" << endl;
    cout << "After : " << nr1<<",  "<<nr2 << endl;
    cout <<"("<<nr1<< ") - ("<<nr2<<") = "<<nr1-nr2<<endl;
    return 0;
}
