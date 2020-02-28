#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    string line;
    if (in.is_open())
    {
        while (getline(in, line))
            cout << line << endl;
    }
    else
		cout << "error";
    return 0; 
}