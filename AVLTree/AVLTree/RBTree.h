#pragma once

#include <iostream>
using namespace std;

namespace wkn
{
	enum Color
	{
		READ,
		BLACK
	};
	template<class K,class V>
	struct RBTreeNode
	{
		RBTreeNode* _left;
		RBTreeNode* _right;
		RBTreeNode* _parent;
		pair<K, V> _data;
		Color _color;

		RBTreeNode(const pair<K, V>& val)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(val)
			, _color(READ)
		{}
	};

	template<class K,class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
	private:
		Node* _root;
	public:
		RBTree()
			:_root(nullptr)
		{}
		void Insert(const pair<K, V>& val)
		{
			if (_root == nullptr) {
				_root = new Node(val);
				_root->_color = BLACK;
				return;
			}
			//按照搜索树规则寻找插入位置
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (cur->_data.first > val.first)
					cur = cur->_left;
				else if (cur->_data.first < val.first)
					cur = cur->_right;
				else
					return;
			}

			//判断插入在左面还是右面
			if (parent->_data.first > val.first) {
				parent->_left = new Node(val);
				cur = parent->_left;
				cur->_parent = parent;
			}
			else {
				parent->_right = new Node(val);
				cur = parent->_right;
				cur->_parent = parent;
			}
			cur->_color = READ;

			//调整平衡
			while (parent &&parent->_color == READ && parent != _root)
			{
				Node* grandfather = parent->_parent;
				Node* uncle = grandfather->_right;
				if (parent == grandfather->_right)
					uncle = grandfather->_left;

				//叔叔存在且为红
				if (uncle && uncle->_color == READ) {
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = READ;
				}
				else
				{
					//叔叔不存在或为黑
					if (parent == grandfather->_left) {
						if (cur == parent->_left) {
							RotateR(grandfather);
							grandfather->_color = READ;
							parent->_color = BLACK;
						}
						else {
							//双旋
							RotateL(parent);
							RotateR(grandfather);
							cur->_color = BLACK;
							grandfather->_color = READ;
							break;
						}
					}
					else{
						if (cur == parent->_right) {
							RotateL(grandfather);
							grandfather->_color = READ;
							parent->_color = BLACK;
						}
						else {
							RotateR(parent);
							RotateL(grandfather);
							cur->_color = BLACK;
							grandfather->_color = READ;
							break;
						}
					}
				}
				cur = grandfather;
				parent = cur->_parent;
			}
			_root->_color = BLACK;
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
				if (parent->_data.first > left->_data.first) {
					parent->_left = left;
				}
				else
					parent->_right = left;
			}
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
				if (parent->_data.first > right->_data.first)
					parent->_left = right;
				else
					parent->_right = right;
			}
		}

		void _Inorder(Node* root) {
			if (root == nullptr)
				return;
			_Inorder(root->_left);
			cout << root->_data.first << ":" << root->_data.second << endl;
			_Inorder(root->_right);
		}
		void Inorder()
		{
			_Inorder(_root);
		}

		bool IsBalance()
		{
			//计算出黑节点的个数
			int datum = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_color == BLACK)
					datum++;
				cur = cur->_left;
			}
			return _IsBalance(_root, datum, 0);
		}

		bool _IsBalance(Node* root, int datum, int num)
		{
			if (root == nullptr) {
				if (datum != num) {
					cout << datum << ":" << num << endl;
					return false;
				}
				return true;
			}
			if (root->_parent&&root->_color == READ) {
				if (root->_parent->_color == READ) {
					cout << "出现连续的红节点" << endl;
				}
			}
			if (root->_color == BLACK)
				num++;
			return _IsBalance(root->_left, datum, num) && _IsBalance(root->_right, datum, num);
		}
	};
}