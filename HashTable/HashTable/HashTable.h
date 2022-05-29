#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <assert.h>
using namespace std;
namespace wkn
{
	enum status
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashNode
	{
		pair<K, V>_data;
		status _st;
		HashNode()
			:_st(EMPTY)
		{}
	};

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

	template<class K, class V, class Hash = HashFunction<K>>
	class HashTable
	{
	private:
		vector<HashNode<K, V>>_hashTable;
		int _n;//表中的元素个数
	public:

		void Insert(const pair<K, V>& val)
		{
			if (_hashTable.size() == 0 || _n * 10 / _hashTable.size() >= 7) {
				//进行扩容
				HashTable<K, V, Hash> newTable;
				size_t newSize = _hashTable.size() == 0 ? 10 : 2 * _hashTable.size();
				newTable._hashTable.resize(newSize);
				for (int i = 0; i < (int)_hashTable.size(); i++)
				{
					if (_hashTable[i]._st == EXIST)
						newTable.Insert(_hashTable[i]._data);
				}
				_hashTable.swap(newTable._hashTable);
			}
			//计算所在的位置
			Hash obj;
			size_t index = obj(val.first) % _hashTable.size();
			while (_hashTable[index]._st == EXIST)
			{
				index++;
				index = index % _hashTable.size();
			}
			_hashTable[index]._data = val;
			_hashTable[index]._st = EXIST;
			_n++;
		}

		HashNode<K,V>* Find(const K& key)
		{
			if (_hashTable.size() == 0)
				return nullptr;
			Hash obj;
			size_t index = obj(key) % _hashTable.size();
			while (_hashTable[index]._st != EMPTY)
			{
				if (_hashTable[index]._data->first == key && _hashTable[index]._st == EXIST) {
					return &_hashTable[index];
				}
				index++;
				index %= _hashTable.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashNode<K, V>* ptr = Find(key);
			if (ptr == nullptr)
				return false;
			_n--;
			ptr->_st = DELETE;
			return true;
		}

		void Swap(HashTable& table)
		{
			_hashTable.swap(table._hashTable);
			swap(_n, table._n);
		}
	};

	void Text()
	{
		HashTable<int, int>table1;
		HashTable<int, int>table2;
		vector<int>nums{ 1,10,4,90 };
		for (auto e : nums)
			table1.Insert({ e,e });
		table1.Swap(table2);
	}
}

namespace OpenHash
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode* _next;
		HashNode(const T& val)
			:_data(val)
			,_next(nullptr)
		{}
	};
	template<class K, class T, class Hash, class GetKey>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class Hash, class Getk>
	class Iterator
	{
	private:
		HashNode<T>*_node;
		HashTable<K, T, Hash, Getk>* _pHashTable;
	public:
		typedef Iterator<K, T, Ref, Ptr, Hash, Getk> self;

		Iterator(HashNode<T>* node, HashTable<K, T, Hash, Getk>* _pht)
			:_node(node)
			, _pHashTable(_pht)
		{}


		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self& operator++()
		{
			Getk getk;
			Hash hash;
			if (_node->_next)
			{
				_node = _node->_next;
				return *this;
			}
			size_t sz = _pHashTable->_table.size();
			//计算当前所在的桶的下标
			size_t index = hash(getk(_node->_data)) % sz;
			index++;
			while (index < sz&& _pHashTable->_table[index] == nullptr)
				index++;
			if (index == sz)
				_node = nullptr;
			else
				_node = _pHashTable->_table[index];
			return *this;
		}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};


	template<class K, class T, class Hash, class GetKey>
	class HashTable
	{
	private:
		vector<HashNode<T>*>_table;
		size_t _n = 0;
	private:
		void Clear()
		{
			for (int i = 0; i < (int)_table.size(); i++)
			{
				if (_table[i] != nullptr) {
					HashNode<T>* cur = _table[i];
					HashNode<T>* next = nullptr;
					while (cur)
					{
						next = cur->_next;
						delete cur;
						cur = next;
					}
				}
			}
		}
		void Copy(const HashTable<K, T, Hash, GetKey>& table)
		{
			_table.resize(table._table.size());
			_n = table._n;
			for (int i = 0; i < (int)_table.size(); i++)
			{
				if (table._table[i] != nullptr) {
					HashNode<T>* cur = table._table[i];
					HashNode<T>* next = nullptr;
					while (cur)
					{
						next = cur->_next;
						HashNode<T>* newNode = new HashNode<T>(cur->_data);
						newNode->_next = _table[i];
						_table[i] = newNode;
						cur = next;
					}
				}
			}
		}

		bool Empty()
		{
			return _n == 0;
		}
	public:
		template<class K, class T, class Ref, class Ptr, class Hash, class GetK>
		friend class Iterator;
		typedef Iterator<K, T, T&, T*, Hash, GetKey> iterator;

		HashTable()
			:_n(0)
		{}

		~HashTable()
		{
			Clear();
		}
		HashTable(const HashTable<K, T, Hash, GetKey>& table)
		{
			Copy(table);
		}

		HashTable& operator=(HashTable<K, T, Hash, GetKey> table)
		{
			_table.swap(table._table);
			swap(_n, table._n);
			return *this;
		}
	public:

		HashNode<T>* Find(const K& key)
		{
			if (_table.size() == 0)
				return nullptr;
			GetKey getkey;
			Hash hash;
			size_t index = hash(key) % _table.size();
			HashNode<T>* cur = _table[index];
			while (cur)
			{
				if (getkey(cur->_data) == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		pair<iterator, bool> Insert(const T& val)
		{
			GetKey getkey;
			Hash hash;
			K key = getkey(val);
			HashNode<T>*pos = Find(key);
			if (pos != nullptr) {
				return { iterator(pos, this), false };
			}
			if (_n == _table.size())
			{
				//进行扩容
				size_t newSize = _table.size() == 0 ? 10 : 2 * _n;
				vector<HashNode<T>*>newTable(newSize);
				for (int i = 0; i < (int)_table.size(); i++)
				{
					if (_table[i] != nullptr)
					{
						HashNode<T>* cur = _table[i];
						while (cur)
						{
							HashNode<T>*next = cur->_next;
							size_t index = hash(getkey(cur->_data)) % newSize;
							cur->_next = newTable[index];
							newTable[index] = cur;
							cur = next;
						}
					}
				}
				newTable.swap(_table);
			}

			HashNode<T>* newnode = new HashNode<T>(val);
			size_t index = hash(getkey(val)) % _table.size();
			newnode->_next = _table[index];
			_table[index] = newnode;
			_n++;
			return { iterator(newnode, this),true };
		}

		bool Erase(const K& key)
		{
			Hash hash;
			GetKey getk;
			if (Empty())
				return false;
			size_t index = hash(key) % _table.size();
			HashNode<T>* cur = _table[index];
			HashNode<T>*prev = nullptr;

			while (cur)
			{
				if (getk(cur->_data) == key) {
					if (prev == nullptr) {
						_table[index] = cur->_next;
					}
					else {
						prev->_next = cur->_next;
					}
					delete cur;
					_n--;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		iterator Begin()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i] == nullptr)
					continue;
				return  iterator(_table[i], this);
			}
			return End();
		}

		iterator End()
		{
			return iterator(nullptr, this);
		}
	};
}
