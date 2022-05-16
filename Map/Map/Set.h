#pragma once
#include "RBTree.h"

namespace wkn
{
	template<class K>
	class Set
	{
		struct GetK
		{
			const K& operator()(const K& val)
			{
				return val;
			}
		};
	private:
		typedef typename RBTree<K, K, GetK>::iterator iterator;

		RBTree<K, K, GetK>_root;
	public:

		void Insert(const K& val)
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