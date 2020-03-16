#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;

class Date {
public:
    Date()
    {}
    Date (int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void    SetYear(int res)
    {
        year = res;
    }
    void    SetMonth(int res)
    {
        month = res;
    }
    void    SetDay(int res)
    {
        day = res;
    }
  int GetYear() const
  {
      return (year);
  }
  int GetMonth() const
  {
      return (month);
  }
  int GetDay() const
  {
      return (day);
  }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() < rhs.GetYear())
        return true;
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() < rhs.GetMonth())
            return true;
    }
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() == rhs.GetMonth())
        {
            if (lhs.GetDay() < rhs.GetDay())
                return true;
        }
    }
    return false;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event)
    {
        dbase[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
        if (dbase[date].count(event))
        {
            dbase[date].erase(event);
            return true;
        }
        else
            return false;
    }
    int  DeleteDate(const Date& date)
    {
        int n;
        n = dbase[date].size();
        dbase[date].clear();
        return n;
    }
    void Find(const Date& date) const
    {
        if (dbase.count(date))
        {
            if (dbase.at(date).size())
            {
                for (auto i : dbase.at(date))
                    cout << i << endl;
            }
        }
    }
    
    void Print() const{
        for (auto i : dbase)
        {
            if (i.second.size() != 0)
            {
                for (auto k : i.second)
                {
                    cout << setw(4) << setfill('0');
                    cout << i.first.GetYear() << "-";
                    cout << setw(2) << setfill('0');
                    cout << i.first.GetMonth() << "-";
                    cout << setw(2) << setfill('0');
                    cout << i.first.GetDay();
                    cout << " " << k << endl;
                }
            }
        }
    }
private:
    map<Date, set<string>> dbase;
};

void    GetDate(stringstream &ss, Date& date)
{
    int year, month, day;
    char tmp;
    int flag = 0;
    int otr = 0;
    string err;
    string tmp1;
    stringstream inarg;
    ss >> tmp1;
    inarg << tmp1;
    if ((inarg.peek() < 48 || inarg.peek() > 57) && inarg.peek() != 43 && inarg.peek() != 45)
        throw invalid_argument("Wrong date format: " + tmp1);
    inarg >> year;
    inarg >> tmp;
    if (tmp != '-')
        throw invalid_argument("Wrong date format: " + tmp1);
    if ((inarg.peek() < 48 || inarg.peek() > 57))
    {
        if (inarg.peek() == 45)
        {
            otr = 1;
            inarg.ignore(1);
        }
        if (inarg.peek() == 43)
        {
            inarg.ignore(1);
        }
        if (inarg.peek() < 48 || inarg.peek() > 57)
            throw invalid_argument("Wrong date format: " + tmp1);
    }
    inarg >> month;
    if (otr == 1)
        month *= -1;
    inarg >> tmp;
    otr = 0;
    if (tmp != '-')
        throw invalid_argument("Wrong date format: " + tmp1);
    if ((inarg.peek() < 48 || inarg.peek() > 57))
    {
        if (inarg.peek() == 45)
        {
            otr = 1;
            inarg.ignore(1);
        }
        if (inarg.peek() == 43)
            inarg.ignore(1);
        if (inarg.peek() < 48 || inarg.peek() > 57)
            throw invalid_argument("Wrong date format: " + tmp1);
    }
    inarg >> day;
    if (otr == 1)
        day *= -1;
    if (inarg.peek() != -1)
        throw invalid_argument("Wrong date format: " + tmp1);
    if (month <= 0 || month > 12)
    {
        err = "Month value is invalid: " + to_string(month);
        throw invalid_argument(err);
    }
    if (day <= 0 || day > 31)
    {
        err = "Day value is invalid: " + to_string(day);
        throw invalid_argument(err);
    }
    date.SetDay(day);
    date.SetMonth(month);
    date.SetYear(year);
}

int main() {
    Database db;
    string commandline;
    while (getline(cin, commandline)) {
        stringstream ss;
        ss << commandline;
        string com;
        ss >> com;
        if (com == "Add")
        {
            Date date;
            string event;
            try
            {
                GetDate(ss, date);
            }
            catch(const exception& e)
            {
                cout << e.what() << '\n';
                return 0;
            }
            ss >> event;
            db.AddEvent(date, event);
        }
        else if (com == "Del")
        {
            Date date;
            string event;
            try
            {
                GetDate(ss, date);
            }
            catch(const exception& e)
            {
                cout << e.what() << '\n';
                return 0;
            }
            ss >> event;
            if (event != "")
            {
                if (db.DeleteEvent(date, event))
                    cout << "Deleted successfully" << endl;
                else
                    cout << "Event not found" << endl;
            }
            else
            {
                int n;
                n = db.DeleteDate(date);
                cout << "Deleted " << n << " events" << endl;
            }
        }
        else if (com == "Find")
        {
            Date date;
            try
            {
                GetDate(ss, date);
            }
            catch(const exception& e)
            {
                cout << e.what() << '\n';
                return 0;
            }
            db.Find(date);
        }
        else if (com == "Print")
        {
            db.Print();
        }
        else if (com == "")
        {}
        else
        {
            cout << "Unknown command: " << com << endl;
            return 0;
        }
    }
    return 0;
}