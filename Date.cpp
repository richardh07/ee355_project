
#include "Date.h"

Date::Date(){
    // Already done! 
    // cout << "Default constructor called! " << endl;
    day = 1;
    month = 1;
    year = 1970;
}


Date::Date(int day, int month, int year){
    // Already done! 
    // cout << "Constructor with integer arguments is called!" << endl;
    set_date(day, month, year);
}


Date::Date(string str){
    // Already done! 
    // input format is M/D/YYYY
    // cout << "Constructor wtih string argument is called" << endl;
    set_date(str); 
}


bool Date::operator==(const Date& rhs){
    // TODO
    return day==rhs.day && month ==rhs.month && year==rhs.year;
}


bool Date::operator!=(const Date& rhs){
    // TODO
    return day!=rhs.day || month !=rhs.month || year!=rhs.year;

}

bool Date::operator < (const Date& rhs){
    // TODO
    if (year > rhs.year) return false;
    else if (year < rhs.year) return true;
    else if (month > rhs.month) return false;
    else if (month < rhs.month) return true;
    else if (day >= rhs.day) return false;
    else return true;
}

bool Date::operator > (const Date& rhs){
    // TODO
    if (year < rhs.year) return false;
    else if (year > rhs.year) return true;
    else if (month < rhs.month) return false;
    else if (month > rhs.month) return true;
    else if (day <= rhs.day) return false;
    else return true;
}

bool Date::check_date(int day, int month, int year){
    if (year<1)
        return false;
    if (month<1 | month >12)
        return false;

    if (month ==1 | month ==3 | month ==5 |month == 7 |month == 8 | month == 10 |month == 12){
        if (day<1 | day > 31)
            return false;
    }
    if (month ==4 | month ==6 | month ==9 |month == 11){
        if (day<1 | day > 30)
            return false;
    }
    if (year%4==0){
        if (year%100 == 0 && year%400!=0){
            if (month == 2){
                if (day < 1 | day > 28)
                    return false;
            }
        }
        else if (month == 2){
                if (day < 1 | day > 29)
                    return false;
            }
    }
    return true;
}

bool Date::set_date(string str){
    // TODO
    // input format should be M/D/YYYY
    char month[3];   // three is enough!
    char day[3];     // also size three is enough!
    char year[10];

    int ptr1 = 0;
    int ptr2 = 0;

    while(str[ptr1] != '/'){
        month[ptr1] = str[ptr1];
        ptr1++;
    }
    month[ptr1] = 0;
    ptr2 = ptr1 + 1;
    while(str[ptr2] != '/'){
        day[ptr2-ptr1-1] = str[ptr2];
        ptr2++;
    }
    day[ptr2-ptr1-1] = 0;

    int ptr3 = ptr2 + 1;
    while(ptr3 < str.length()){
        year[ptr3-ptr2-1] = str[ptr3];
        ptr3++;
    }
    year[ptr3-ptr2-1] = 0;
    //cout << "day: " << day << "month: " << month << "year: " << year;

    return set_date(atoi(day), atoi(month), atoi(year));
        
    
}


bool Date::set_date(int day, int month, int year){
    // Already done!
    // returns a true if operation successful, or false if unsuccessful
    // understand why we used "this" statement in this method
    if (check_date(day, month, year)){
        this->day = day;
        this->month = month;
        this->year = year;
        return true;
    }
    else {
        cout << "Error! Invalid date!" << endl;
        cout << "Date set to default!" << endl;
        this->day = 1;
        this->month = 1;
        this->year = 1970;
        return false;
    }
}


void Date::print_date(string type){
    // TODO
    // Different types for print, are: 
    //cout<< "hello"<<endl;
    //cout << "day: " << day << "month: " << month << "year: " << year;
    string month_word;
    switch(month){
        case 1:
            month_word = "January";
            break;
        case 2:
            month_word = "February";
            break;
        case 3:
            month_word = "March" ;
            break;
        case 4:
            month_word = "April";
            break;
        case 5:
            month_word = "May";
            break;
        case 6:
            month_word = "June";
            break;
        case 7:
            month_word = "July";
            break;
        case 8:
            month_word = "August";
            break;
        case 9:
            month_word = "September";
            break;
        case 10:
            month_word = "October";
            break;
        case 11:
            month_word = "November";
            break;
        case 12:
            month_word = "December";
            break;
    }
    
    if (type == "M/D/YYYY")
        cout << month << "/" << day << "/" << year <<endl;
    else if (type == "Month D, YYYY")
        cout << month_word << " " <<day << ", " <<year<<endl;
    else if (type == "D-Month-YYYY")        
        cout << day << "-" << month_word << "-" << year<<endl;
    else
        cout << "Wrong print type!" << endl;
}

string Date::get_date(){
    // Already done!
    ostringstream ss;
    ss << month << "/" << day << "/" << year; 
    string str = ss.str();
    return str;
}

