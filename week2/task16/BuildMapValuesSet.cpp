#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m)
{
    set<string> s;
    for (auto item : m)
        s.insert(item.second);
    return s;
}