#include <iostream>
#include <vector>
#include <string>
#include "MoveStrings.cpp"
using namespace std;

int main()
{  
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for (auto i : destination)
        cout << i;
    return 0;
}