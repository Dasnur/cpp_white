#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string    low_registr(string s)
{
    for (char &ch : s)
    {
        if ((ch >= 'A') && (ch <= 'Z'))
            ch = ch + 32;
    }
    return s;
}

int     main()
{
    int n;
    cin >> n;
    vector<string> v;
    while (n > 0)
    {
        string s;
        cin >> s;
        v.push_back(s);
        n--;
    }
    sort(begin(v), end(v), [](string s1, string s2){
        return low_registr(s1) < low_registr(s2);
    });
    for (auto item : v)
        cout << item << ' ';
}