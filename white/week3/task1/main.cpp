#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int     main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n > 0)
    {
        int i;
        cin >> i;
        v.push_back(i);
        n--;
    }
    sort(begin(v), end(v), [](int x, int j){
        if (abs(x) < abs(j))
            return true;
        return false;});
    for (auto i : v)
        cout << i << ' ';
}