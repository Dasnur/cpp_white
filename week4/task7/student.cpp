#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student
{
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main()
{
    int n;
    cin >> n;
    int i = 0;
    vector<Student> students(n);
    while (i < n)
    {
        string name;
        string surname;
        int day;
        int month;
        int year;
        cin >> name >> surname >> day >> month >> year;
        students[i].name = name;
        students[i].surname = surname;
        students[i].day = day;
        students[i].month = month;
        students[i].year = year;
        i++;
    }
    int m = n;
    cin >> n;
    while (n > 0)
    {
        string zapros;
        int ind;
        cin >> zapros >> ind;
        ind = ind - 1;
        if (zapros == "name" && (ind + 1 <= m) && ((ind + 1) > 0))
        {
            cout << students[ind].name << " " << students[ind].surname << endl;
        }
        else if (zapros == "date" && (ind + 1 <= m) && ((ind + 1) > 0))
        {
            cout << students[ind].day << "." << students[ind].month << "." << students[ind].year << endl;
        }
        else
            cout << "bad request" << endl;
        n--;
    }
    return 0;
}