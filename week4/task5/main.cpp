#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("input.txt");
    string line;
    double res;
    if (in.is_open())
    {
        in >> res;
        cout << fixed << setprecision(3);
        cout << res << endl;
        while (getline(in, line))
        {
            in >> res;
            cout << fixed << setprecision(3);
            cout << res << endl;
        }
    }
    return 0;
}