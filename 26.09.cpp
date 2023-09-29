﻿#include <iostream>
#include <string>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:

    string zero = "\nDividing by zero is like cutting the cake into 0 pieces, which doesn't make any sense at all if you think of it, as the cake itself is already made of a single piece\n\n";

    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction(int nmrtr, int dnmntr) {
        if (dnmntr == 0) {
            cout << zero;
            dnmntr = 1;
        }
        numerator = nmrtr;
        denominator = dnmntr;
    }

    void edit() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << zero;
            denominator = 1;
        }
    }

    void print() {
        cout << "Fraction: " << numerator << "/" << denominator << "\n";
    }

    int leastCommonMultiple(int a, int b)
    {
        if (b == 0) return a;
        return leastCommonMultiple(b, a % b);
    }

    Fraction add(const Fraction& other) {
        Fraction result;
        if (denominator == other.denominator) {
            result.numerator = numerator + other.numerator;
            result.denominator = denominator;
        }
        else {
            result.numerator = (numerator * other.denominator) + (other.numerator * denominator);
            result.denominator = denominator * other.denominator;
        }
        return result;
    }

    Fraction subtract(const Fraction& other) {
        Fraction result;
        if (denominator == other.denominator) {
            result.numerator = numerator - other.numerator;
            result.denominator = denominator;
        }
        else {
            result.numerator = (numerator * other.denominator) - (other.numerator * denominator);
            result.denominator = denominator * other.denominator;
        }
        return result;
    }

    Fraction multiply(const Fraction& other) {
        Fraction result;
        if (denominator == other.denominator) {
            result.numerator = numerator * other.numerator;
            result.denominator = denominator;
        }
        else {
            result.numerator = numerator * other.numerator;
            result.denominator = denominator * other.denominator;
        }
        return result;
    }

    Fraction divide(const Fraction& other) {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        if (result.denominator == 0) {
            cout << zero; 
        }
        return result;
    }
};

void menu() {
    Fraction x;
    Fraction y;
    Fraction result;
    int choice;
    bool stop = false;

    while (!stop)
    {
        cout << "\nSet first fraction:\n";
        x.edit();
        x.print();

        cout << "\nSet second fraction:\n";
        y.edit();
        y.print();

        cout << "\nFraction operations:\n1) Add\n2) Substract\n3) Multiply\n4) Divide\n0) Exit\nChoose operation: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            result = x.add(y);
            result.print();
            break;
        case 2:
            result = x.subtract(y);
            result.print();
            break;
        case 3:
            result = x.multiply(y);
            result.print();
            break;
        case 4:
            result = x.divide(y);
            result.print();
            break;
        case 0:
            stop = true;
            break;
        default:
            cout << "Wrong input\n";
            break;
        }

    }
}

int main()
{
    menu();
}