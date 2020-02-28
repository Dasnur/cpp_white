#include <iostream>
#include <string>
using namespace std;

struct  Specialization
{
    explicit Specialization(const string& s)
    {
        specialization = s;
    }
    string specialization;
};

struct  Course
{
    explicit Course(const string& s)
    {
        course = s;
    }
    string course;
};

struct  Week{
    explicit Week(const string& s)
    {
        week = s;
    }
    string week;
};

struct  LectureTitle {
    LectureTitle(Specialization sp, Course crse, Week wk)
    {
        specialization = sp.specialization;
        course = crse.course;
        week = wk.week;
    }
    string specialization;
    string course;
    string week;
};