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
			while (yearn > 1899)
			{
				if (m[yearn].count("FN") != 0)
					break;
				yearn--;
			}
			while (yearf > 1899)
			{
				if (m[yearf].count("LN") != 0)
					break;
				yearf--;
			}
			if (yearn == 1899 && yearf == 1899)
				return "Incognito";
			if (yearn == 1899)
				return m[yearf]["LN"] + " with unknown first name";
			else if (yearf == 1899)
				return m[yearn]["FN"] + " with unknown last name";
			else
				return m[yearn]["FN"] + ' ' + m[yearf]["LN"];
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
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}