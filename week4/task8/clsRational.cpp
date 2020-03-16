#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
		p = 0;
		q = 1;
    }

    Rational(int numerator, int denominator) {
		if (numerator < 0 && denominator >= 0)
			otr = 1;
		else if (numerator >= 0 && denominator < 0)	
			otr = 1;
		else
			otr = 0;
		numerator = abs(numerator);
		denominator = abs(denominator);
        p = abs(numerator);
		q = abs(denominator);
		while (numerator != 0 && denominator != 0)
		{
			if (numerator > denominator)
				numerator = numerator % denominator;
			else
				denominator = denominator % numerator;
		}
		nod = numerator + denominator;
    }

    int Numerator() const {
		if (otr == 1)
			return p / nod * -1;
		else
			return p / nod;
    }

    int Denominator() const {
		return q / nod;
    }

private:
    int		p;
    int		q;
	int		nod;
	int		otr;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}