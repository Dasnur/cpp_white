#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream to("output.txt");
    string line;
    if (in.is_open())
    {
        while (getline(in, line))
            to << line << endl;
    }
    return 0;
}