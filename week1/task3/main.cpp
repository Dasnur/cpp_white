#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    vector<double> a;
    double res;
    for (int i = 0; i < 3; i++)
    {
        cin >> res;
        a.push_back(res);
    }
    if (a[0] == 0)
    {
        cout << -a[2] / a[1];
        return 0;
    }
    double diskr = a[1] * a[1] - 4 * a[0] * a[2];
    if (diskr > 0)
    {
        cout << (-1 * a[1] + sqrt(diskr)) / (2 * a[0]) << ' ';
        cout << (-1 * a[1] - sqrt(diskr)) / (2 * a[0]);
    }
    else if(diskr == 0.0)
    {
        cout << (-1 * a[1]) / (2 * a[0]);
    }
    return 0;
}