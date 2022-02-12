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

        string monthName;   //IN/OUT - the month name of the date name
                            //object

        unsigned year;      //IN/OUT - the year of the date object

        /******************************
        ** PRIVATE FUNCTIONS  **
        ******************************/
        /******************************************************************
        * bool isLeap(unsigned) const;
        *
        * Mutator; This method will return a boolean response based on
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
        * void printAlpha() const;
        *
        * Accessor; This method print the date object alphanumerically
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        friend string& operator>> (string& string, Date& cDate);
        /****************************************************************
        * void printAlpha() const;
        *
        * Accessor; This method print the date object alphanumerically
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        friend ostream& operator<< (ostream& osDate,
                                    const Date& cDate);
        /****************************************************************
        * void printAlpha() const;
        *
        * Accessor; This method print the date object alphanumerically
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        bool operator<(const Date&) const;
        /****************************************************************
        * void printAlpha() const;
        *
        * Accessor; This method print the date object alphanumerically
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        bool operator>(const Date&) const;
        /****************************************************************
        * void printAlpha() const;
        *
        * Accessor; This method print the date object alphanumerically
        * --------------------------------------------------------------
        * Parameters: none
        * --------------------------------------------------------------
        * Return: none
        ***************************************************************/
        bool operator==(const Date&) const;

        /*
        else if (ui->Date_radioButton_4->isChecked())
            {
                string date = input.toStdString();
                int dayTemp;                           // Day
                int monthTemp;                         // Month
                int yearTemp;                          // Year
                string monthNameTemp;                           // Month name
                bool slashFound = false;
                bool spaceFound = false;

                for (unsigned long i = 0; i < date.size(); i++)
                {
                    if (date.at(i) == '/')
                    {
                        slashFound = true;
                    }
                    else if (date.at(i) == ' ')
                    {
                        spaceFound = true;
                    }
                }

                if (slashFound == true)
                {
                    monthTemp = stoi(date.substr(0, date.find("/")));
                    dayTemp = stoi(date.substr(date.find("/") + 1, date.find_last_of('/')));
                    yearTemp = stoi(date.substr(date.find_last_of("/") + 1, date.size()));
                    Date tempDate (monthTemp, dayTemp, yearTemp);
                    listDate.push_back(tempDate);
                }
                else if (spaceFound == true)
                {
                    monthTemp = stoi(date.substr(0, date.find(' ')));
                    dayTemp = stoi(date.substr(date.find(' ') + 1, date.find_last_of(' ')));
                    yearTemp = stoi(date.substr(date.find_last_of(' ') + 1, date.size()));
                    Date tempDate (monthNameTemp, dayTemp, yearTemp);
                    listDate.push_back(tempDate);
                }
                else
                {
                    Date tempDate;
                    listDate.push_back(tempDate);
                }
                display(1,1);
        */


};

#endif // DATE_H
