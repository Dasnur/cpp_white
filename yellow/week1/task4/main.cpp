#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

bool    operator==(const Region& region1, const Region& region)
{
    return (tie(region1.std_name, region1.parent_std_name, region1.names, region1.population) == 
    tie(region.std_name, region.parent_std_name, region.names, region.population));
}

bool    operator<(const Region& region1, const Region& region)
{
    return (tie(region1.std_name, region1.parent_std_name, region1.names, region1.population) <
    tie(region.std_name, region.parent_std_name, region.names, region.population));
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    map<Region, int> m;
    for (const auto &region1 : regions)
    {
        m[region1]++;
    }
    int tmp = 0;
    int res = 0;
    for (auto i : m)
    {
        if (i.second > res)
            res = i.second;
    }
    return (res);
}
