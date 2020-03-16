#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
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
    if (stream)
    {
        stream >> p;
        stream.ignore(1);
        stream >> q;
        if (p != 0 && q != 1)
        {
            Rational tmp(p, q);
            res = tmp;
        }
    }
    return stream;
}   

Rational    operator*(const Rational& lhs, const Rational& rhs)
{
    return (Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()));
}

bool		operator<(const Rational& lhs, const Rational& rhs)
{
    int nok = get_nok(lhs.Denominator(), rhs.Denominator());
    int newq1 = lhs.Numerator() * (nok / lhs.Denominator());
    int newq2 = rhs.Numerator() * (nok / rhs.Denominator());
    if (newq1 < newq2)
		return (true);
	return false;
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
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}