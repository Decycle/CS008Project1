#ifndef DATE_H
#define DATE_H
#include <string>

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

        unsigned year;      //IN/OUT - the year of the date object

        /******************************
        ** PRIVATE FUNCTIONS  **
        ******************************/
        /******************************************************************
        * bool isLeap(unsigned) const;
        *
        * Accessor; This method will return a boolean response based on
        * if the year(parameter) is a leap year or not.
        *------------------------------------------------------------------
        * Parameter: year (unsigned) // IN/OUT – the year to check if it is
        * a leap year or not
        *------------------------------------------------------------------
        * Return: bool
        ******************************************************************/
        bool isLeap(unsigned) const;

        /******************************************************************
        * unsigned daysPerMonth(unsigned m, unsigned y) const;
        *
        * Accessor; This method will return the number of days in the month
        * (unsigned integer) based on if the year(parameter) is a leap year
        * or not and the month.
        *------------------------------------------------------------------
        * Parameter: m (unsigned) // IN/OUT – the month to check number of
        * days of
        * Parameter: y (unsigned) // IN/OUT – the year to check if it is
        * a leap year or not
        *------------------------------------------------------------------
        * Return: unsigned
        ******************************************************************/
        unsigned daysPerMonth(unsigned m, unsigned y) const;

        /******************************************************************
        * string name (unsigned m) const;
        *
        * Accessor; This method will return the (string) name of the month,
        *  based on the month.
        *------------------------------------------------------------------
        * Parameter: m (unsigned) // IN/OUT – the month (number) to get the
        * string name of.
        *------------------------------------------------------------------
        * Return: string
        ******************************************************************/
        string name (unsigned m) const;

        /******************************************************************
        * unsigned number (const string &mn) const;
        *
        * Accessor; This method will return a number (in months) based on
        * the string name of the month.
        *------------------------------------------------------------------
        * Parameter: mn (unsigned) // IN/OUT – the string name of the month
        * to return the unsigned integer of.
        *------------------------------------------------------------------
        * Return: bool
        ******************************************************************/
        unsigned number (const string &mn) const;
    public:
        /******************************
        ** CONSTRUCTOR  **
        ******************************/
        /****************************************************************
        * Date ();
        * Constructor; Initialize Date attributes for object
        * Parameters: none
        * Return: none
        ***************************************************************/
        Date();

        /******************************
        ** OVERLOAD CONSTRUCTOR  **
        ******************************/
        /****************************************************************
        * Date (const Date &source);
        * Constructor; Initialize Date attributes  with source object
        * Parameters: Date &source
        * Return: none
        ***************************************************************/
        Date(const Date &source);

        /******************************************************************
          * Date& operator=(const Date &source);
          *      Constructor; Called when using the assignment operator to
          *      set one
          *      Date equal to another.
          *----------------------------------------------------------------
          *      Parameters:
         *              source          // Date
          *----------------------------------------------------------------
          *      Return: none
          ****************************************************************/
        Date& operator=(const Date &source);

        /****************************************************************
        * Date(unsigned m, unsigned d, unsigned y);
        * Constructor; Initialize Date attributes for object
        * Parameters:
        *   m (unsigned) //IN/OUT - the month of the date object
        *
        *   d (unsigned) //IN/OUT - the day of the date object
        *   y (unsigned) //IN/OUT - the year of the date object
        * Return: none
        ***************************************************************/
        Date(unsigned m, unsigned d, unsigned y);

        /****************************************************************
        * Date (const string &mn, unsigned d, unsigned y);
        * Constructor; Initialize Date attributes for object
        * Parameters:
        *   mn (const string) //IN/OUT - the month name of the date name
        * object
        *   d (unsigned) //IN/OUT - the day of the date object
        *   y (unsigned) //IN/OUT - the year of the date object
        * Return: none
        ***************************************************************/
        Date(const string &mn, unsigned d, unsigned y);

        /***************
        ** ACCESSORS **
        ***************/
        /****************************************************************
        * void printNumeric() const;
        *
        * Accessor; This method print the date object numerically
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        void printNumeric() const;

        /***************
        ** MUTATOR **
        ***************/
        /****************************************************************
        * string getNumeric();
        * MUTATOR; This method Rreturn the date in string
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: string
        ***************************************************************/
        std::string getNumeric();

        /****************************************************************
        * string getNumeric();
        * MUTATOR; This method Rreturn the date in string
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: string
        ***************************************************************/
        unsigned getYear() const;

        /****************************************************************
        * getMonth() const;
        * MUTATOR; This method Rreturn the month in string
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: string
        ***************************************************************/
        unsigned getMonth() const;

        /****************************************************************
        * string getDay() const;
        * MUTATOR; This method Rreturn the day in string
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: string
        ***************************************************************/
        unsigned getDay() const;

        /****************************************************************
        * string getMonthName() const;
        * MUTATOR; This method Rreturn the month in string
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: string
        ***************************************************************/
        std::string getMonthName() const;


        /****************************************************************
        * void printAlpha() const;
        *
        * Accessor; This method print the date object alphanumerically
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        void printAlpha() const;

        /****************************************************************
        * operator>> (string& string, Date& cDate);
        * Accessor; This method will read the date in string and
        *  convert to Date type
        * --------------------------------------------------------------
        * Parameters: string
        * --------------------------------------------------------------
        * Return: Date
        ***************************************************************/
        friend string& operator>> (string& string, Date& cDate);

        /****************************************************************
        * ostream& operator<< (ostream& osDate,const Date& cDate);
        * Accessor; This method print the date object
        * --------------------------------------------------------------
        * Parameters: Date
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        friend ostream& operator<< (ostream& osDate,
                                    const Date& cDate);

        /****************************************************************
        * bool operator<(const Date&) const;
        * Accessor; This method compares two date object, return true
        *  if input Date < this object
        * --------------------------------------------------------------
        * Parameters: Date
        * --------------------------------------------------------------
        * Return: true / false
        ***************************************************************/
        bool operator<(const Date&) const;

        /****************************************************************
        * bool operator>(const Date&) const;
        * Accessor; This method compares two date object, return true
        *  if input Date > this object
        * --------------------------------------------------------------
        * Parameters: Date
        * --------------------------------------------------------------
        * Return: true / false
        ***************************************************************/
        bool operator>(const Date&) const;

        /****************************************************************
        * bool operator==(const Date&) const;
        * Accessor; This method compares two date object, return true
        *  if input Date == this object
        * --------------------------------------------------------------
        * Parameters: Date
        * --------------------------------------------------------------
        * Return: true / false
        ***************************************************************/
        bool operator==(const Date&) const;

        /****************************************************************
        * bool operator!=(const Date&) const;
        * Accessor; This method compares two date object, return true
        *  if input Date != this object
        * --------------------------------------------------------------
        * Parameters: Date
        * --------------------------------------------------------------
        * Return: true / false
        ***************************************************************/
        bool operator!=(const Date&) const;


        /***************
        ** ACCESSORS **
        ***************/
        /****************************************************************
        * void setDay(unsigned d);
        * Accessor; This method set the day with input unsigned day
        * --------------------------------------------------------------
        * Parameters: unsigned day
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        void setDay(unsigned d);

        /****************************************************************
        * void setMonth(unsigned m);
        * Accessor; This method set the month with input unsigned day
        * --------------------------------------------------------------
        * Parameters: unsigned day
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        void setMonth(unsigned m);

        /****************************************************************
        * void setYear(unsigned y);
        * Accessor; This method set the year with input unsigned day
        * --------------------------------------------------------------
        * Parameters: unsigned year
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        void setYear(unsigned y);



};

#endif // DATE_H
