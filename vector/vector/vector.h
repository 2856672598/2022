#pragma once
#include <iostream>
#include <assert.h>
using std::endl;
using std::cerr;

namespace wkn
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//øΩ±¥ππ‘Ï
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T>tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector& operator=(vector<T> x)
		{
			swap(x);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		void reserve(int n)
		{
			if (n > (int)capacity()) {
				T* tmp = new T[n];
				if (tmp == nullptr)
					exit(1);
				for (int i = 0; i < (int)size(); i++)
				{
					tmp[i] = _start[i];
				}
				_finish = tmp + size();
				delete[] _start;
				_start = tmp;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, T val = T())
		{
			if (size() >= n)
			{
				_finish = _start + n;
			}
			else
			{
				//≈–∂œø’º‰ «∑Òπª
				if (n > capacity())
				{
					reserve(n);
				}
				for (size_t i = size(); i < n; i++)
				{
					push_back(val);
				}
			}
		}

		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			erase(_finish - 1);
		}

		iterator insert(iterator position, const T& val)
		{
			assert(position >= _start);
			assert(position <= _finish);
			if (_finish == _end_of_storage)
			{
				//ø‚»›
				size_t newcapacity = capacity() == 0 ? 10 : 2 * capacity();
				int gap = position - _start;
				reserve(newcapacity);
				//∑¿÷πµ¸¥˙∆˜ µ–ß
				position = _start + gap;
			}
			auto begin = _finish;
			while (begin > position)
			{
				*begin = *(begin - 1);
				begin--;
			}
			*begin = val;
			++_finish;
			return position;
		}

		iterator erase(iterator position)
		{
			assert(position >= _start);
			assert(position < _finish);
			auto begin = position + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			_finish--;
			return position;
		}

		bool empty()const
		{
			return _finish == _start;
		}

		T& operator[](int pos)
		{
			assert(pos < (int)size() && pos >= 0);
			return _start[pos];
		}

		const T& operator[](int pos)const
		{
			assert(pos < (int)size() && pos >= 0);
			return _start[pos];
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const iterator begin()const 
		{
			return _start;
		}

		const iterator end()const
		{
			return _finish;
		}

		void clear()const
		{
			_finish = _start;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

	private:
		T* _start;
		T*_finish;
		T* _end_of_storage;
	};
}
