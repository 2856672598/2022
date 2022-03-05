//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> Month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int ans = 6, ret = 2, month = 12;
//	for (int i = 2000; i <= 2020; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
//			Month[1] = 29;
//		else
//			Month[1] = 28;
//		if (i == 2020)
//			month = 9;
//		else
//			month = 12;
//		for (int j = 0; j < month; j++)
//		{
//			for (int z = 1; z <= Month[j]; z++)
//			{
//				if (z == 1 || ans == 1)
//					ret += 1;
//				ans++;
//				ans %= 7;
//			}
//			ret += Month[j];
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Solution
//{
//public:
//	int addDigits(int num)
//	{
//		if (num < 10)
//			return num;
//		int ret = 0;
//		while (num)
//		{
//			ret += num % 10;
//			num /= 10;
//		}
//		return addDigits(ret);
//	}
//};
//
//int main()
//{
//	cout << Solution().addDigits(38);
//	return 0;
//}


//#include<iostream>
//#include<queue>
//using namespace std;
//
//class Node {
//public:
//	int val;
//	Node* left;
//	Node* right;
//	Node* next;
//
//	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//
//	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//
//	Node(int _val, Node* _left, Node* _right, Node* _next)
//		: val(_val), left(_left), right(_right), next(_next) {}
//};
//
//class Solution {
//public:
//	Node* connect(Node* root)
//	{
//		if (root == nullptr)
//			return nullptr;
//		queue<Node*>q;
//		q.push(root);
//		while (!q.empty())
//		{
//			int size = q.size();
//			Node* prev = nullptr, *cur = nullptr;
//			for (int i = 0; i < size; i++)
//			{
//				prev = cur;
//				cur = q.front();
//				q.pop();
//				if (cur->left != nullptr)
//					q.push(cur->left);
//				if (cur->right != nullptr)
//					q.push(cur->right);
//				if (i > 0)
//				{
//					prev->next = cur;
//				}
//			}
//		}
//		return root;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>nums(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//	}
//	sort(nums.begin(), nums.end());
//	int gap = nums[n - 1] - nums[0];
//	for (int i = 1; i < n; i++)
//	{
//		gap = min(gap, nums[i] - nums[i - 1]);
//	}
//	if (gap == 0)
//		cout << n << endl;
//	else
//		cout << (nums[n - 1] - nums[0]) / gap + 1 << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//
//class Solution
//{
//public:
//	bool wordBreak(string s, vector<string>& wordDict)
//	{
//		unordered_set<string>flag;
//		for (auto e : wordDict)
//			flag.insert(e);
//
//		vector<bool>dp(s.size() + 1);
//		dp[0] = true;
//		for (int i = 1; i <= s.size(); i++)
//		{
//			for (int j = 0; j < i; j++)
//			{
//				if (dp[j] && flag.find(s.substr(j, i - j)) != flag.end())
//				{
//					dp[i] = true;
//					break;
//				}
//			}
//		}
//		return dp[s.size()];
//	}
//};
//
//int main()
//{
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS 
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using std::swap;
//
//class string
//{
//public:
//	string(const char* str = "")
//		:_str(nullptr)
//		, _capacity(strlen(str))
//		, _size(0)
//	{
//		_str = new char[_capacity + 1];
//		_str[_capacity] = '\0';
//		strcpy(_str, str);
//		_size = _capacity;
//	}
//
//	//string(const string& s)
//	//	:_str(nullptr)
//	//{
//	//	char* tmp = new char[s._size + 1];
//	//	strcpy(tmp, s._str);
//	//	_size = s._size;
//	//	_capacity = s._capacity;
//	//}
//	string(const string& s)
//		:_str(nullptr)
//	{
//		string tmp(s._str);
//		swap(tmp._str, _str);
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//	
//	string& operator= (const string& s)
//	{
//		string tmp(s);
//		swap(tmp._str, _str);
//		_size = s._size;
//		_capacity = s._capacity;
//		return *this;
//	}
//
//	~string()
//	{
//		delete[] _str;
//		_size = _capacity = 0;
//	}
//private:
//	char* _str;
//	size_t _capacity;
//	size_t _size;
//};
//
//int main()
//{
//	string s1("hello");
//	string s2(s1);
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
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
////class Solution
////{
////	int sum = 0;
////public:
////	//¸ù×óÓÒ
////	void Preorder(TreeNode* root, int tmp)
////	{
////		if (root->left == root->right&&root->left == nullptr)
////		{
////			sum += tmp * 10 + root->val;
////			return;
////		}
////		if (root->left != nullptr)
////			Preorder(root->left, tmp * 10 + root->val);
////		if (root->right != nullptr)
////			Preorder(root->right, tmp * 10 + root->val);
////	}
////
////	int sumNumbers(TreeNode* root)
////	{
////		if (root == nullptr)
////			return 0;
////		Preorder(root, 0);
////		return sum;
////	}
////};
//
//
//class Solution {
//public:
//	void Preorder(TreeNode* root, int& sum)
//	{
//		if (root == nullptr)
//			return;
//		if (root->left && root->left->left == nullptr&&root->left->right == nullptr)
//		{
//			sum += root->left->val;
//		}
//		if (root->left)
//			Preorder(root->left, sum);
//		if (root->right)
//			Preorder(root->right, sum);
//	}
//
//	int sumOfLeftLeaves(TreeNode* root)
//	{
//		int sum = 0;
//		Preorder(root, sum);
//		return sum;
//	}
//};

