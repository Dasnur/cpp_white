#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    int q;
    int n;
    int i = 1;
    map <int, set<string>> m;

    cin >> q;
	int flag;
    while (q > 0)
    {
		flag = 0;
        set<string> tmp;
        cin >> n;
        while (n > 0)
        {
            string s;
            cin >> s;
            tmp.insert(s);
            n--;
        }
		for (auto item : m)
		{
			if (item.second == tmp)
			{
				cout << "Already exists for " << item.first << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
        	m[i] = tmp;
        	cout << "New bus " << i << endl;
        	i++;
		}
        q--;
    }
}