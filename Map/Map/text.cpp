#include "Map.h"
#include "Set.h"
void TextMap()
{
	wkn::Map<int, int>m;
	m.Insert({ 1,1 });
	m.Insert({ 2,2 });
	m.Insert({ 3,4 });
	auto it = m.Begin();
	while (it != m.End()) {
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}

void TextSet()
{
	wkn::Set<int> s;
	s.Insert(10);
	s.Insert(13);
	s.Insert(12);
	auto it = s.Begin();
	while (it != s.End())
	{
		cout << *it << endl;
		++it;
	}
}

int main()
{
	//TextMap();
	TextSet();
	return 0;
}