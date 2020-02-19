bool    IsPalindrom(string res)
{
    int n = res.size() - 1;
    for (auto i : res)
    {
        if (i != res[n])
            return false;
        n--;
    }
    return true;
}

vector<string>  PolindromFilter(vector<string> words, int minLength)
{
    vector<string> res;
    for (string i : words)
    {
        if (IsPalindrom(i) && i.size() >= minLength)
            res.push_back(i);
    }
    return (res);
}