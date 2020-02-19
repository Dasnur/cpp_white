#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void    new_bus(map<string, vector<string>>& m, vector<string>& trash)
{
    string bus;
    int stops;

    cin >> bus >> stops;
    while (stops > 0)
    {
        string stop;
        cin >> stop;
        m[bus].push_back(stop);
        stops--;
    }
    trash.push_back(bus);
}

void    buses_for_stop(map<string, vector<string>>& m, vector<string>& trash)
{
    string stop;
    cin >> stop;
    int flag = 0;
    for (auto tr : trash)
    {
        for (auto item : m)
        {
            if (tr == item.first)
            {
                for (auto stops : item.second)
                {
                    if (stops == stop)
                    {
                        cout << item.first << ' ';
                        flag = 1;
                        //break;
                    }
                }
            }
        }
    }
    if (flag != 1)
        cout << "No stop";
    cout << endl;
}

void    stops_for_bus(map<string, vector<string>>& m)
{
    string bus;
    cin >> bus;
    if (m.count(bus) == 0)
    {
        cout << "No bus" << endl;
        return ;
    }
    for (auto stops : m[bus])
    {
        string res;
        for (auto item1 : m)
        {
            if (item1.first != bus)
            {
                for (auto stops1 : item1.second)
                {
                    if (stops1 == stops)
                    {
                        res += item1.first;
                        res += " ";
                    }
                }
            }
        }
        if (res.size() != 0)
            cout << "Stop " << stops << ": " << res << endl;
        else
            cout << "Stop "<< stops << ": no interchange" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    map<string, vector<string>> m;
    vector<string> trash;
    while (n > 0)
    {
        string s;
        cin >> s;
        if (s == "NEW_BUS")
            new_bus(m, trash);
        if (s == "BUSES_FOR_STOP")
            buses_for_stop(m, trash);
        if (s == "STOPS_FOR_BUS")
            stops_for_bus(m);
        if (s == "ALL_BUSES")
        {
            if (m.size() == 0)
                cout << "No buses" << endl;
            else
            {
                for (auto bus : m)
                {
                    cout << "Bus " << bus.first << ": ";
                    for (auto stop : bus.second)
                    {
                        cout << stop << ' ';
                    }
                    cout << endl;
                }
            }
        }
        n--;
    }
    return 0;
}