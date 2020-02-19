#include <iostream>
#include <string>
#include <vector>
using namespace std;

void    come(vector<bool>& q)
{
    int n;
    cin >> n;
    if (n >= 0)
    {
        while (n > 0)
        {
            q.push_back(false);
            n--;
        }
    }
    else
    {
        while (n < 0)
        {
            q.pop_back();
            n++;
        }
    }
}

void    quiet(vector<bool>& q, int flag)
{
    int i;
    cin >> i;
    q[i] = flag;
}

void    worry(const vector<bool>& q)
{
    int res = 0;
    for (auto i : q)
    {
        if (i == true)
            res++;
    }
    cout << res;
}

int     main(){
    int n;
    vector<bool> q;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        if (s == "COME")
            come(q);
        if (s == "QUIET")
            quiet(q, 0);
        if (s == "WORRY")
            quiet(q, 1);
        if (s == "WORRY_COUNT")
            worry(q);
        n--;
    }
    return 0;
}