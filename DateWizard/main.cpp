#include <iostream>
#include "Date.h"

using  namespace std ;

int main() {

    int day, month, year;

    cout<< "Enter the first date (day month year): ";
    cin >> day >> month >> year;

    Date mainDate1(day, month, year);

    cout << "Enter the second date (day month year): ";
    cin >> day >> month >> year;
    Date mainDate2(day, month, year);

    cout << "*****************" <<endl;
    cout << "First date: "<<endl;
    mainDate1.displayDate();
    cout << "Second date: "<<endl;
    mainDate2.displayDate();

    cout << "*****************" <<endl;

    mainDate1.DayDifference(mainDate2);


    int dayIncrease,dayDecrease;

    cout << "*****************\nIncreasing the first date\nHow many day would you like the increase day? ";
    cin >> dayIncrease;

    cout << "Increasing the first date by" << dayIncrease << endl<<"New date is:"<<endl;
    mainDate1.increaseDay(dayIncrease);
    mainDate1.displayDate();


    cout << "*****************\nDecreasing the second date\nHow many day would you like the decrease day? " <<endl;
    cin>>dayDecrease;
    cout << "Decreasing the second date by "<<dayDecrease<<endl<<"New date is:"<<endl;
    mainDate2.decreaseDay(dayDecrease);
    mainDate2.displayDate();



    return 0;
}



