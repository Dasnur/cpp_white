#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    int n;
    vector<string> v;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        v.push_back(s);
        n--;
    }
    set<string> s(begin(v), end(v));
    cout << s.size() << endl; 
}