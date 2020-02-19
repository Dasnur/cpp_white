#include <iostream>
#include <string>
#include <vector>
using namespace std;

void    dump(const vector<vector<string>>& month)
{
    int n;
    cin >> n;
    cout << month[n - 1].size() << ' ';
    if (month[n - 1].size() > 0)
    {
        for (auto i : month[n - 1])
            cout << i << ' ';
    }
    cout << endl;
}

void    add(vector<vector<string>>& month)
{
    int n;
    string s;
    cin >> n >> s;
    month[n - 1].push_back(s);
}

void    next(vector<vector<string>>& month, int& m)
{
    if (m % 12 == 0)
    {
        month[27].insert(end(month[27]), begin(month[28]), end(month[28]));
        month[27].insert(end(month[27]), begin(month[29]), end(month[29]));
        month[27].insert(end(month[27]), begin(month[30]), end(month[30]));
        month.resize(28);
    }
    else if (m == 6)
        return ;
    else if (m == 11)
        return ;
    else if (m % 2 == 1)
        month.resize(31);
    else if (m % 2 == 0)
    {
        month[29].insert(end(month[29]), begin(month[30]), end(month[30]));
        month.resize(30);
    }
    m++;
}   

int     main()
{
    int n;
    int m = 0;
    vector<vector<string>> month(31);
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        if (s == "ADD")
            add(month);
        if (s == "NEXT")
            next(month, m);
        if (s == "DUMP")
            dump(month);
        n--;
    }
    return 0;
}