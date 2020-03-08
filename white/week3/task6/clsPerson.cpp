#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class	Person
{
	public:
        Person(const string& f_name, const string & s_name, int year)
        {
            m[year]["FN"] = f_name;
            m[year]["LN"] = s_name;
            year_of_birth = year;
        }
		void ChangeFirstName(int year, const string& first_name)
		{
            if (year < year_of_birth)
                return ;
			m[year]["FN"] = first_name;
		}
		void ChangeLastName(int year, const string& last_name)
		{
            if (year < year_of_birth)
                return ;
			m[year]["LN"] = last_name;
		}
		string GetFullName(int year) const
		{
            map <int, map<string, string>> mm = m;
            if (year < year_of_birth)
                return "No person";
			int yearn = year;
			int yearf = year;
			while (yearn > 0)
			{
				if (mm[yearn].count("FN") != 0)
					break;
				yearn--;
			}
			while (yearf > 0)
			{
				if (mm[yearf].count("LN") != 0)
					break;
				yearf--;
			}
			if (yearn == 0 && yearf == 0)
				return "Incognito";
			if (yearn == 0)
				return mm[yearf]["LN"] + " with unknown first name";
			else if (yearf == 0)
				return mm[yearn]["FN"] + " with unknown last name";
			else
				return mm[yearn]["FN"] + ' ' + mm[yearf]["LN"];
		}
		string GetFullNameWithHistory(int year) const
		{
            map <int, map<string, string>> mm = m;
            if (year < year_of_birth)
                return "No person";
			int yearn = year;
			int yearf = year;
			vector<string> fname;
			vector<string> sname;
			string prev_name;
			string res1;
			int flag = 0;
			while (yearn > 0)
			{
				if (mm[yearn].count("FN") != 0)
				{
					if (mm[yearn]["FN"] != prev_name)
					{
						prev_name = mm[yearn]["FN"];
						fname.push_back(mm[yearn]["FN"]);
					}
				}
				yearn--;
			}
			while (yearf > 0)
			{
				if (mm[yearf].count("LN") != 0)
				{
					if (mm[yearf]["LN"] != prev_name)
					{
						prev_name = mm[yearf]["LN"];
						sname.push_back(mm[yearf]["LN"]);
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
					res1 = res1 + ", " + item;
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
					res1 = res1 + ", " + item;
			}
			if (flag == 2)
				res1 += ")";
			if (res1 == "")
				return "Incognito";
			if (sname.size() == 0)
				res1 += "with unknown last name";
			if (fname.size() == 0)
				res1 += " with unknown first name";
			return res1;
		}
	private:
		map <int, map<string, string>> m;
        int year_of_birth;
};