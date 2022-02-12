#ifndef DATE_CPP
#define DATE_CPP
#include "date.h"
#include <string>
#include <iostream>
/****************************************************************
* Date Class
*   This class represents a Date object. It manages 4 attributes,
*   the month, the string name of the month,  and the denominator
* of the Date number.
***************************************************************/

using namespace std;
/**********************************************************
*
* Method Date: Class Date
*_________________________________________________________
* This method constructs the date object
*_________________________________________________________
* PRE-CONDITIONS
* none
* POST-CONDITIONS
* The function creates an object. No return value.
***********************************************************/

Date::Date()
{
    //PROC - initialize private variables, no parameter object
    month = 1;
    day = 1;
    year = 2000;

    monthName = name(month);
}
/**********************************************************
*
* Method Date: Class Date
*_________________________________________________________
* This method constructs the date object based on the parameters
* of number month, day, and year. A string month name the object is
* created based on the month (unsigned int) parameter. The
* month, day, and year are used to validity check for
* correct days of month based on whether it is a leap year.
*_________________________________________________________
* PRE-CONDITIONS
* m (unsigned) //IN/OUT - the month of the date object
* d (unsigned) //IN/OUT - the day of the date object
* y (unsigned) //IN/OUT - the year of the date object
* POST-CONDITIONS
* The function creates an object. No return value.
***********************************************************/

Date::Date(unsigned m, unsigned d, unsigned y)
{
    int invalid;    //PROC - invalid status for invalid output
    month = m;      //IN/OUT - string month name for date output
    day = d;        //IN/OUT - day for date output
    year = y;       //IN/OUT - year for date output

    //PROC - initialize to valid
    invalid = 0;

    //PROC - if number of months is more than existing 12
    if (month > 12)
    {
        month = 12;
        invalid = 1;
    }
    //PROC - if month is less than 1
    if (month < 1)
    {
        month = 1;
        invalid = 1;
    }

    //PROC - name of month
    monthName = name(month);

    //PROC - if day greater than max day of month, leap year respective
    if (day > daysPerMonth(month,year))
    {
        day = daysPerMonth(month,year);
        invalid = 1;
    }
    //PROC - if day is less than 1
    if (day < 1)
    {
        day = 1;
        invalid = 1;
    }
    //PROC - if the date itself was invalid, before correction
    if (invalid == 1)
        cout << "Invalid date values: Date corrected to " << month << "/"
         << day << "/" << year << ".\n";
}

/**********************************************************
*
* Method Date: Class Date
*_________________________________________________________
* This method constructs the date object based on the
* parameters of string month, number day, number and year.
* A month (unsigned int) for the object is created based
* on the string month name parameter. The month, day, and
* year are used to validity check for correct days of
* month based on whether it is a leap year. The string
* month name is also validity checked whether it is an
* actual month, defaulting to 1/1/2000 if not.
*_________________________________________________________
* PRE-CONDITIONS
* mn (const string) //IN/OUT - the month string of the date object
* d (unsigned) //IN/OUT - the day of the date object
* y (unsigned) //IN/OUT - the year of the date object
* POST-CONDITIONS
* The function creates an object. No return value.
***********************************************************/
Date::Date(const string &mn, unsigned d, unsigned y)
{
    int invalid;    //PROC - invalid status for invalid output
    monthName = mn; //IN/OUT - string month name for date output
    day = d;        //IN/OUT - day for date output
    year = y;       //IN/OUT - year for date output

    //PROC - initialize to valid
    invalid = 0;
    //PROC - returns month number, 0 if string couldn't be read
    month = number(monthName);
    //PROC - if month string could not be read
    if (month == 0) //month check
    {
        month = 1;
        day = 1;
        year = 2000;
        monthName = name(month);
        invalid = 2;
    }
    //PROC - if number of months is more than existing 12
    if (month > 12)
    {
        month = 12;
        invalid = 1;
    }
    //PROC - if month is less than 1
    if (month < 1)
    {
        month = 1;
        invalid = 1;
    }

    //PROC - if day greater than max day of month, leap year respective
    if (day > daysPerMonth(month,year)) //day check
    {
        day = daysPerMonth(month,year);
        invalid = 1;
    }
    //PROC - if day is less than 1
    if (day < 1)
    {
        day = 1;
        invalid = 1;
    }
    //PROC - if the date itself was invalid, before correction
    if (invalid == 2)
        cout << "Invalid month name: the Date was set to " << month << "/"
             << day << "/" << year << ".\n";
    //PROC - if the month string was invalid, before correction
    if (invalid == 1)
        cout << "Invalid date values: Date corrected to " << month << "/"
         << day << "/" << year << ".\n";
}
/**********************************************************
*
* Method printAlpha: Class Date
*_________________________________________________________
* This private method prints the Date object on screen in
* alphanumeric form
*_________________________________________________________
* PRE-CONDITIONS
* the month(string), day(unsigned) and year (unsigned) for output.
* POST-CONDITIONS
* The function couts/prints out the date in alphanumeric
* form. No return value.
***********************************************************/

void Date::printAlpha() const
{
    //PROC - print alphabetical form
    cout << monthName << " " << day << ", " << year;
}

/**********************************************************
*
* Method printNumeric: Class Date
*_________________________________________________________
* This private method prints the Date object on screen in
* numeric form
*_________________________________________________________
* PRE-CONDITIONS
* the month(string), day (unsigned) and year (unsigned) for output.
* POST-CONDITIONS
* The function couts/prints out the date in Numeric
* form. No return value.
***********************************************************/
void Date::printNumeric() const
{
    //PROC - print numeric form
    cout << month << "/" << day << "/" << year;
}

/**********************************************************
*
* Method isLeap: Class Date
*_________________________________________________________
* This private method returns true/false for whether the year
* is the leap year
*_________________________________________________________
* PRE-CONDITIONS
* y (unsigned int) //IN/OUT - the month unsigned int of the
* date object
* POST-CONDITIONS
* The function returns true/false for whether the year
* is the leap year. A boolean is returned.
***********************************************************/
bool Date::isLeap(unsigned y) const
//PROC - will determine if leap year
{
    //PROC - implies leap year
    if (y % 4 == 0)
    {
        //PROC - implies NOT leap year
        if (y % 100 == 0)
        {
            //PROC - implies leap year
            if (y % 400 == 0)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

/**********************************************************
*
* Method daysPerMonth: Class Date
*_________________________________________________________
* This private method returns the days of the month. This
* is based on the month and year( for leap year). returns
* unsigned int.
*_________________________________________________________
* PRE-CONDITIONS
* m (unsigned int) //IN/OUT - the month unsigned int of the
* date object
* y (unsigned int) //IN/OUT - the month unsigned int of the
* date object
* whether it is a leap year or not
* whether the month is on February
* POST-CONDITIONS
* The function returns the number of days in the month based
* on month, year and whether the year is a leap year. returns
* unsigned int
***********************************************************/
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    //PROC - return days of month based leap year, year, and month
    if (m == 1)
        return 31;
    //PROC - accounts for year yer in month of january
    if (m == 2 && isLeap(y))
    {
        return 29;
    }
        else if (m == 2)
    {
        return 28;
    }

    if (m == 3)
        return 31;
    if (m == 4)
        return 30;
    if (m == 5)
        return 31;
    if (m == 6)
        return 30;
    if (m == 7)
        return 31;
    if (m == 8)
        return 31;
    if (m == 9)
        return 30;
    if (m == 10)
        return 31;
    if (m == 11)
        return 30;
    if (m == 12)
        return 31;
    //PROC - error
    return 0;
}
/**********************************************************
*
* Method name: Class Date
*_________________________________________________________
* This private method returns the month string based on the
*  month number given in parameter. Used for date constructor
* month number is given instead of the string. returns string.
*_________________________________________________________
* PRE-CONDITIONS
* m (unsigned int) //IN/OUT - the month unsigned int of the
* date object
* POST-CONDITIONS
* The function returns a month string for the constructor.
* Returns "error" when the string is invalid(month number is
* invalid). Returns string.
***********************************************************/

string Date::name (unsigned m) const
{
    //PROC - return month string based on number
    if (m == 1)
        return "January";
    if (m == 2)
        return "February";
    if (m == 3)
        return "March";
    if (m == 4)
        return "April";
    if (m == 5)
        return "May";
    if (m == 6)
        return "June";
    if (m == 7)
        return "July";
    if (m == 8)
        return "August";
    if (m == 9)
        return "Spetember";
    if (m == 10)
        return "October";
    if (m == 11)
        return "November";
    if (m == 12)
        return "December";
    //PROC - invalid month number
    return "error";
}
/**********************************************************
*
* Method number: Class Date
*_________________________________________________________
* This private method returns the month number based on the
* string month name given in parameter. Used for date constructor
* when month string is given instead of the number. returns an
* unsigned int.
*_________________________________________________________
* PRE-CONDITIONS
* mn (const string) //IN/OUT - the month string of the date object
* POST-CONDITIONS
* The function returns an unsigned int for the constructor.
* Returns 0 when the string is invalid(cannot be read
* as a month). Returns unsigned int.
***********************************************************/
unsigned Date::number (const string &mn) const
{
    //PROC - return month number based on string
    if (mn == "January")
        return 1;
    if (mn == "February")
        return 2;
    if (mn == "March")
        return 3;
    if (mn == "April")
        return 4;
    if (mn == "May")
        return 5;
    if (mn == "June")
        return 6;
    if (mn == "July")
        return 7;
    if (mn == "August")
        return 8;
    if (mn == "September")
        return 9;
    if (mn == "October")
        return 10;
    if (mn == "November")
        return 11;
    if (mn == "December")
        return 12;
    //PROC - // invalid month string
    return 0;
}

string& operator>> (string& input,
                            Date& cDate)
{

//  string date = "";
//  isDate >> date;

  int dayTemp;                           // Day
  int monthTemp;                         // Month
  int yearTemp;                          // Year
  string monthNameTemp;                           // Month name
  bool slashFound = false;
  bool spaceFound = false;

  for (unsigned long i = 0; i < input.size(); i++)
  {
      if (input.at(i) == '/')
      {
          slashFound = true;
      }
      else if (input.at(i) == ' ')
      {
          spaceFound = true;
      }
  }

  if (slashFound == true)
  {
      monthTemp = stoi(input.substr(0, input.find("/")));
      dayTemp = stoi(input.substr(input.find("/") + 1, input.find_last_of('/')));
      yearTemp = stoi(input.substr(input.find_last_of("/") + 1, input.size()));
      Date tempDate (monthTemp, dayTemp, yearTemp);
  }
  else if (spaceFound == true)
  {
      monthTemp = stoi(input.substr(0, input.find(' ')));
      dayTemp = stoi(input.substr(input.find(' ') + 1, input.find_last_of(' ')));
      yearTemp = stoi(input.substr(input.find_last_of(' ') + 1, input.size()));
      Date tempDate (monthNameTemp, dayTemp, yearTemp);
  }
//  else
//  {
//      Date tempDate;
//      //listDate.push_back(tempDate);
//  }
  cDate.month = monthTemp;
  cDate.day = dayTemp;
  cDate.year = yearTemp;

  return input;

}
ostream& operator<< (ostream& osDate,
                            const Date& cDate)
{
    osDate << cDate.month;
    osDate << "/";
    osDate << cDate.day;
    osDate << "/";
    osDate << cDate.year;
    return osDate;
}
bool Date::operator<(const Date& rhs) const
{

    if (year<rhs.year)
    {
        return true;
    }else if (year>rhs.year)
    {
        return false;
    }
    //if same year
    if (month<rhs.month)
    {
        return true;
    }else if (month>rhs.month)
    {
        return false;
    }
    //if same month and year
    if (day<rhs.day)
    {
        return true;
    }else if (day>rhs.day)
    {
        return false;
    }
    return false;
}
bool Date::operator>(const Date& rhs) const
{

    if (year>rhs.year)
    {
        return true;
    }else if (year<rhs.year)
    {
        return false;
    }
    //if same year
    if (month>rhs.month)
    {
        return true;
    }else if (month<rhs.month)
    {
        return false;
    }
    //if same month and year
    if (day>rhs.day)
    {
        return true;
    }else if (day<rhs.day)
    {
        return false;
    }
    return false;
}
bool Date::operator==(const Date& rhs) const
{
    if (year == rhs.year && month == rhs.month && day == rhs.day)
        return true;
    return false;
}
#endif // COMPLEX_CPP
