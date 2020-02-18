#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (a <= b)
    {
        if (a % 2 == 0)
        {
            cout << a;
            if (a != b && a != b - 1)
                cout << ' ';
        }
        a++;
    }
    return 0;
}