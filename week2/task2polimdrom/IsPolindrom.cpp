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