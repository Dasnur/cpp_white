#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    string s1;
    string s2;
    cin >> n;
    while (n > 0)
    {
		map<char, int> m1;
    	map<char, int> m2;
        cin >> s1 >> s2;
        for (char i : s1)
            m1[i]++;
        for (char i : s2)
            m2[i]++;
        if (m1 == m2)
            cout << "YES" << endl;
        else
			cout << "NO" << endl;
        n--;
    }
    return 0;
}