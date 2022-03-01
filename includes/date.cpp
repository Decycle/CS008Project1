#ifndef DATE_CPP
#define DATE_CPP
#include "date.h"
#include <string>
#include <iostream>


using namespace std;


Date::Date()
{
    //PROC - initialize private variables, no parameter object
    month = 1;
    day = 1;
    year = 2000;

    monthName = name(month);
}

Date::Date(string date){
    //03/05/2013
    int  in_day=0, in_year, temp_mon;
    string in_mon=" ";
    in_mon = date.substr(0,2);

    if(in_mon[0] ==0){
        temp_mon = (int)in_mon[1];
        month = (unsigned int)temp_mon;
    }
    else{
        month = stoi(in_mon);
    }

    day = stoi(date.substr(3,4));
    year = stoi(date.substr(6,9));

    monthName = name(month);
}

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


void Date::printAlpha() const
{
    //PROC - print alphabetical form
    cout << monthName << " " << day << ", " << year;
}


void Date::printNumeric() const
{
    //PROC - print numeric form
    cout << month << "/" << day << "/" << year;
}

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
  cDate.monthName=cDate.name(cDate.month);

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

string Date::print(){
    return to_string(month) +"-"+ to_string(day) +"-"+ to_string(year);
}

#endif // COMPLEX_CPP
