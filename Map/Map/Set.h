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
		typedef typename RBTree<K, K, GetK>::const_iterator const_iterator;
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

		const_iterator cbegin()
		{
			return _root.cbegin();
		}

		const_iterator cend()
		{
			return _root.cend();
		}

		iterator Find(const K& val)
		{
			return  _root.Find(val);
		}
	};
}