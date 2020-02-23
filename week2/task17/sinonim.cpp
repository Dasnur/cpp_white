#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void	add(map<string, set<string>> &m)
{
	string s1;
    string s2;
	cin >> s1 >> s2;
    m[s1].insert(s2);
}

void 	count(map<string, set<string>> &m)
{
	string s1;
    cin >> s1;
    int i = 0;
    for (auto item : m)
    {
        int flag = 0;
        for (auto sino : item.second)
        {
            if (sino == s1)
            {
                flag = 2;
                for (auto aaa : m[s1])
                {
                    if (item.first == aaa)
                    flag = 1;
                }
            } 
        }
        if (flag == 2)
            i++;
    }
    cout << i + m[s1].size() << endl;
}

void	check(map<string, set<string>> &m)
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

int main()
{
    int q;
    map<string, set<string>> m;
    cin >> q;
    while (q > 0)
    {
        string s;
        cin >> s;
        if (s == "ADD")
			add(m);
        if (s == "COUNT")
			count(m);
        if (s == "CHECK")
			check(m);
        q--;
    }
    return 0;
}