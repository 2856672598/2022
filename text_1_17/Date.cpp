#include "Date.h"

int Date::GetMonthDay(int year, int month)const
{
    int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = arr[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 4 == 0))
        day += 1;
    return day;
}
Date &Date::operator+=(int day)
{
    if(day<0)
    {
        *this-=-day;
        return *this;
    }
    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        _month++;
        if (_month >= 13)
        {
            _month = 1;
            _year++;
        }
    }
    return *this;
}

Date Date::operator+(int day)const
{
    Date ret(*this);
    ret += day;
    return ret;
}
void Date::Print()const
{
    std::cout << _year << "-" << _month << "-" << _day << std::endl;
}

//前置++
Date &Date::operator++()
{
    (*this) += 1;
    return *this;
}
//后置++
Date Date::operator++(int)
{
    Date ret(*this);
    (*this) += 1;
    return ret;
}

bool Date::operator>(const Date &d)const
{
    if (_year > d._year)
        return true;
    else if (_year == d._year && _month > d._month)
        return true;
    else if (_year == d._year && _month > d._month && _day > d._day)
        return true;
    return false;
}

bool Date::operator==(const Date &d)const
{
    if (d._day == _day && d._month == d._month && d._year == _year)
        return true;
    return false;
}

bool Date::operator>=(const Date &d)const
{
    return *this > d || *this == d;
}

bool Date::operator<(const Date &d)const
{
    return !(*this >= d);
}
bool Date::operator<=(const Date &d)const
{
    return !(*this > d);
}
bool Date::operator!=(const Date &d)const
{
    return !(*this == d);
}
Date& Date::operator-=(int day)
{
    if(day<0)
    {
        *this+=-day;
        return *this;
    }
    _day -= day;
    while (_day <= 0)
    {
        _month--;
        if (_month <= 0)
        {
            _year--;
            _month = 12;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;
}

Date Date::operator-(int day)const
{
    Date ret(*this);
    ret -= day;
    return ret;
}

int Date::DateInit(int init)const
{
    int day = 0;
    for (int i = init; i < _year; i++)
    {
        day += 365;
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            day += 1;
    }
    for (int i = 1; i < _month; i++)
    {
        day += GetMonthDay(_year, i);
    }
    return day += _day;
}

int Date::operator-(Date &d)const
{
    int ret = 0;
    Date begin = (*this) < d ? (*this) : d;
    return abs(DateInit(begin._year) - d.DateInit(begin._year));
}

void Date::WeekDay()const
{
    const char* arr[] ={"周一","周二","周三","周四","周五","周六","周日"};
    Date statr(1970,1,1);
    int day = *this -statr + 3;
    std::cout<<arr[day%7]<<std::endl;
}