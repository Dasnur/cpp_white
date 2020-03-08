#include <iostream>
#include <vector>
using namespace std;

class Incognizable
{
    public:
        Incognizable(){}
        Incognizable(int a)
        {
            res.push_back(a);
        }
        Incognizable(int a, int b)
        {
            res.push_back(a);
            res.push_back(b);
        }
    private:
        vector<int> res;
};