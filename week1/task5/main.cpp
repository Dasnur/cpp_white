#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    if (N > B)
    {
        cout << N - N * Y / 100;
        return 0;
    }
    else if (N > A)
    {
        cout << N - N * X / 100;
        return 0;
    }
    cout << N;
    return 0;
}