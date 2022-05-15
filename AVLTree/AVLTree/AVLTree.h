#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
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
					if (cur->_bf == 1)
						RotateL(parent);
					else if (cur->_bf == -1)
						RotateRL(parent);
					break;
				}
				else {
					if (cur->_bf == -1)
						RotateR(parent);
					else if (cur->_bf == 1)
						RotateLR(parent);
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
		if (cur->_left)
			cur->_left->_parent = cur;
		left->_right = cur;
		cur->_parent = left;
		left->_parent = parent;
		if (_root == cur) {
			_root = left;
		}
		else {
			if (parent->_kv.first > left->_kv.first) {
				parent->_left = left;
			}
			else
				parent->_right = left;
		}
		left->_bf = cur->_bf = 0;
	}

	void RotateL(Node* cur)
	{
		Node* right = cur->_right;
		Node* parent = cur->_parent;

		cur->_right = right->_left;
		right->_left = cur;
		cur->_parent = right;
		if (cur->_right)
			cur->_right->_parent = cur;
		right->_parent = parent;
		if (_root == cur) {
			_root = right;
		}
		else {
			if (parent->_kv.first > right->_kv.first)
				parent->_left = right;
			else
				parent->_right = right;
		}
		cur->_bf = right->_bf = 0;
	}

	//左旋加右旋
	void RotateLR(Node* cur)
	{
		Node* left = cur->_left;
		Node* leftR = left->_right;
		int bf = leftR->_bf;
		RotateL(left);
		RotateR(cur);
		if (bf == -1) {
			left->_bf = 0;
			cur->_bf = 1;
			leftR = 0;
		}
		else if (bf == 1) {
			left->_bf = -1;
			cur->_bf = 0;
			leftR->_bf = 0;
		}
		else if (bf == 0) {
			left->_bf = 0;
			cur->_bf = 0;
			leftR->_bf = 0;
		}
		else {
			//出错了
			assert(false);
		}
	}

	void RotateRL(Node* cur)
	{
		Node* right = cur->_right;
		Node* rightL = right->_left;
		int bf = rightL->_bf;
		RotateR(right);
		RotateL(cur);
		if (bf == -1) {
			right->_bf = 1;
			cur->_bf = 0;
			rightL->_bf = 0;
		}
		else if (bf == 1) {
			right->_bf = 0;
			cur->_bf = -1;
			rightL->_bf = 0;
		}
		else if (bf == 0) {
			right->_bf = 0;
			cur->_bf = 0;
			rightL->_bf = 0;
		}
		else {
			//出错了
			assert(false);
		}
	}

	void _Inorder(Node* root) {
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}

	int High(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = High(root->_left);
		int right = High(root->_right);
		return max(left, right) + 1;
	}

	void Inorder()
	{
		_Inorder(_root);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int left = High(root->_left);
		int right = High(root->_right);
		if (right - left != root->_bf) {
			cout << root->_kv.first << "当前节点不合法" << endl;
		}
		return abs(left - right) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
	}
};