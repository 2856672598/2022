#include"Date.h"
using namespace std;

int main()
{
    Date d1(2022, 1, 17);
    Date d2(d1);
    Date d3(2002,1,1);
    // cout << (d1 >= d3) << endl;
    // cout << (d1 == d2) << endl;
    // d1.Print();
    // d1-=100;
    // d1.Print();
    d2 =d1- -100;
    d2.Print();
    d2=d2+-100;
    d2.Print();
    Date d4(2046,1,31);
    cout<<d4-d1<<endl;
    d4.WeekDay();
    cout<<d4;
    return 0;
}