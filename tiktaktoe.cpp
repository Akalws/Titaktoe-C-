/********************************************************************
* Author:
*    Daniel Akalws
* Summary:
*   This program gets a year and month from the user and displays a
*   calender.
*     The hardest part of writing this function was calculating the
*     offset and knowing how to display the days and start a new line at
*     the end of the week.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * getMonth
 * Prompts user for month number
 ***********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;
   while (!(month >= 1 && month <= 12))
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> month;
   }
   return month;
   
}

/**********************************************************************
 * getYear
 * Prompts user for year
 ***********************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;
   while (!(year >= 1753))
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> year;
      
   }
   
   return year;
}

/**********************************************************************
 * isYearLeap
 * checks if year is leap
 ***********************************************************************/
bool isYearLeap(int year)
{
   if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
      return true;
   else
      return false;
   
}

/**********************************************************************
 * getNumDaysInYear
 * calculates number of days in year
 ***********************************************************************/
int getNumDaysInYear(int year)
{

   return 365 + isYearLeap(year);
}

/**********************************************************************
 * getNumDaysInMonth
 * calculates number of days in month
 ***********************************************************************/
int getNumDaysInMonth(int month, int year)
{
   int daysInMonth = 0;
   if (month == 1 || month == 3 || month == 5 || month == 7
       || month == 8 || month == 10 || month == 12)
      daysInMonth = 31;
   if (month == 4 || month == 6 || month == 9 || month == 11)
      daysInMonth = 30;
   if (month == 2)
   {
      if (isYearLeap(year))
         daysInMonth = 29;
      else
         daysInMonth = 28;
   }
   
   return daysInMonth;
}

/**********************************************************************
 * computeOffset
 * calculates offset
 ***********************************************************************/
int computeOffset(int month, int year)
{
   int offset = 0;
   for (int i = 1753; i < year; i++)
   {
      offset += getNumDaysInYear(i);
   }
   for (int i = 1; i < month; i++)
   {
      offset += getNumDaysInMonth(i, year);
   }
   
   return offset % 7;
   
}

/**********************************************************************
 * displayTable
 * displays month
 ***********************************************************************/
void displayTable(int daysInMonth, int offset)
{
   
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   if (offset != 6)
   {
      for (int i = 0; i <= offset; i++)
      {
         cout << "    ";
      }
   }
      for (int i = 1; i <= daysInMonth; i++)
   {
      cout << setw(4) << i;
      if ( (i + offset + 1) % 7 == 0 && i != daysInMonth)
         cout << endl;
   }
   cout << endl;
   
}

/**********************************************************************
 * displayHeader
 * displays month header
 ***********************************************************************/
void displayHeader(int month, int year)
{
   cout << endl;
   
   if (month == 1)
      cout << "January, " << year << endl;
   if (month == 2)
      cout << "February, " << year << endl;
   if (month == 3)
      cout << "March, " << year << endl;
   if (month == 4)
      cout << "April, " << year << endl;
   if (month == 5)
      cout << "May, " << year << endl;
   if (month == 6)
      cout << "June, " << year << endl;
   if (month == 7)
      cout << "July, " << year << endl;
   if (month == 8)
      cout << "August, " << year << endl;
   if (month == 9)
      cout << "September, " << year << endl;
   if (month == 10)
      cout << "October, " << year << endl;
   if (month == 11)
      cout << "November, " << year << endl;
   if (month == 12)
      cout << "December, " << year << endl;
   
}

/**********************************************************************
 * display
 * calls other display functions
 ***********************************************************************/
void display(int year, int month, int offset)
{
   int daysInMonth = getNumDaysInMonth(month, year);
   displayHeader(month, year);
   displayTable(daysInMonth, offset);
   return;
}

/**********************************************************************
 * Main
 * calls other fuctions and passes data between functions.
 ***********************************************************************/
int main()
{

   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(month, year);
   int numDaysInYear = getNumDaysInYear(year);
   display(year, month, offset);
   
   
   
   return 0;
}
