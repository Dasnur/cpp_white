#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class   FuncPart
{
    public:
        FuncPart(char oper1, double value1)
        {
            oper = oper1;
            value = value1;
        }
        double Apply(double res) const
        {
            if (oper == '+')
                res += value;
            else if (oper == '*')
                res *= value;
            else if (oper == '/')
                res /= value;
            else
                res -= value;
            return res;
        }
        void Invert()
        {
            if (oper == '+')
                oper = '-';
            else if (oper == '-')
                oper = '+';
            else if (oper == '*')
                oper = '/';
            else
                oper = '*';
        }
    private:
        char oper;
        double value;
};

class Function
{
    public:
        double Apply(double value) const
        {
            for (auto item : Parts)
                value = item.Apply(value);
            return value;
        }
        void AddPart(char oper, double value)
        {
            Parts.push_back({oper, value});
        }
        void Invert()
        {
            for (auto& item : Parts)
                item.Invert();
            reverse(begin(Parts), end(Parts));
        }
    private:
        vector<FuncPart> Parts;
};