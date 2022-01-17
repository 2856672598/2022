#pragma once
#include <iostream>
class Date
{
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