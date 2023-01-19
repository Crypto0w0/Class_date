#include <iostream>
using namespace std;

class date{
    int day;
    int month;
    int year;
public:
    date();
    date(int day_, int month_, int year_);
    void check();
    date operator+(int d);
    date operator-(int d);
    date operator-(date d);
    bool operator>(date d);
    bool operator<(date d);
    bool operator>=(date d);
    bool operator<=(date d);
    
    date& operator++(){
        day += 1;
        check();
        return *this;
    }
    date operator++(int){
        day -= 1;
        check();
        date temp(this->day, this->month, this->year);
        return temp;
    }
    date& operator--(){
        day += 1;
        check();
        return *this;
    }
    date operator--(int){
        day -= 1;
        check();
        date temp(this->day, this->month, this->year);
        return temp;
    }
};

void date::check(){
    if (day > 31){
        while(day > 30){
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
                day -= 31;
                month++;
            }
            else if (month == 2 && year % 4 != 0){
                day -= 28;
                month++;
            }
            else if (month == 2 && year % 4 == 0){
                day -= 29;
                month++;
            }
            else{
                day -= 30;
                month++;
            }
        }
    }
    if (month > 12){
        while (month > 12){
            month -= 12;
            year++;
        }
    }
    
    if (day < 31){
        while(day < 30){
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
                day += 31;
                month--;
            }
            else if (month == 2 && year % 4 != 0){
                day += 28;
                month--;
            }
            else if (month == 2 && year % 4 == 0){
                day += 29;
                month--;
            }
            else{
                day += 30;
                month--;
            }
        }
    }
    if (month < 12){
        while (month < 12){
            month += 12;
            year--;
        }
    }
}

date::date(){
    day = 0;
    month = 0;
    year = 0;
}
date::date(int day_, int month_, int year_){
    day = day_;
    month = month_;
    year = year_;
}

date date::operator+(int d){
    day += d;
    check();
    return *this;
}

date date::operator-(int d){
    day -= d;
    check();
    return *this;
}

date date::operator-(date d){
    day -= d.day;
    month -= d.month;
    year -= d.year;
    check();
    return *this;
}

bool date::operator>(date d){
    if (day > d.day && month >= d.month && year >= d.year) return true;
    else return false;
}

bool date::operator<(date d){
    if (day < d.day && month <= d.month && year <= d.year) return true;
    else return false;
}

bool date::operator>=(date d){
    if (day >= d.day && month >= d.month && year >= d.year) return true;
    else return false;
}

bool date::operator<=(date d){
    if (day <= d.day && month <= d.month && year <= d.year) return true;
    else return false;
}


int main() {
    
}
