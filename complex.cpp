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


    ComplexNumber(pair<double, double> complex_pair) {
        real_part = complex_pair.first;
        imaginary_part = complex_pair.second;
    }

    ComplexNumber(string complex_string) {
        real_part = 0;
        imaginary_part = 0;

        complex_string.erase(remove(complex_string.begin(), complex_string.end(), ' '), complex_string.end());
        if (!complex_string.empty() && complex_string[0] == '+') complex_string.erase(0, 1);

        if (complex_string.find_first_of("1234567890") != complex_string.npos) {
            int minus1_pos = 40, minus2_pos = 40, plus_pos = 40, i_pos = 40;

            if (complex_string.find('i') != complex_string.npos) i_pos = complex_string.find('i');
            if (complex_string.find('+') != complex_string.npos) plus_pos = complex_string.find('+');
            if (complex_string.find('-') != complex_string.npos) {
                minus1_pos = complex_string.find_first_of('-');
                minus2_pos = complex_string.find_last_of('-');
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
                imaginary_part = stod(complex_string.substr(0, i_pos));
                if (i_pos + 1 != complex_string.length())
                    real_part = stod(complex_string.substr(min_sign));
            } else {
                real_part = stod(complex_string.substr(0, min_sign));
                if (i_pos != 40)
                    imaginary_part = stod(complex_string.substr(min_sign));
            }
        }
    }

    ComplexNumber& operator=(const pair<double, double>& complex_pair) {
        real_part = complex_pair.first;
        imaginary_part = complex_pair.second;
        return *this;
    }

    ComplexNumber& operator=(const string& complex_string) {
        *this = ComplexNumber(complex_string);
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
        else 
            ss << real_part;
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const ComplexNumber& number) {
            os << number.to_string();
            return os;
    }

    ComplexNumber operator-(const ComplexNumber& number)
    {
        ComplexNumber result;
        result.real_part = real_part - number.real_part;
        result.imaginary_part = imaginary_part - number.imaginary_part;
        return result;
    }
    ComplexNumber operator+(const ComplexNumber& number)
    {
        ComplexNumber result;
        result.real_part = real_part + number.real_part;
        result.imaginary_part = imaginary_part + number.imaginary_part;
        return result;
    }
    ComplexNumber operator+(const string& number)
    {
        ComplexNumber result;
        result.real_part = real_part + ComplexNumber(number).real_part;
        result.imaginary_part = imaginary_part +  ComplexNumber(number).imaginary_part;
        return result;
    }
    
     ComplexNumber operator*(const ComplexNumber& number)
    {
        ComplexNumber result;
        result.real_part = (real_part * number.real_part) - (imaginary_part * number.imaginary_part);
        result.imaginary_part = (real_part * number.imaginary_part) + (imaginary_part * number.real_part);
        return result;
    }

     ComplexNumber operator/(const ComplexNumber& number)
    {
        ComplexNumber result;
        double module=number.real_part*number.real_part+number.imaginary_part*number.imaginary_part;
        result.real_part=real_part*number.real_part+imaginary_part*number.imaginary_part;
        result.imaginary_part = imaginary_part * number.real_part - real_part * number.imaginary_part;

        result.real_part/=module;
        result.imaginary_part/=module;
        
        return result;
    }


    void display() const {
        cout << to_string() << endl;
    }

};


