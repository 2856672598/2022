#pragma once
#include <iostream>
#include <assert.h>
namespace wkn
{
	template<class T>
	class ListNode
	{
	public:
		ListNode(const T& val = T())
			:prev(nullptr)
			, next(nullptr)
			, val(val)
		{}

		T val;
		ListNode<T>* prev;
		ListNode<T>* next;
	};

	template<class T, class Ref, class Ptr>
	class __List_iterator
	{
	public:
		typedef ListNode<T> node;
		typedef __List_iterator<T, Ref, Ptr> self;
	public:
		__List_iterator(node* x)
			:_node(x)
		{};

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}
		
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->prev;
			return tmp;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->next;
			return tmp;
		}

		Ref& operator*()
		{
			return _node->val;
		}

		Ptr operator->()
		{
			return &_node->val;
		}
		node* _node;
	};

	template<class T>
	class List
	{
	public:
		typedef ListNode<T> node;
		typedef __List_iterator<T, T&, T*> iterator;
		typedef __List_iterator<T, const T&, const T*> const_iterator;
	public:
		List()
		{
			_head = new node;
			_head->next = _head->prev = _head;
		}

		~List()
		{
			node* cur = _head->next, *next = nullptr;
			while (cur != _head)
			{
				next = cur->next;
				delete cur;
				cur = next;
			}
			delete cur;
			_head = nullptr;
		}

		List(const List& node)
		{
			
		}

		void push_back(const T& val)
		{
			insert(_head, val);
		}

		void push_front(const T& val)
		{
			insert(_head->next, val);
		}

		void pop_back()
		{
			erase(_head->prev);
		}

		void pop_front()
		{
			erase(_head->next);
		}

		iterator insert(iterator position, const T val)
		{
			node* newnode = new node(val);
			node* prev = position._node->prev;
			node* next = position._node;
			newnode->next = next;
			next->prev = newnode;
			newnode->prev = prev;
			prev->next = newnode;
			return iterator(newnode);
		}

		iterator erase(iterator position)
		{
			assert(position != _head);
			node* next = position._node->next;
			position._node->prev->next = next;
			next->prev = position._node->prev;
			delete position._node;
			return next;
		}

		iterator begin()
		{
			return _head->next;
		}

		const_iterator begin()const
		{
			return _head->next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator end()const
		{
			return _head;
		}

	private:
		node* _head;
	};
}