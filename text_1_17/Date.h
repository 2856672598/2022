#pragma once
#include <iostream>
//using namespace std;
using std::ostream;
using std::istream;
class Date
{
public:
    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);

public:
    Date(int year = 1, int month = 1, int day = 1)
        : _year(year),
          _month(month), _day(day)
    {
    }

    int GetMonthDay(int year, int month)const;
    Date &operator+=(int day);
    Date operator+(int day)const;
    Date operator-(int day)const;
    Date& operator-=(int day);
    Date &operator++();
    Date operator++(int);
    int operator-(Date &d)const;

    bool operator>(const Date &d)const;
    bool operator>=(const Date &d)const;
    bool operator<(const Date &d)const;
    bool operator<=(const Date &d)const;
    bool operator==(const Date &d)const;
    bool operator!=(const Date &d)const;
    int DateInit(int init)const;

    void Print()const;
    void WeekDay()const;
private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& out,const Date &d);
istream& operator>>(istream &in, Date &d);
