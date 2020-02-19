#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a, b, tmp, del;

    cin >> a >> b;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    del = a;
    while (del > 0)
    {
        if (a % del == 0 && b % del == 0)
        {
            cout << del;
            return 0;
        }
        else
            del--;
    }
    return 0;
}