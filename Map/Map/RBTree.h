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
	template<class T>
	struct RBTreeNode
	{
		RBTreeNode* _left;
		RBTreeNode* _right;
		RBTreeNode* _parent;
		T _data;
		Color _color;

		RBTreeNode(const T& val)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(val)
			, _color(READ)
		{}
	};

	template<class T, class Ref, class Ptr>
	class RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef RBTreeIterator<T, Ref, Ptr> Self;
	public:
		Node* _p;
	public:
		RBTreeIterator(RBTreeNode<T>* node)
			:_p(node)
		{}

		Ref operator*()
		{
			return _p->_data;
		}

		Ptr operator->()
		{
			return &_p->_data;
		}

		bool operator!=(RBTreeIterator it)
		{
			return _p != it._p;
		}

		bool operator ==(RBTreeIterator it)const
		{
			return _p == it._p;
		}

		Self& operator++()
		{
			Node* cur = _p;
			Node* parent = cur->_parent;
			if (cur->_right) {
				cur = cur->_right;
				while (cur && cur->_left) {
					cur = cur->_left;
				}
			}
			else {
				while (parent && parent->_right == cur) {
					cur = parent;
					parent = parent->_parent;
				}
				cur = parent;
			}
			_p = cur;
			return *this;
		}

		Self& operator--()
		{
			if (_p->_left != nullptr) {
				Node* subR = _p->_left;
				while (subR->_right)
				{
					subR = subR->_right;
				}
				_p = subR;
			}
			else {
				Node* parent = _p->_parent;
				Node* cur = _p;
				while (parent && parent->_left = cur)
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
				_p = parent;
			}
			return *this;
		}
	};

	template<class K, class T, class GetK>
	class RBTree
	{
	public:
		typedef RBTreeNode<T> Node;
		typedef RBTreeIterator<T, const T&, T*> iterator;
		typedef RBTreeIterator<T, const T&, const T*> const_iterator;
	private:
		Node* _root;
		GetK _getk;//�ȽϷ���
	private:
		//�ҵ���
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
				if (_getk(parent->_data)> _getk(left->_data)) {
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
				if (_getk(parent->_data) > _getk(right->_data))
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
					cout << "���������ĺ�ڵ�" << endl;
				}
			}
			if (root->_color == BLACK)
				num++;
			return _IsBalance(root->_left, datum, num) && _IsBalance(root->_right, datum, num);
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* newNode = new Node(root->_data);
			newNode->_color = root->_color;
			newNode->_left = Copy(root->_left);
			newNode->_right = Copy(root->_right);
			//���Ӹ��ڵ�
			if (newNode->_left != nullptr) {
				newNode->_left->_parent = newNode;
			}
			if (newNode->_right != nullptr) {
				newNode->_right->_parent = newNode;
			}
			return newNode;
		}

		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

	public:
		RBTree()
			:_root(nullptr)
		{}

		~RBTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		RBTree(const RBTree<K, T, GetK>& tree)
		{
			//���
			_root = Copy(tree._root);
		}

		RBTree<K, T, GetK>& operator=(RBTree<K, T, GetK> tree)
		{
			swap(_root, tree._root);
			return *this;
		}

		pair<iterator,bool> Insert(const T& val)
		{
			if (_root == nullptr) {
				_root = new Node(val);
				_root->_color = BLACK;
				return{ iterator(_root),true };
			}
			//��������������Ѱ�Ҳ���λ��
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (_getk(cur->_data) > _getk(val))
					cur = cur->_left;
				else if (_getk(cur->_data) < _getk(val))
					cur = cur->_right;
				else
					return { iterator(cur),false };
			}
			Node* newNode = new Node(val);
			//�жϲ��������滹������
			if (_getk(parent->_data) > _getk(val)) {
				parent->_left = newNode;
				cur = parent->_left;
				cur->_parent = parent;
			}
			else {
				parent->_right = newNode;
				cur = parent->_right;
				cur->_parent = parent;
			}
			cur->_color = READ;

			//����ƽ��
			while (parent &&parent->_color == READ && parent != _root)
			{
				Node* grandfather = parent->_parent;
				Node* uncle = grandfather->_right;
				if (parent == grandfather->_right)
					uncle = grandfather->_left;

				//���������Ϊ��
				if (uncle && uncle->_color == READ) {
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = READ;
				}
				else
				{
					//���岻���ڻ�Ϊ��
					if (parent == grandfather->_left) {
						if (cur == parent->_left) {
							RotateR(grandfather);
							grandfather->_color = READ;
							parent->_color = BLACK;
						}
						else {
							//˫��
							RotateL(parent);
							RotateR(grandfather);
							cur->_color = BLACK;
							grandfather->_color = READ;
							break;
						}
					}
					else {
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
			return { iterator(newNode),true };
		}

		void Inorder()
		{
			_Inorder(_root);
		}

		bool IsBalance()
		{
			//������ڽڵ�ĸ���
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

		iterator Begin()
		{
			//����߽ڵ�
			Node* cur = _root;
			while (cur && cur->_left)
				cur = cur->_left;
			return iterator(cur);
		}

		iterator End()
		{
			return iterator(nullptr);
		}

		const_iterator cbegin()
		{
			return const_iterator(Begin()._p);
		}

		const_iterator cend()
		{
			return const_iterator(nullptr);
		}

		iterator Find(const K& val)
		{
			Node* cur = _root;
			while (cur)
			{
				if (_getk(cur->_data) > val)
					cur = cur->_left;
				else if (_getk(cur->_data) < val)
					cur = cur->_right;
				else
					return iterator(cur);
			}
			return End();
		}
	};
}