#include "BitSet.h"

void TextBitSet()
{
	BitSet<100>bit;
	for (int i = 1; i < 100; i += 2)
		bit.Set(i);
	bit.Reset(1);
	bit.Reset(3);
	bit.Reset(99);
	for (int i = 1; i < 100; i++)
		cout << bit.Text(i) << endl;
}

void TextBloomFilter()
{
	BloomFilter<string, 5>bf;
	bf.Set("hello");
	bf.Set("world");
	cout << bf.Text("hello");
}

int main()
{
	TextBloomFilter();
	return 0;
}