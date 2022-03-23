#pragma once

namespace wkn
{
	template<class iterator, class Ref, class Ptr>
	class __Reverse_iterator
	{
	public:
		typedef __Reverse_iterator<iterator, Ref, Ptr> reverse_iterator;
	public:

		__Reverse_iterator(const iterator& it)
			:_rit(it)
		{}

		Ref operator*()
		{
			iterator tmp = _rit;
			return *--tmp;
		}

		Ptr operator->()
		{
			return &operator*();
		}

		reverse_iterator& operator++()
		{
			--_rit;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			--_rit;
			return tmp;
		}

		reverse_iterator& operator--()
		{
			++_rit;
			return *this;
		}

		bool operator!=(const reverse_iterator& it)const
		{
			return  _rit != it._rit;
		}
	private:
		iterator _rit;
	};
}