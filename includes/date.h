#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
/****************************************************************
* Date Class
*   This class represents a Date object. It manages 4 attributes,
*   the month, the string name of the month,  and the denominator
* of the rational number.
***************************************************************/

using namespace std;

class Date
{
    private:
        unsigned day;       //IN/OUT - the day of the date object

        unsigned month;     //IN/OUT - the month of the date object

        string monthName;   //IN/OUT - the month name of the date name
                            //object

        unsigned year;      //IN/OUT - the year of the date object

        bool isLeap(unsigned) const;
        unsigned daysPerMonth(unsigned m, unsigned y) const;
        string name (unsigned m) const;
        unsigned number (const string &mn) const;


    public:

        Date();
        Date(string date);
        Date(unsigned m, unsigned d, unsigned y);
        Date(const string &mn, unsigned d, unsigned y);
        void printNumeric() const;
        void printAlpha() const;
        string print();

        friend string& operator>> (string& string, Date& cDate);
        friend ostream& operator<< (ostream& osDate,
                                    const Date& cDate);
        bool operator<(const Date&) const;
        bool operator>(const Date&) const;
        bool operator==(const Date&) const;
};

#endif // DATE_H
