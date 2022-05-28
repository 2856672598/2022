//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//struct TreeNode
//{
//	char val;
//	struct TreeNode *lchild, *rchild;
//	TreeNode(char c) :val(c), lchild(NULL), rchild(NULL) {}
//};
//
//TreeNode* CreateTree(const string& str, int& pos) {
//	if (str[pos] == '#')
//		return NULL;
//	TreeNode *root = new TreeNode(str[pos]);
//	root->lchild = CreateTree(str, ++pos);
//	root->rchild = CreateTree(str, ++pos);
//	return root;
//}
//
//void InOrder(TreeNode* root)
//{
//	if (root == nullptr)
//		return;
//	InOrder(root->lchild);
//	cout << root->val;
//	InOrder(root->rchild);
//}
//
//void PostOrder(TreeNode* root)
//{
//	if (root == nullptr)
//		return;
//	PostOrder(root->lchild);
//	PostOrder(root->rchild);
//	cout << root->val;
//}
//
//void PrevOrder(TreeNode* root)
//{
//	if (root == nullptr)
//		return;
//	cout << root->val;
//	PrevOrder(root->lchild);
//	PrevOrder(root->rchild);
//}
//void LeveOrder(TreeNode* root)
//{
//	queue<TreeNode*>q;
//	q.push(root);
//	while (!q.empty())
//	{
//		int sz = q.size();
//		TreeNode* tmp = nullptr;
//		for (int i = 0; i < sz; i++)
//		{
//			tmp = q.front();
//			q.pop();
//			cout << tmp->val;
//			if (tmp->lchild)
//				q.push(tmp->lchild);
//			if (tmp->rchild)
//				q.push(tmp->rchild);
//		}
//	}
//	cout << endl;
//}
//
//void ShowByLayer(TreeNode* root, int layer)
//{
//	if (root->rchild)
//		ShowByLayer(root->rchild, layer + 1);
//	for (int i = 0; i < layer; i++)
//		cout << "     ";
//	cout<< root->val << std::endl;
//	if (root->lchild)
//		ShowByLayer(root->lchild, layer + 1);
//}
//
//int main() {
//	string str;
//	cin >> str;
//	int pos = 0;
//	TreeNode *root = CreateTree(str, pos);
//	PrevOrder(root);
//	cout << endl;
//	InOrder(root);
//	cout << endl;
//	PostOrder(root);
//	cout << endl;
//	LeveOrder(root);
//	ShowByLayer(root, 0);
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <string>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//TreeNode* _buildTree(vector<char>& preorder, vector<char>& inorder, int& index, int left, int right)
//{
//	if (index == preorder.size())
//		return nullptr;
//	TreeNode* node = new TreeNode(preorder[index]);
//	//判断下当前节点是否有左子树
//	int pos = 0;
//	for (int i = left; i <= right; i++)
//	{
//		if (inorder[i] == preorder[index]) {
//			pos = i;
//			break;
//		}
//	}
//	if (left < pos) {
//		index++;
//		node->left = _buildTree(preorder, inorder, index, left, pos - 1);
//	}
//	if (pos < right) {
//		index++;
//		node->right = _buildTree(preorder, inorder, index, pos + 1, right);
//	}
//	return node;
//}
//TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder) {
//	int left = 0, right = preorder.size() - 1, index = 0;
//	return _buildTree(preorder, inorder, index, left, right);
//}
//
//void PostOrder(TreeNode* root, vector<char>& arr)
//{
//	if (root == nullptr)
//		return;
//	PostOrder(root->left, arr);
//	PostOrder(root->right, arr);
//	arr.push_back(root->val);
//}
//
//int main()
//{
//	vector<char>preOrder;
//	vector<char>InOrder;
//	vector<char>post;
//	int n;
//	cin >> n;
//	string tmp;
//	stack<char>s;
//	for (int i = 0; i < 2 * n; i++)
//	{
//		cin >> tmp;
//		if (tmp == "push") {
//			char ch;
//			cin >> ch;
//			preOrder.push_back(ch);
//			s.push(ch);
//		}
//		else {
//			InOrder.push_back(s.top());
//			s.pop();
//		}
//	}
//	TreeNode* root = buildTree(preOrder, InOrder);
//
//	PostOrder(root, post);
//	for (int i = 0; i < post.size(); i++)
//	{
//		cout << post[i];
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
	char val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool flag = true;

TreeNode* _buildTree(string& preorder, string& inorder, int& index, int left, int right)
{
	if (index >= preorder.size())
		return nullptr;
	TreeNode* node = new TreeNode(preorder[index]);
	//判断下当前节点是否有左子树
	int pos = -1;
	for (int i = left; i <= right; i++)
	{
		if (inorder[i] == preorder[index]) {
			pos = i;
			break;
		}
	}
	if (pos == -1)
		flag = false;
	if (left < pos) {
		index++;
		node->left = _buildTree(preorder, inorder, index, left, pos - 1);
	}
	if (pos < right) {
		index++;
		node->right = _buildTree(preorder, inorder, index, pos + 1, right);
	}
	return node;
}
TreeNode* buildTree(string& preorder, string& inorder) {
	int left = 0, right = preorder.size() - 1, index = 0;
	return _buildTree(preorder, inorder, index, left, right);
}

void PostOrder(TreeNode* root)
{
	if (root == nullptr)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->val;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		flag = true;
		TreeNode* root = buildTree(str1, str2);
		if (flag) {
			PostOrder(root);
			cout << endl;
		}
		else
			cout << "Error" << endl;
	}
	return 0;
}