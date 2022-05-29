#pragma once

#include "HashTable.h"

template<class K>
struct HashFunction
{
	size_t operator()(K key)
	{
		return key;
	}
};

template<>
struct HashFunction <string>
{
	size_t operator()(const string& key)
	{
		size_t ret = 0;
		for (int i = 0; i < (int)key.size(); i++)
		{
			ret = ret * 31 + key[i];
		}
		return ret;
	}
};

template<class K, class T>
struct GetK
{
	const K& operator()(const T& val)
	{
		return val.first;
	}
};

template<class K, class V>
class UnorderedMap
{
private:
	OpenHash::HashTable<const K, pair<const K, V>, HashFunction<K>, GetK<K, pair< K, V>>>_table;
public:
	typedef typename OpenHash::HashTable <const K, pair<const K, V>, HashFunction<K>, GetK<K, pair< K, V>>>::iterator iterator;
	pair<iterator, bool>Insert(const pair<K, V>& val)
	{
		return  _table.Insert(val);
	}

	bool Erase(const K& key)
	{
		return _table.Erase(key);
	}

	iterator Begin()
	{
		return _table.Begin();
	}

	iterator End()
	{
		return _table.End();
	}

	V& operator[](const K& key)
	{
		return Insert({ key,V() }).first->second;
	}
};