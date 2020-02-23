#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int		cc(vector<string> &v, string s)
{
	for (auto item : v)
	{
		if (item == s)
			return 1;
	}
	return 0;
}

void	add(map<string, vector<string>> &m)
{
	string s1;
    string s2;
	cin >> s1 >> s2;
	m[s1].push_back(s2);
}

void 	count(map<string, vector<string>> &m)
{
	string s1;
    cin >> s1;
    int i = 0;
	set<string> tmp;
	for (auto item : m)
	{
		if (cc(item.second, s1))
			tmp.insert(item.first);
	}
	tmp.insert(m[s1].begin(), m[s1].end());
    cout << tmp.size() << endl;
}

void	check(map<string, vector<string>> &m)
{
	string s1;
    string s2;
    int flag = 0;
    cin >> s1 >> s2;
    if (cc(m[s1], s2) || cc(m[s2], s1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

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
			add(m);
        if (s == "COUNT")
			count(m);
        if (s == "CHECK")
			check(m);
        q--;
    }
    return 0;
}