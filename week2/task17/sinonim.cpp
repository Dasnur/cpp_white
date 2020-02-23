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
	set<string> tmp;
	for (auto item : m)
	{
		if (item.second.count(s1))
			tmp.insert(item.first);
	}
	tmp.insert(m[s1].begin(), m[s1].end());
    cout << tmp.size() << endl;
}

void	check(map<string, set<string>> &m)
{
	string s1;
    string s2;
    int flag = 0;
    cin >> s1 >> s2;
    if (m[s1].count(s2) || m[s2].count(s1))
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