#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    vector<int> otvet;
    for (int& i : res)
        cin >> i;
    int sum = 0;
    for (int i : res)
        sum += i;
    sum = sum / n;
    for (int i = 0; i < n; i++)
    {
        if (res[i] > sum)
            otvet.push_back(i);
    }
    cout << n - otvet.size() + 1 << endl;
    for (int i : otvet)
        cout << i << ' ';
    return 0;
}