#include <iostream>
using namespace std;

int     get_nod(int numerator, int denominator);

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
		nod = get_nod(numerator, denominator);
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

int     get_nod(int numerator, int denominator)
{
    while (numerator != 0 && denominator != 0)
	{
		if (numerator > denominator)
			numerator = numerator % denominator;
		else
			denominator = denominator % numerator;
	}
	return (numerator + denominator);
}

int     get_nok(int a, int b)
{
    return (a * b / get_nod(a, b));
}

bool    operator==(Rational lhs, Rational rhs)
{
    if (lhs.Denominator() != rhs.Denominator() || (lhs.Numerator() != rhs.Numerator()))
        return false;
    return true;
}

Rational    operator*(const Rational& lhs, const Rational& rhs)
{
    return (Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()));
}

Rational    operator/(const Rational& lhs, const Rational& rhs)
{
    return (Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()));
}

Rational    operator+(const Rational& lhs, const Rational& rhs)
{
    int nok = get_nok(lhs.Denominator(), rhs.Denominator());
    int newq1 = lhs.Numerator() * (nok / lhs.Denominator());
    int newq2 = rhs.Numerator() * (nok / rhs.Denominator());
    return (Rational(newq1 + newq2, nok));
}

Rational    operator-(const Rational& lhs, const Rational& rhs)
{
    int nok = get_nok(lhs.Denominator(), rhs.Denominator());
    int newq1 = lhs.Numerator() * (nok / lhs.Denominator());
    int newq2 = rhs.Numerator() * (nok / rhs.Denominator());
    return (Rational(newq1 - newq2, nok));
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}