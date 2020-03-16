#include <iostream>
#include <sstream>
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

    void    setNumerator(int Num) {
        p = Num;
    }

    void    setDenominator(int Den)
    {
        q = Den;
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
	int		nod;
	int		otr;
    int		p;
    int		q;
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

ostream&   operator<<(ostream& stream, const Rational& res)
{
    stream << res.Numerator() << "/" << res.Denominator();
    return (stream);
}    

istream&   operator>>(istream& stream, Rational& res)
{
    int p = 0;
    int q = 1;
    char c;
    if (stream)
    {
        stream >> p;
        stream >> c;
        if (c != '/')
            return stream;
        stream >> q;
        res = {p, q};
    }
    return stream;
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
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}