#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class	Person
{
	public:
		void ChangeFirstName(int year, const string& first_name)
		{
			m[year]["FN"] = first_name;
		}
		void ChangeLastName(int year, const string& last_name)
		{
			m[year]["LN"] = last_name;
		}
		string GetFullName(int year)
		{
			int yearn = year;
			int yearf = year;
			while (yearn > 0)
			{
				if (m[yearn].count("FN") != 0)
					break;
				yearn--;
			}
			while (yearf > 0)
			{
				if (m[yearf].count("LN") != 0)
					break;
				yearf--;
			}
			if (yearn == 0 && yearf == 0)
				return "Incognito";
			if (yearn == 0)
				return m[yearf]["LN"] + " with unknown first name";
			else if (yearf == 0)
				return m[yearn]["FN"] + " with unknown last name";
			else
				return m[yearn]["FN"] + ' ' + m[yearf]["LN"];
		}
		string GetFullNameWithHistory(int year)
		{
			int yearn = year;
			int yearf = year;
			vector<string> fname;
			vector<string> sname;
			string prev_name;
			string res1;
			int flag = 0;
			while (yearn > 0)
			{
				if (m[yearn].count("FN") != 0)
				{
					if (m[yearn]["FN"] != prev_name)
					{
						prev_name = m[yearn]["FN"];
						fname.push_back(m[yearn]["FN"]);
					}
				}
				yearn--;
			}
			while (yearf > 0)
			{
				if (m[yearf].count("LN") != 0)
				{
					if (m[yearf]["LN"] != prev_name)
					{
						prev_name = m[yearf]["LN"];
						sname.push_back(m[yearf]["LN"]);
					}
				}
				yearf--;
			}
			for (auto item : fname)
			{
				if (flag == 0)
				{
					res1 = res1 + item;
					flag = 1;
				}
				else if (flag == 1)
				{
					res1 = res1 + " (" + item;
					flag = 2;
				}
				else
				{
					res1 = res1 + " " + item;
				}
			}
			if (flag == 2)
				res1 += ") ";
			if (flag == 1)
				res1 += " ";
			flag = 0;
			for (auto item : sname)
			{
				if (flag == 0)
				{
					res1 = res1 + item;
					flag = 1;
				}
				else if (flag == 1)
				{
					res1 = res1 + " (" + item;
					flag = 2;
				}
				else
					res1 = res1 + " " + item;
			}
			if (flag == 2)
				res1 += ")";
			if (res1 == "")
				return "Incognito";
			return res1;
		}
	private:
		map <int, map<string, string>> m;
};

int main()
{

  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
  return 0;
}