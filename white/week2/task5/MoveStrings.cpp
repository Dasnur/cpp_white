#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& src, vector<string>& dest)
{
    for (auto i : src)
        dest.push_back(i);
    src.clear();
}