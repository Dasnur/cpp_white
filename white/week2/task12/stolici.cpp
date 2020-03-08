#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void    change_capital(map<string, string>& m)
{
    string  country;
    string  new_capital;
    int old_size = m.size();
    cin >> country >> new_capital;
    string old_capital = m[country];
    m[country] = new_capital;
    if (old_size < m.size())
    {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        return ;
    }
    if (old_capital != m[country])
        cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
    else
        cout << "Country " << country << " hasn't changed its capital" << endl;
}

void    rename(map<string, string>& m)
{
    string old_country;
    string new_country;

    cin >> old_country >> new_country;
    if (m.count(old_country) == 0 || m.count(new_country) != 0)
        cout << "Incorrect rename, skip" << endl;
    else
    {
        m[new_country] = m[old_country];
        m.erase(old_country);
        cout << "Country " << old_country << " with capital " << m[new_country] << " has been renamed to " << new_country << endl;
    }
}

void    about(map<string, string>& m)
{
    string country;

    cin >> country;
    if (!m.count(country))
        cout << "Country " << country << " doesn't exist " << endl;
    else
        cout << "Country " << country << " has capital " << m[country] << endl;
}

int     main()
{
    int n;
    cin >> n;
    map<string, string> m;
    while (n > 0)
    {
        string s;
        cin >> s;
        if (s == "CHANGE_CAPITAL")
            change_capital(m);
        if (s == "RENAME")
            rename(m);
        if (s == "ABOUT")
            about(m);
        if (s == "DUMP")
        {
            if (m.size() == 0)
                cout << "There are no countries in the world" << endl;
            else
            {
                for (auto item : m)
                {
                    cout << item.first << '/' << item.second << ' ';
                }
            }
        }
        n--;
    }
    return 0;
}