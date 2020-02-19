#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int& i : res)
        cin >> i;
    int sum = 0;
    for (int i : res)
        sum += i;
    sum = sum / n;
    for (int i = 0; i < n; i++)
    {
        if (res[i] > sum)
            cout << i << ' ';
    }
    return 0;
}