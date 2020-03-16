#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int plot;
    cin >> n >> plot;
    int tmp = n;
    uint64_t mass = 0;
    while (tmp > 0)
    {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        mass += a * b * c * plot;
        tmp--;
    }
    cout << mass;
    return 0;
}