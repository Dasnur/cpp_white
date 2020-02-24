#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class   SortedStrings
{
    public:
        void AddString(const string& s)
        {
            res.push_back(s);
        }
        vector<string> GetSortedStrings()
        {
            sort(begin(res), end(res));
            return res;
        }
    private:
        vector<string> res;
};