#include <iostream>
#include <utility>
using namespace std;


class ComplexNumber {
private:
    double real_part;
    double imaginary_part;
    
public:
    public:
    
    ComplexNumber(double r = 0, double i = 0) {
        real_part = r;
        imaginary_part = i;
    }

    ComplexNumber(pair<double,double>complexPair)
    {
        real_part=complexPair.first;
        imaginary_part=complexPair.second;
    }


    void display() {
        if (imaginary_part >= 0)
            cout << real_part << " + " << imaginary_part << "i" << endl;
        else
            cout << real_part << " - " << -imaginary_part << "i" << endl;
    }
};


int main() {
    ComplexNumber myObj1;
    ComplexNumber myObj2(5.0);
    ComplexNumber myObj3(3.0, 4.0);

    pair<double, double> complexPair(5.0, -7.0);
    ComplexNumber myObj4(complexPair);
    
    cout << "myObj1: "; myObj1.display();
    cout << "myObj2: "; myObj2.display();
    cout << "myObj3: "; myObj3.display();
    cout << "myObj4:" ; myObj4.display();
    return 0;
}
