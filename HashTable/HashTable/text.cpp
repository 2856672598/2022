#include <vector>
#include <string>
#include <utility>
#include "HashTable.h"
#include "UnorderedMap.h"
#include "UnorderedSet.h"

void TextUnorderedMap()
{
	//UnorderedMap<int, int>m;
	//vector<int>nums{ 10,20,30,40,56,66,34,45,17,18 };
	//for (int i = 0; i < (int)nums.size(); i++) {
	//	m.Insert({ nums[i],nums[i] });
	//}
	//m.Insert({ 19,19 });

	//for (int i = 0; i < (int)nums.size(); i++) {
	//	m.Erase(nums[i]);
	//}
	//cout << m.Erase(100) << endl;
	//UnorderedMap<int, int>::iterator it = m.Begin();
	//while (it != m.End()) {
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}

	vector<pair<string, string>>nums{ {"left","×ó±ß"},{"right","ÓÒÃæ"},{"apple","Æ»¹û"}, {"pear","Ñ¼Àæ"} };
	UnorderedMap<string, string>m;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		m.Insert({ nums[i] });
	}
	m["pear"] = "Àæ";
	m.Erase("left");
	cout << m.Insert({ "left","×ó±ß" }).second << endl;
	UnorderedMap<string, string>::iterator it = m.Begin();
	while (it != m.End()) {
		cout << it->first << " " << it->second << endl;
		++it;
	}
}

void TextUnorderedSet()
{
	//vector<int>nums{ 10,20,30,40,56,66,34,45,17,18 };
	//Set::UnorderedSet<int> s;
	//for (int i = 0; i < (int)nums.size(); i++)
	//{
	//	s.Insert(nums[i]);
	//}
	//Set::UnorderedSet<int>::iterator it = s.Begin();
	//while (it != s.End()) {
	//	cout << *it << " ";
	//	++it;
	//}
	vector<string>nums{ "hello","world","left","right","map" };
	Set::UnorderedSet<string> s;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		s.Insert(nums[i]);
	}
	Set::UnorderedSet<string>::iterator it = s.Begin();
	while (it != s.End()) {
		cout << *it << " ";
		++it;
	}
}

int main()
{
	wkn::Text();
	TextUnorderedMap();
	//TextUnorderedSet();
	return 0;
}