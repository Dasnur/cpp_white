vector<int>    Reversed(const vector<int>& v)
{
    vector<int> tmp;

    for (int i = v.size() - 1; i > -1; i--)
        tmp.push_back(v[i]);
    return tmp;
}