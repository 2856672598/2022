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
	};
}