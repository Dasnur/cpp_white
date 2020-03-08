#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int q;
    int n;
    int i = 1;
    map <int, vector<string>> m;

    cin >> q;
	int flag;
    while (q > 0)
    {
		flag = 0;
        vector<string> tmp;
        cin >> n;
        while (n > 0)
        {
            string s;
            cin >> s;
            tmp.push_back(s);
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