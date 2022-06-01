#pragma once

#include <iostream>
#include <vector>
#include <bitset>
#include <assert.h>
using namespace std;

template<size_t N>
class BitSet
{
private:
	vector<int>_bit;
public:
	BitSet()
		:_bit(N / 32 + 1, 0)
	{}

	void Set(size_t pos)
	{
		//算出在几号位置的第几个比特位上
		size_t i = pos / 32;
		size_t j = pos % 32;
		if (i >= _bit.size())
			assert(false);
		_bit[i] |= (1 << j);
	}

	void Reset(size_t pos)
	{
		size_t i = pos / 32;
		size_t j = pos % 32;
		if (i >= _bit.size())
			assert(false);
		_bit[i] &= ~(1 << j);
	}

	bool Text(size_t pos)
	{
		size_t i = pos / 32;
		size_t j = pos % 32;
		if (i >= _bit.size())
			assert(false);
		return _bit[i] & (1 << j);
	}
};

class BKDRHash
{
public:
	size_t operator()(const string& str)
	{
		register size_t hash = 0;
		for (const auto& e : str)
			hash = hash * 131 + e;
		return hash;
	}
};

class SDBMHash
{
public:
	size_t operator()(const string& str)
	{
		register size_t hash = 0;
		for (const auto& e : str)
			hash = 65599 * hash + e;
		return hash;
	}
};

class RSHash
{
public:
	size_t operator()(const string& str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		for (const auto& e : str)
		{
			hash = hash * magic + e;
			magic *= 378551;
		}
		return hash;
	}
};

template<class T, size_t N, class Hash1 = BKDRHash, class Hash2 = SDBMHash, class Hash3 = RSHash>
class BloomFilter
{
private:
	bitset<N * 5>_bits;
public:
	void Set(const T& key)
	{
		size_t index1 = Hash1()(key) % _bits.size();
		size_t index2 = Hash2()(key) % _bits.size();
		size_t index3 = Hash3()(key) % _bits.size();

		_bits.set(index1);
		_bits.set(index2);
		_bits.set(index3);
	}

	bool Text(const T& key)
	{
		size_t index1 = Hash1()(key) % _bits.size();
		size_t index2 = Hash2()(key) % _bits.size();
		size_t index3 = Hash3()(key) % _bits.size();
		return _bits.test(index1) && _bits.test(index2) && _bits.test(index3);
	}
};