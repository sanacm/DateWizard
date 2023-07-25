#include <iostream>
#include <cmath>


using namespace std;

class Date{

private:

    int year{},month{},day{};

    const string monthStrings[12]={
            "January","February","March","April","May","June","July"
            ,"August","September","October","November","December"
    };




    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    static bool isLeapYear(int );

public:

    explicit Date(int d=1, int m=1, int y=1601);
    Date(const Date& oth);
    ~Date();

    void setDate(int d=1, int m=1, int y=1601);
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);



    void increaseDay(int dayIncrease);
    void decreaseDay(int dayDecrease);
    void DayDifference(const Date& othDate) const;
    void displayDate();


};

Date::Date(int d, int m, int y) {
    setDate(d,m,y);

}

Date::~Date() {
    cout<<"Date destroyed"<<endl;

}

Date::Date(const Date& other) {

    day=other.day;
    month=other.month;
    year=other.year;

    cout<<"Date copied to target"<<endl;

}

void Date::setDay(int d){

    if (isLeapYear(year)){

        monthDays[1]=29;

        if (d>=1 && d<=monthDays[month-1]){

            day=d;

        }
        else{
            day=1;
        }


    }

    else{

        if (d>=1 && d<=monthDays[month-1]){

            day=d;

        }
        else{
            day=1;
        }


    }



}


void Date::setMonth(int m) {

    if (m>=1 && m<=12){
        month=m;
    }
    else{
        month=1;
    }


}

void Date::setYear(int y) {

    //year>=1 ? year=y:year=1;

    if (y>=1601){

        year=y;


    }
    else{

        year=1601;

    }


}


void Date::setDate(int d, int m, int y) {

    setMonth(m);
    setDay(d);
    setYear(y);



}

void Date::displayDate() {

    cout<<day<<"/"<<monthStrings[month - 1]<<"/"<<year<<endl;

}

//Upgrade this part

void Date::increaseDay(int dayIncrease) {



    for (int i = 0; i <dayIncrease ; i++) {

        if (day<monthDays[month-1]){
            day+=1;
        }
        else{
            day=1;
            if(month<=12){
                month++;
            }
            else{
                month=1;
                year+=1;

            }


            if (month == 2 && isLeapYear(year)) {
                monthDays[1] = 29;
            } else {
                monthDays[1] = 28;
            }

        }

    }



}

void Date::decreaseDay(int dayDecrease){

    for (int i = 0; i <dayDecrease ; i++) {
        if (day > 1) {
            day--;
        } else {
            if (month > 1) {
                month--;
                day = monthDays[month - 1];
            } else {
                year--;
                month = 12;
                day = monthDays[month - 1];


            }
        }

    }

}

bool Date::isLeapYear(int inputYear) {

    if ( inputYear % 400 == 0){
        return true;
    }
    else if( inputYear% 100 == 0){
        return false;
    }
    else if ( inputYear% 4 == 0) {
        return true;

    }
    else{
        return false;
    }


}

void Date::DayDifference(const Date& othDate) const {

    // Calculate the total number of days for the current date

    int totalDaysCurrent = day;
    for (int i = 0; i < month - 1; i++) {
        totalDaysCurrent += monthDays[i];
    }

    totalDaysCurrent += (year - 1) * 365;
    totalDaysCurrent += (year - 1) / 4;
    totalDaysCurrent -= (year - 1) / 100;
    totalDaysCurrent += (year - 1) / 400;

    // Calculate the total number of days for the other date
    int totalDaysOther = othDate.day;

    for (int i = 0; i < othDate.month - 1; i++) {

        totalDaysOther += othDate.monthDays[i];
    }

    totalDaysOther += (othDate.year - 1) * 365;
    totalDaysOther += (othDate.year - 1) / 4;
    totalDaysOther -= (othDate.year - 1) / 100;
    totalDaysOther += (othDate.year - 1) / 400;

    // Calculate the absolute difference in days
    int difference = abs(totalDaysCurrent - totalDaysOther);

    // Display the result
    cout << "The difference between the two dates is " << difference << " days." << endl;




}










