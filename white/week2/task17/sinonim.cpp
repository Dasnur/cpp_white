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
	m[s2].insert(s1);
}

void 	count(map<string, set<string>> &m)
{
	string s1;
    cin >> s1;
	cout << m[s1].size() << endl;
}

void	check(map<string, set<string>> &m)
{
	string s1;
    string s2;
    cin >> s1 >> s2;
    if (m[s1].count(s2))
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