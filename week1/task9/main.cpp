#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int ten;
    vector<int> res;
    cin >> ten;

    while (ten > 0)
    {
        res.push_back(ten % 2);
        ten /= 2;
    }
    for (int i = res.size() - 1; i > -1; i--)
        cout << res[i];
    return 0;
}