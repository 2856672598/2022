#pragma once
#include "RBTree.h"

namespace wkn
{
	template<class K, class V>
	class Map
	{
		struct Getk
		{
			const K& operator()(const pair<K, V>&kv)
			{
				return kv.first;
			}
		};

	private:
		RBTree<K, pair<const K, V>, Getk>_root;
		typedef typename RBTree<K, pair<const K, V>, Getk>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, Getk>::const_iterator const_iterator;
	public:
		void Insert(const pair<K, V>& val)
		{
			_root.Insert(val);
		}

		iterator Begin()
		{
			return _root.Begin();
		}

		iterator End()
		{
			return _root.End();
		}

		const_iterator  cbegin()
		{
			return _root.cbegin();
		}

		const_iterator cend()
		{
			return  _root.cend();
		}

		V& operator[](const K& k)
		{
			return _root.Insert({ k,V() }).first->second;
		}

		iterator Find(const K& val)
		{
			return _root.Find(val);
		}
	};
}