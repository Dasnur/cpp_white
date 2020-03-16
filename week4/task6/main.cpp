#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(void)
{
    ifstream in("input.txt");
    int n;
    int m;
    if (in.is_open())
    {
        in >> n;
        in >> m;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                int value;
                in >> value;
                in.ignore(1);
                cout << setw(10) << value;
                if (i != m - 1)
                    cout << " ";
            }
            if (j != n - 1)
                cout << endl;
        }
    }
    return 0;
}