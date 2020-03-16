#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    while (n > 0)
    {
        int val;
        cin >> val;
        v.push_back(val);
        n--;
    }
    int64_t sum;
    sum = 0;
    for (auto i : v)
        sum += i;
    int avg = sum / (int)v.size();
    n = 0;
     for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] > avg)
            n++;
    }
    cout << n << endl;
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i] > avg)
            cout << i << " ";
    }
    return 0;
}