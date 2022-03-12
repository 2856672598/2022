#include "vector.h"
#include <string>
#include <algorithm>
using std::string;
using std::cout;
using namespace wkn;
void text_vector1()
{
	vector<string>nums;
	string s1("hello");
	nums.push_back(s1);
	nums.push_back(s1);
	vector<string>nums1(nums);

	for (int i = 0; i < (int)nums1.size(); i++)
	{
		cout << nums1[i] << endl;
	}
	for (auto& e : nums)
	{
		cout << e << endl;
	}
}

void text_vector2()
{
	vector<int>nums;
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(3);

	auto it = std::find(nums.begin(), nums.end(), 6);
	if (it != nums.end())
		nums.insert(it, 100);
	nums.insert(nums.begin(), 10);
	for (auto e : nums)
		cout << e << " ";
}

void text_vector3()
{
	vector<int>num1;
	num1.push_back(1);
	num1.push_back(2);
	num1.push_back(3);
	vector<int>num2;
	num2.push_back(4);
	num2.push_back(5);
	num2.push_back(6);

	num1.swap(num2);
	for (auto e : num1)
		cout << e << " ";
	cout << endl;

	num2.resize(10, 1);
	cout << "num2 size:" << num2.size() << endl;
	num2.resize(5);
	num2.clear();
	cout << "num2 size:" << num2.size() << endl;

	for (auto e : num2)
		cout << e << " ";
	cout << endl;
}

void text_vector4()
{
	vector<int>nums;
	nums.push_back(2);
	//nums.push_back(2);
	//nums.push_back(4);
	//nums.push_back(5);
	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		if (*it % 2 == 0)
			it = nums.erase(it);
		else
			it++;
	}
	for (auto e : nums)
		cout << e << " ";
	vector<string>s;
	s.push_back("hello");
	vector<string>s2;
	s2 = s;
	for (auto e : s2)
		cout << e;
}

int main()
{
	text_vector4();
	//text_vector3();
	//text_vector2();
	//text_vector1();
	return 0;
}
