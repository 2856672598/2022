#include "Map.h"
#include "Set.h"
void TextMap()
{
	wkn::Map<int, int>m;
	m.Insert({ 100,1 });
	m.Insert({ 90,2 });
	m.Insert({ 13,4 });
	wkn::Map<int, int>m1(m);
	m[100] = 100;
	m[3];
	auto it = m.Begin();
	while (it != m.End()) {
		it->second = 10;
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	auto it1 = m.cbegin();
	while (it1 != m.cend()) {
		cout << it1->first << ":" << it1->second << endl;
		++it1;
	}
	//cout << m.Find(13)->first << m.Find(13)->second << endl;

}

void TextSet()
{
	wkn::Set<int> s;
	s.Insert(15);
	s.Insert(13);
	s.Insert(12);

	wkn::Set<int> s1(s);
	auto it = s.Begin(); 
	//*it = 100;
	while (it != s.End())
	{
		cout << *it << endl;
		++it;
	}

	auto it1 = s1.cbegin();
	//*it1 = 10;
	while (it1 != s1.cend())
	{
		cout << *it1 << endl;
		++it1;
	}
	cout << *s.Find(15) << endl;
}

int main()
{
	TextMap();
	//TextSet();
	return 0;
}