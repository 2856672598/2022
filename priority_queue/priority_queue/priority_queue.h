#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
namespace  wkn
{
	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	private:
		void adjustup(int chil)
		{
			int child = chil;
			int parent = (child - 1) / 2;
			Compare compare;
			while (child > 0 && compare(_container[parent], _container[child]))
			{
				swap(_container[parent], _container[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
		}

		void adjustdown(int par)
		{
			int parent = par;
			int child = parent * 2 + 1;
			Compare compare;
			while (child < (int)_container.size())
			{
				if (child + 1 < (int)_container.size()
					&& compare(_container[child], _container[child + 1])) {
					child = child + 1;
				}
				if (compare(_container[parent], _container[child])) {
					swap(_container[child], _container[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					//无需在向下调整
					break;
				}
			}
		}
	public:
		priority_queue()
		{}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_container(first, last)
		{
			for (int i = (_container.size() - 2) / 2; i >= 0; i--)
			{
				adjustdown(i);
			}
		}

		void push(const T& val)
		{
			_container.push_back(val);
			adjustup(_container.size() - 1);
		}

		void pop()
		{
			assert(_container.size() > 0);
			swap(_container[0], _container[_container.size() - 1]);
			_container.pop_back();
			adjustdown(0);
		}

		const T& top()
		{
			return _container[0];
		}

		bool empty()
		{
			return _container.size() == 0;
		}
		size_t size()const
		{
			return _container.size();
		}
	private:
		Container _container;

	};
}
