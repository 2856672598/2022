#include"list.h"
using std::cout;
using std::endl;
using namespace wkn;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	int _year;
	int _month;
	int _day;
};

void TextList1()
{
	List<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_front(6);
	nums.pop_front();
	auto it = nums.begin();
	while (it != nums.end())
	{
		cout << *it << endl;
		++it;
	}
}

void TextList2()
{
	List<Date>num;
	num.push_back(Date(2020, 12, 1));
	num.push_back(Date(2020, 9, 1));
	auto it = num.rbegin();
	while (it != num.rend())
	{
		cout << it->_year << " " << it->_month << " " << it->_day << endl;
		++it;
	}
}

void TextList3()
{
	List<int>nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	auto it = nums.rbegin();
	while (it != nums.rend())
	{
		cout << *it << " ";
		it++;
	}
}

int main()
{
	TextList2();
	TextList3();
	return 0;
}