
#include "student.h"

// *******************************************************************
// * Function Name: Student Default Constructor                      *
// * Description: Creates new Student with defaults                  *
// * Parameter Description: None                                     *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
Student::Student()
{
    first_name = "";
    last_name = "";
    mi = ' ';
    student_id = DEFAULTSTUDENTID;
    gpa = MINIMUMGPA;
    major = DEFAULTMAJOR;
    date_of_birth = DEFAULTDOB;
    home_phone = DEFAULTHOMEPHONE;
}

// *******************************************************************
// * Function Name: Student (Parameterized Constructor)              *
// * Description: Creates student with given values                  *
// * Parameter Description:                                          *
// *    fn - first name string                                       *
// *    ln - last name string                                        *
// *    mi - middle initial char                                     *
// *    id - student id string (9 digits)                            *
// *    g - gpa float                                                *
// *    ma - major string                                            *
// *    m,d,y -  month, day, year integers                           *
// *    hp - home phone string (10 digits)                           *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
Student::Student(string fn, string ln, char mi, string id, float g,
                string ma, int m, int d, int y, string hp)
{
    Setfirst_name(fn);
    Setlast_name(ln);
    Setmi(mi);
    Setstudent_id(id);
    Setgpa(g);
    Setmajor(ma);
    Setdate_of_birth(m,d,y);
    Sethome_phone(hp);
}

// *******************************************************************
// * Function Name: Setlast_name                                     *
// * Description: Sets student's last name                           *
// * Parameter Description: ln   last name string to set             *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
void Student::Setlast_name(const string ln) {
    last_name = ln;
}

// *******************************************************************
// * Function Name: Setfirst_name                                    *
// * Description: Sets student's first name                          *
// * Parameter Description: fn   first name string to set            *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
void Student::Setfirst_name(const string fn) {
    first_name = fn;
}

// *******************************************************************
// * Function Name: Setmi                                            *
// * Description: Sets student's middle initial if valid             *
// * Parameter Description: m   char for middle initial              *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
void Student::Setmi(const char m) {
    if(isalpha(m))
        mi = m;
    else
        mi = ' ';
}

// ******************************************************************
// * Function Name: Setstudent_id                                   *
// * Description: Sets student ID if exactly 9 digits               *
// * Parameter Description: si   student ID string                  *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
void Student::Setstudent_id(const string si) {
    if(si.length() == 9)
        student_id = si;
    else
        student_id = DEFAULTSTUDENTID;
}

// ******************************************************************
// * Function Name: Setgpa                                          *
// * Description: Sets GPA if between 0.0 and 4.0                   *
// * Parameter Description: g float GPA value                       *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
void Student::Setgpa(const float g) {
    if(g >= MINIMUMGPA && g <= MAXIMUMGPA)
        gpa = g;
    else
        gpa = MINIMUMGPA;
}

// ******************************************************************
// * Function Name: Setmajor                                        *
// * Description: Sets major if valid                               *
// * Parameter Description: m string major code                     *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
void Student::Setmajor(const string m) {
    if(Valid_Major(m))
        major = m;
    else
        major = DEFAULTMAJOR;
}

// *******************************************************************
// * Function Name: Setdate_of_birth                                 *
// * Description: Sets DOB if valid date                             *
// * Parameter Description:                                          *
// *    m   integer month (1-12)                                     *
// *    d   integer day (depends on month)                           *
// *    y   integer year (>1900)                                     *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// ******************************************************************
void Student::Setdate_of_birth(const int m, const int d, const int y) {
    if(Valid_Date(m, d, y)) {
        date_of_birth.month = m;
        date_of_birth.day = d;
        date_of_birth.year = y;
    }
    else {
        date_of_birth = DEFAULTDOB;
    }
}

// *******************************************************************
// * Function Name: Sethome_phone                                    *
// * Description: Sets phone if exactly 10 digits                    *
// * Parameter Description: h string phone number                    *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
void Student::Sethome_phone(const string h) {
    if(Valid_Phone(h))
        home_phone = h;
    else
        home_phone = DEFAULTHOMEPHONE;
}

// ******************************************************************
// * Function Name: Getlast_name                                    *
// * Description: Returns student's last name                       *
// * Parameter Description: None                                    *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
string Student::Getlast_name() {
    return last_name;
}

// *******************************************************************
// * Function Name: Getfirst_name                                    *
// * Description: Returns student's first name                       *
// * Parameter Description: None                                     *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
string Student::Getfirst_name() {
    return first_name;
}

// ******************************************************************
// * Function Name: Getmi                                           *
// * Description: Returns student's middle initial                  *
// * Parameter Description: None                                    *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
char Student::Getmi() {
    return mi;
}

// ******************************************************************
// * Function Name: Getstudent_id                                   *
// * Description: Returns student's ID                              *
// * Parameter Description: None                                    *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
string Student::Getstudent_id() {
    return student_id;
}

// ******************************************************************
// * Function Name: Getgpa                                          *
// * Description: Returns student's GPA                             *
// * Parameter Description: None                                    *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
float Student::Getgpa() {
    return gpa;
}

// *******************************************************************
// * Function Name: Getmajor                                         *
// * Description: Returns student's major                            *
// * Parameter Description: None                                     *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// ******************************************************************
string Student::Getmajor() {
    return major;
}

// ******************************************************************
// * Function Name: Getdate_of_birth                                *
// * Description: Returns formatted date string (mm/dd/yyyy)        *
// * Parameter Description: None                                    *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
string Student::Getdate_of_birth() {
    return to_string(date_of_birth.month) + "/" +
           to_string(date_of_birth.day) + "/" +
           to_string(date_of_birth.year);
}

// ******************************************************************
// * Function Name: Gethome_phone                                   *
// * Description: Returns formatted phone (999) 999-9999            *
// * Parameter Description: None                                    *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
string Student::Gethome_phone() {
    return "(" + home_phone.substr(0,3) + ") " +
           home_phone.substr(3,3) + "-" +
           home_phone.substr(6);
}

// *******************************************************************
// * Function Name: PrintStudent                                     *
// * Description: Prints all student info in required format         *
// * Parameter Description: None                                     *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
void Student::PrintStudent() {
    cout << "\nStudent Object Print" << endl;
    cout << Getfirst_name() << " " << Getmi() << ". " << Getlast_name() << endl;
    cout << "Major: " << Getmajor() << "  GPA: " << fixed << setprecision(2)
         << Getgpa() << " Date of Birth: " << Getdate_of_birth() << endl;
    cout << "Home Phone is: " << Gethome_phone() << endl;
}

// ******************************************************************
// * Function Name: Valid_Date                                      *
// * Description: Validates date including leap years               *
// * Parameter Description:                                         *
// *    m   month to validate (1-12)                                *
// *    d   day to validate                                         *
// *    y   year to validate (>1900)                                *
// * Date: 1/31/25                                                  *
// * Author: Adrianna Dooley                                        *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25*
// ******************************************************************
bool Student::Valid_Date(const int m, const int d, const int y) {
    if(y < 1900) return false;
    if(m < 1 || m > 12) return false;
    if(d < 1) return false;

    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(y % 4 == 0) {
        if(y % 100 == 0) {
            if(y % 400 == 0)
                days[1] = 29;
        }
        else
            days[1] = 29;
    }

    return d <= days[m-1];
}

// *******************************************************************
// * Function Name: Valid_Phone                                      *
// * Description: Validates 10-digit phone number                    *
// * Parameter Description: p string phone number to check           *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
bool Student::Valid_Phone(const string p) {
    if(p.length() != 10) return false;
    if(p[0] == '0') return false;

    for(int i = 0; i < p.length(); i++) {
        if(!isdigit(p[i]))
            return false;
    }
    return true;
}

// *******************************************************************
// * Function Name: Valid_Major                                      *
// * Description: Checks if major code is valid                      *
// * Parameter Description: m string major code to validate          *
// * Date: 1/31/25                                                   *
// * Author: Adrianna Dooley                                         *
// * References: Referenced from Dr.Gaitros Class Lecture on 1/29/25 *
// *******************************************************************
bool Student::Valid_Major(const string m) {
    return (m == "CompSci" || m == "Math" || m == "EE" ||
            m == "Bio" || m == "Chem");
}