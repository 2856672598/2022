//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Gift
//{
//public:
//	int getValue(vector<int> gifts, int n)
//	{
//		sort(gifts.begin(), gifts.end());
//		int left = 0, right = n / 2;
//		while (right < n)
//		{
//			if (gifts[left] == gifts[right])
//				return gifts[left];
//			left++;
//			right++;
//		}
//		return 0;
//	}
//};
//int main()
//{
//	vector<int>nums{ 1,2,3,2,2 };
//	cout << Gift().getValue(nums, nums.size());
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
//	for (int i = 0; i <= s2.size(); i++)
//		dp[0][i] = i;
//	for (int i = 0; i <= s1.size(); i++)
//		dp[i][0] = i;
//
//	for (int i = 1; i <= s1.size(); i++)
//	{
//		for (int j = 1; j <= s2.size(); j++)
//		{
//			if (s1[i - 1] == s2[j - 1]) {
//				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
//			}
//			else {
//				dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
//			}
//		}
//	}
//	cout << dp[s1.size()][s2.size()];
//	return 0;
//}

//#include <iostream>
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
//class Solution
//{
//public:
//	string tree2str(TreeNode* root)
//	{
//		string ret;
//		if (nullptr == root)
//			return ret;
//		ret += to_string(root->val);
//		if (root->left || root->right){
//			ret += '(';
//			ret += tree2str(root->left);
//			ret += ')';
//		}
//		if (root->right){
//			ret += '(';
//			ret += tree2str(root->right);
//			ret += ')';
//		}
//		return ret;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
////class Solution {
////public:
////
////	TreeNode* _searchBST(TreeNode*root, int val)
////	{
////		if (nullptr == root)
////			return nullptr;
////		if (val == root->val) {
////			return root;
////		}
////		else if (val > root->val) {
////			return _searchBST(root->right, val);
////		}
////		else
////			return _searchBST(root->left, val);
////	}
////
////
////	TreeNode* searchBST(TreeNode* root, int val)
////	{
////		return   _searchBST(root, val);
////	}
////};
//
//class Solution {
//public:
//	TreeNode* deleteNode(TreeNode* root, int key)
//	{
//		TreeNode* cur = root, *parent = nullptr;
//		while (cur)
//		{
//			if (cur->val == key) {
//				//如果删除的节点只有一个孩子直接删除
//				if (cur->left == nullptr || cur->right == nullptr) {
//					if (cur == root){
//						if (cur->left == nullptr)
//							root = cur->right;
//						else
//							root = cur->left;
//					}
//					else if (cur->left == nullptr) {
//						if (cur == parent->left)
//							parent->left = cur->right;
//						else if (cur == parent->right)
//							parent->right = cur->right;
//					}
//					else {
//						if (cur == parent->left)
//							parent->left = cur->left;
//						else
//							parent->right = cur->left;
//					}
//					delete cur;
//					break;
//				}
//				else {
//					//替换删除-->找该节点左子树的最大节点
//					TreeNode* leftMax = cur->left;
//					TreeNode* leftMaxParent = cur;
//					while (leftMax->right)
//					{
//						leftMaxParent = leftMax;
//						leftMax = leftMax->right;
//					}
//
//					cur->val = leftMax->val;
//					//进行删除
//					if (leftMaxParent->left == leftMax) {
//						leftMaxParent->left = leftMax->left;
//					}
//					else {
//						leftMaxParent->right = leftMax->left;
//
//					}
//					delete leftMax;
//					break;
//				}
//			}
//			else if (cur->val > key) {
//				parent = cur;
//				cur = cur->left;
//			}
//			else {
//				parent = cur;
//				cur = cur->right;
//			}
//		}
//		return root;
//	}
//};

//#include <iostream>
//#include <stack>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution
//{
//public:
//
//	bool Find(TreeNode* root, TreeNode* target, stack<TreeNode*>&st)
//	{
//		if (root == nullptr)
//			return false;
//		st.push(root);
//		if (root == target || Find(root->left, target, st) || Find(root->right, target, st))
//			return true;
//		st.pop();
//		return false;
//	}
//
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//	{
//		stack<TreeNode*>st1, st2;
//		Find(root, p, st1);
//		Find(root, q, st2);
//
//		while (!st1.empty() && !st2.empty())
//		{
//			if (st1.size() > st2.size())
//				st1.pop();
//			else if (st1.size() < st2.size())
//				st2.pop();
//			else {
//				if (st1.top() == st2.top())
//					break;
//				st1.pop();
//				st2.pop();
//			}
//		}
//		return st1.top();
//	}
//};


//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
////class Solution {
////public:
////	vector<int> intersection(vector<vector<int>>& nums) {
////		unordered_map<int, int>m;
////		for (auto e : nums)
////		{
////			for (auto i : e)
////				m[i]++;
////		}
////		vector<int>ret;
////		for (auto e : m) {
////			if (e.second == nums.size())
////				ret.push_back(e.first);
////		}
////		sort(ret.begin(), ret.end());
////		return ret;
////	}
////};
//
//class Solution {
//public:
//
//	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons)
//	{
//		sort(flowers.begin(), flowers.end());
//		vector<int>ret;
//		unordered_map<int, int>m;
//		for (auto e : persons)
//			m[e] = 0;
//
//		for (auto& e : m)
//		{
//			int count = 0;
//			for (int j = 0; j < (int)flowers.size(); j++)
//			{
//				if (flowers[j][0] > e.first)
//					break;
//				if (flowers[j][0] <= e.first && e.first <= flowers[j][1])
//					count++;
//			}
//			e.second = count;
//		}
//		for (auto e : persons)
//			ret.push_back(m[e]);
//		return ret;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////class Bonus {
////public:
////	int getMost(vector<vector<int> > board)
////	{
////		for (int i = 1; i < (int)board.size(); i++)
////		{
////			board[i][0] += board[i - 1][0];
////			board[0][i] += board[0][i - 1];
////		}
////		for (int i = 1; i < (int)board.size(); i++)
////		{
////			for (int j = 1; j < (int)board[i].size(); j++)
////				board[i][j] += max(board[i - 1][j], board[i][j - 1]);
////		}
////		return board[board.size() - 1][board[0].size() - 1];
////	}
////};
//
//vector<vector<int>>ret;
//bool Dfs( vector<vector<int>>&nums, int row, int col)
//{
//	if (row == nums.size() - 1 && col == nums[0].size() - 1) {
//		ret.push_back({ row,col });
//		return true;
//	}
//	if (row < 0 || col < 0 || row == nums.size() || col == nums[0].size() || nums[row][col] == 1) {
//		return false;
//	}
//	ret.push_back({ row,col });
//	nums[row][col] = 1;
//	if (!Dfs(nums, row + 1, col) && !Dfs(nums, row - 1, col) && !Dfs(nums, row, col + 1) && !Dfs(nums, row, col - 1)) {
//		ret.pop_back();
//		nums[row][col] = 0;
//		return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>nums(n, vector<int>(m, 0));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cin >> nums[i][j];
//	}
//
//	Dfs(nums, 0, 0);
//	for (auto e : ret)
//		cout << "(" << e[0] << "," << e[1] << ")" << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string nums;
//	while (cin >> nums)
//	{
//		while (nums.size() > 1) {
//			long long tmp = 0;
//			for (auto e : nums) {
//				tmp += e - '0';
//			}
//			nums = to_string(tmp);
//		}
//		cout << nums << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int>nums(100000, 0);
//	nums[0] = 1;
//	nums[1] = 2;
//	for (int i = 2; i < 100000; i++) {
//		nums[i] = (nums[i - 1] + nums[i - 2]) % 10000;
//	}
//
//	int n;
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			int tmp = 0;
//			cin >> tmp;
//			int ret = nums[tmp - 1];
//			if (ret < 1000) {
//				printf("%04d", ret);
//			}
//			else {
//				cout << ret % 10000;
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//class Node {
//public:
//	int val;
//	Node* left;
//	Node* right;
//
//	Node() {}
//
//	Node(int _val) {
//		val = _val;
//		left = NULL;
//		right = NULL;
//	}
//
//	Node(int _val, Node* _left, Node* _right) {
//		val = _val;
//		left = _left;
//		right = _right;
//	}
//};
//
//class Solution {
//public:
//
//	void Inorder(Node* root, Node*& prev)
//	{
//		if (root == nullptr)
//			return;
//		Inorder(root->left, prev);
//
//		root->left = prev;
//		if (prev)
//			prev->right = root;
//		prev = root;
//		Inorder(root->right, prev);
//	}
//
//	Node* treeToDoublyList(Node* root) {
//		if (root == nullptr)
//			return nullptr;
//		Node* prev = nullptr;
//		Inorder(root, prev);
//		Node* cur = prev;
//		while (cur->left)
//			cur = cur->left;
//		cur->left = prev;
//		prev->right = cur;
//		return cur;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
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
////class Solution {
////public:
////	vector<int> preorderTraversal(TreeNode* root)
////	{
////		stack<TreeNode*>st;
////		if (root != nullptr)
////			st.push(root);
////		vector<int>ret;
////		while (!st.empty())
////		{
////			TreeNode* tmp = st.top();
////			ret.push_back(tmp->val);
////			st.pop();
////			if (tmp->right)
////				st.push(tmp->right);
////			if (tmp->left)
////				st.push(tmp->left);
////		}
////		return ret;
////	}
////};
//
//////中序
////class Solution {
////public:
////	vector<int> inorderTraversal(TreeNode* root)
////	{
////		stack<TreeNode*>st;
////		vector<int>ret;
////		TreeNode* cur = root;
////		while (cur || !st.empty())
////		{
////			//左子树走到底
////			while (cur)
////			{
////				st.push(cur);
////				cur = cur->left;
////			}
////
////			cur = st.top();
////			ret.push_back(cur->val);
////			st.pop();
////			//去右子树
////			cur = cur->right;
////		}
////		return ret;
////	}
////};
//
//////后序
////class Solution {
////public:
////	vector<int> postorderTraversal(TreeNode* root)
////	{
////		stack<TreeNode*>st;
////		vector<int>ret;
////		TreeNode* cur = root;
////		TreeNode* prev = nullptr;
////		while (cur || !st.empty())
////		{
////			while (cur)
////			{
////				st.push(cur);
////				cur = cur->left;
////			}
////			TreeNode* tmp = st.top();
////			//判断当前访问的是左子树还是右子树
////			if (tmp->right == nullptr || tmp->right == prev) {
////				ret.push_back(tmp->val);
////				st.pop();
////				prev = tmp;
////			}
////			else {
////				cur = tmp->right;
////			}
////		}
////		return ret;
////	}
////};
//
////class Solution {
////public:
////	vector<vector<int>> levelOrder(TreeNode* root)
////	{
////		queue<TreeNode*>q;
////		vector<vector<int>>ret;
////		if (root)
////			q.push(root);
////		while (!q.empty())
////		{
////			vector<int>tmp;
////			int sz = q.size();
////			for (int i = 0; i < sz; i++)
////			{
////				TreeNode* cur = q.front();
////				tmp.push_back(cur->val);
////				if (cur->left)
////					q.push(cur->left);
////				if (cur->right)
////					q.push(cur->right);
////				q.pop();
////			}
////			ret.push_back(tmp);
////		}
////		return ret;
////	}
////};
//
//class Solution {
//public:
//	bool Find(TreeNode* root, TreeNode* x)
//	{
//		if (root == nullptr)
//			return false;
//		if (root == x)
//			return true;
//		return Find(root->left, x) || Find(root->right, x);
//	}
//
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//	{
//		if (root == nullptr)
//			return nullptr;
//		if (root == p || root == q)
//			return root;
//		if (Find(root->left, p) && Find(root->right, q) || Find(root->left, q) && Find(root->right, p))
//			return root;
//
//		TreeNode* p1 = lowestCommonAncestor(root->left, p, q);
//		TreeNode* p2 = lowestCommonAncestor(root->right, p, q);
//		return p1 == nullptr ? p2 : p1;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//			val(x), left(NULL), right(NULL) {
//	}
//};
//
//class Solution {
//public:
//
//	TreeNode* _Convert(TreeNode* root, TreeNode*& prev)
//	{
//		if (root == nullptr)
//			return nullptr;
//
//		_Convert(root->left, prev);
//		root->left = prev;
//		if (prev)
//			prev->right = root;
//		prev = root;
//		_Convert(root->right, prev);
//		return prev;
//	}
//
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		if (pRootOfTree == nullptr)
//			return nullptr;
//		TreeNode* prev;
//		TreeNode* cur = _Convert(pRootOfTree, prev);
//		while (cur->left)
//			cur = cur->left;
//		return cur;
//	}
//
//};


#include <iostream>
using namespace std;
 
int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (2 * 3.14*r > n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
