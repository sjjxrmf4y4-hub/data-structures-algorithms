#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
struct date_struct
{
    int month;
    int day;
    int year;
};
const string DEFAULTSTUDENTID="000000000";
const date_struct DEFAULTDOB={1,1,1900};
const string DEFAULTHOMEPHONE="5555555555";
const string DEFAULTMAJOR="Math";
const int MINIMUMGPA=0;
const int MAXIMUMGPA=4.0;
class Student {
public:
    Student(string fn, string ln, char mi, string id, float g, string ma, int m,
    int d, int y, string hp);
    Student();
    void Setlast_name(const string ln);
    void Setfirst_name(const string fn);
    void Setmi(const char m);
    void Setstudent_id(const string si);
    void Setgpa(const float g);
    void Setmajor(const string m);
    void Setdate_of_birth(const int m, const int d, const int y);
    void Sethome_phone(const string h);
    string Getlast_name();
    string Getfirst_name();
    char Getmi();
    string Getstudent_id();
    float Getgpa();
    string Getmajor();
    string Getdate_of_birth();
    string Gethome_phone();
    void PrintStudent();


private:
    bool Valid_Date(const int m, const int d, const int y);
    bool Valid_Phone(const string p);
    bool Valid_Major(const string m);
    string last_name;
    string first_name;
    char mi;
    string student_id;
    float gpa;
    string major;
    date_struct date_of_birth;
    string home_phone;
};
#endif