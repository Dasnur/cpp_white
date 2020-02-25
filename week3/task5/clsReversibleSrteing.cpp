class   ReversibleString
{
    public:
        ReversibleString(const string& s)
        {
            res = s;
        }
        ReversibleString(){}
        void Reverse()
        {
            string rres = res;
            int k = res.size() - 1;
            for (int i = 0; i < res.size(); ++i)
            {
                rres[k] = res[i];
                k--;
            }
            res = rres;
        }
        string ToString() const
        {
            return res;
        }
    private:
        string res;
};