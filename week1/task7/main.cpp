#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = 0;
    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'f')
        {
            n++;
            if (n == 2)
                res = i;
        }
    }
    if (n >= 2)
        cout << res;
    if (n == 1)
        cout << -1;
    if (n == 0)
        cout << -2;
    return 0;
}