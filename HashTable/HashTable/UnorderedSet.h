#pragma once
#include "HashTable.h"

namespace Set
{
	template<class K>
	struct HashFunction
	{
		size_t operator()(const K& key)
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

	template<class K>
	struct GetK
	{
		const K& operator()(const K& val)
		{
			return val;
		}
	};

	template<class K>
	class UnorderedSet
	{
	private:
		OpenHash::HashTable<const K, const K, HashFunction<K>, GetK<K>> _table;
	public:
		typedef typename OpenHash::HashTable<const K, const K, HashFunction<K>, GetK<K>>::iterator iterator;

		iterator Begin()
		{
			return _table.Begin();
		}

		iterator End()
		{
			return _table.End();
		}

		pair<iterator, bool>Insert(const K& val)
		{
			return _table.Insert(val);
		}

		bool Erase(const K& key)
		{
			return _table.Erase(key);
		}
	};
}
