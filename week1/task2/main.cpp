#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n = 3;
    vector<string> a;
    string res;
    for (int i = 0; i < n; i++)
    {
        cin >> res;
        a.push_back(res);
    }
    sort(begin(a), end(a));
    string min = min_element(begin(a), end(a));
    cout << a[0];
    return 0;
}