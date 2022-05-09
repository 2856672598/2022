#pragma once
#include <iostream>
#include <utility>

using namespace std;
template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;
	pair<K, V>_kv;
	int _bf;//平衡因子

	AVLTreeNode(pair<K, V> val)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(val)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
private:
	Node* _root;
public:
	AVLTree()
		: _root(nullptr)
	{}

	bool Insert(pair<K, V>val)
	{
		if (_root == nullptr){
			_root = new Node(val);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_kv.first > val.first)
				cur = cur->_left;
			else if (cur->_kv.first < val.first)
				cur = cur->_right;
			else
				return false;
		}

		//找到插入位置
		if (parent->_kv.first > val.first) {
			parent->_left = new Node(val);
			parent->_left->_parent = parent;
			cur = parent->_left;
		}
		else {
			parent->_right = new Node(val);
			parent->_right->_parent = parent;
			cur = parent->_right;

		}
		//调节平衡因子
		while (parent)
		{
			if (cur == parent->_left) {
				parent->_bf -= 1;
			}
			else
				parent->_bf += 1;

			if (parent->_bf == -2 || parent->_bf == 2) {
				//进行旋转
				if (parent->_bf == 2) {
					//右边高
					RotateL(parent);
					break;
				}
				else {
					RotateR(parent);
					break;
				}
			}
			else if (parent->_bf == 0) {
				//此时已经平衡
				return true;
			}
			cur = parent;
			parent = parent->_parent;
		}
		return true;
	}
	//右单旋
	void RotateR(Node* cur)
	{
		Node* left = cur->_left;
		Node* parent = cur->_parent;
		cur->_left = left->_right;
		left->_right = cur;
		if (cur->_left != nullptr)
			cur->_left->_parent = cur;
		cur->_parent = left;
		left->_parent = parent;
		if (_root == cur)
			_root = left;
		left->_bf = cur->_bf = 0;
	}

	void RotateL(Node* cur)
	{
		Node* parent = cur->_parent;
		Node* right = cur->_right;
		cur->_right = right->_left;
		right->_left = cur;
		cur->_parent = right;
		right->_parent = parent;
		if (cur->_right != nullptr)
			cur->_right->_parent = cur;
		if (cur == _root) {
			_root = right;
		}
		right->_bf = cur->_bf = 0;
	}
};