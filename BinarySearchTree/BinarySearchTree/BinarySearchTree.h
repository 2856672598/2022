#pragma once

#include <iostream>
#include <vector>
using namespace std;


template<class T>
class Node
{
public:
	Node(T val)
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
	T _val;
	Node* _left;
	Node* _right;
};

template<class K>
class BSTree
{
public:
	bool Insert(K val)
	{
		if (_root == nullptr) {
			_root = new Node<K>(val);
			return true;
		}
		//Ѱ�Ҳ���λ��
		Node<K>* cur = _root;
		Node<K>* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (val < cur->_val) {
				cur = cur->_left;
			}
			else if (val > cur->_val)
				cur = cur->_right;
			else
				return false;
		}

		//�ҵ��˲���λ���ж��ǲ�������������������
		if (val > parent->_val) {
			parent->_right = new Node<K>(val);
		}
		else {
			parent->_left = new Node<K>(val);
		}
		return true;
	}

	//�������
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node<K>* root)
	{
		if (nullptr == root)
			return;
		_InOrder(root->_left);
		cout << root->_val << " ";
		_InOrder(root->_right);
	}

	bool Erase(K val)
	{
		Node<K>*cur = _root;
		Node<K>* parent = nullptr;
		while (cur)
		{
			if (cur->_val > val) {
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_val < val) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				//�ҵ���
				if (cur->_left == nullptr) {
					if (cur == parent->_left) {
						parent->_left = cur->_right;
					}
					else if (cur == parent->_right) {
						parent->_right = cur->_right;
					}
					delete cur;
					return true;
				}
				else if (cur->_right == nullptr) {
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
					delete cur;
					return true;
				}
				else {
					//���Ҷ���Ϊ��,�����滻ɾ��
					//ȥcur�������������Ľڵ�����滻
					Node<K>* maxParent = cur;
					Node<K>* maxNode = cur->_left;
					while (maxNode->_right)
					{
						maxParent = maxNode;
						maxNode = maxNode->_right;
					}
					cur->_val = maxNode->_val;
					if (maxParent->_left == maxNode) {
						maxParent->_left = maxNode->_left;
					}
					else
						maxParent->_right = maxNode->_left;
					delete maxNode;
					return true;
				}
			}
		}
		return false;
	}

	bool find(const K& val)
	{
		Node<K>* cur = _root;
		while (cur)
		{
			if (cur->_val < val) {
				cur = cur->_right;
			}
			else if (cur->_val > val) {
				cur = cur->_left;
			}
			else {
				return true;
			}
		}
		return false;
	}
	//�ݹ�汾����
	bool InsertR(const K& val)
	{
		return _InsertR(_root, val);
	}

	bool EraseR(const K& val)
	{
		return _EraseR(_root, val);
	}

	private:

		bool _InsertR(Node<K>*& root, const K& val)
		{
			if (root == nullptr) {
				root = new Node<K>(val);
				return true;
			}

			if (root->_val == val)
				return false;
			else if (root->_val > val)
				return _InsertR(root->_left, val);
			else
				return _InsertR(root->_right, val);
		}

		bool _EraseR(Node<K>*&root, const K& val)
		{
			if (root == nullptr)
				return false;
			if (root->_val > val) {
				return _EraseR(root->_left, val);
			}
			else if (root->_val < val) {
				return _EraseR(root->_right, val);
			}
			else
			{
				//��ǰ����Ҫɾ���Ľڵ㣬���������Ҳ�����
				Node<K>*del = root;
				if (nullptr == root->_left) {
					root = root->_right;
				}
				else if (nullptr == root->_right) {
					root = root->_left;
				}
				else {
					//ȥ�������������ֵ
					Node<K>*cur = root->_left;
					while (cur->_right)
					{
						cur = cur->_right;
					}
					root->_val = cur->_val;
					//ȥroot����������ɾ��cur;
					return _EraseR(root->_left, cur->_val);
				}
				delete del;
				return true;
			}
		}
private:
	Node<K>*_root = nullptr;
};
