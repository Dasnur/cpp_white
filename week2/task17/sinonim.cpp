#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    int q;
    map<string, vector<string>> m;
    cin >> q;
    while (q > 0)
    {
        string s;
        cin >> s;
        if (s == "ADD")
        {
            string s1;
            string s2;
            cin >> s1 >> s2;
            m[s1].push_back(s2);
        }
        if (s == "COUNT")
        {
            string s1;
            cin >> s1;
            int i = 0;
            for (auto item : m)
            {
                for (auto sino : item.second)
                {
                    if (sino == s1)
                        i++;
                }
            }
            if (m[s1].size() != 0) 
                cout << m[s1].size() + i - 1 << endl;
            else
                cout << i << endl;
        }
        if (s == "CHECK")
        {
            string s1;
            string s2;
            int flag = 0;
            cin >> s1 >> s2;
            for (auto sino : m[s1])
            {
                if (sino == s2)
                    flag = 1;
            }
            for (auto sino : m[s2])
            {
                if (sino == s1)
                    flag = 1;
            }
            if (flag == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        q--;
    }
    return 0;
}