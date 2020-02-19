void    Reverce(vector<int>& v)
{
    vector<int> tmp;

    for (i = v.size() - 1; i > -1; i--)
        tmp.push_back(v[i]);
    v = tmp;
}