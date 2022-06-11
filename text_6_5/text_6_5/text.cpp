//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
////class Solution {
////public:
////	int minMaxGame(vector<int>& nums)
////	{
////		while (nums.size() != 1)
////		{
////			vector<int>newNums;
////			for (int i = 0; i < (int)nums.size() / 2; i++)
////			{
////				if (i % 2 == 0) {
////					newNums.push_back(min(nums[2 * i], nums[2 * i + 1]));
////				}
////				else
////					newNums.push_back(max(nums[2 * i], nums[2 * i + 1]));
////			}
////			nums = newNums;
////		}
////		return nums[0];
////	}
////};
//
////class Solution {
////public:
////	vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations)
////	{
////		unordered_map<int, int>m;
////		for (int i = 0; i < nums.size(); i++)
////			m.insert({ nums[i],i });
////		for (auto e : operations)
////		{
////			int  pos = m[e[0]];
////			int tmp = nums[pos];
////			nums[pos] = e[1];
////			m.erase(tmp);
////			m.insert({ e[1],pos });
////		}
////		return nums;
////	}
////};
//
//
//class Solution {
//public:
//	int partitionArray(vector<int>& nums, int k)
//	{
//		sort(nums.begin(), nums.end());
//		int ret = 1, min = nums[0];
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			if (nums[i] - min > k)
//			{
//				ret++;
//				min = nums[i];
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,2,3 };
//	int k = 1;
//	cout << Solution().partitionArray(nums, k);
//	return 0;
//}


//#include <iostream>
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
//class Solution {
//public:
//	int sum = 0;
//	TreeNode* convertBST(TreeNode* root)
//	{
//		//右左根
//		if (root == nullptr)
//			return nullptr;
//		convertBST(root->right);
//		sum += root->val;
//		root->val = sum;
//		convertBST(root->left);
//		return root;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost)
//	{
//		vector<int>nums(cost.size() + 1, 0);
//		for (size_t i = 2; i <= cost.size(); i++)
//		{
//			nums[i] = min(cost[i - 1] + nums[i - 1], cost[i - 2] + nums[i - 2]);
//		}
//		return nums[cost.size()];
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 10, 15, 20 };
//	cout << Solution().minCostClimbingStairs(nums);
//	return 0;
//}

//#include <iostream>
//#include <queue>
//using namespace std;
//
//class RecentCounter {
//	int count;
//	queue<int>_q;
//public:
//	RecentCounter() {
//		count = 0;
//	}
//
//	int ping(int t)
//	{
//		_q.push(t);
//		while (_q.front() + 3000 < t)
//			_q.pop();
//		return _q.size();
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////
////class Solution {
////public:
////	int minEatingSpeed(vector<int>& piles, int h)
////	{
////		size_t sum = 0;
////		for (auto e : piles)
////			sum += e;
////		int k = sum / h;
////		if (sum%h)
////			k = 1;
////		if (h == piles.size())
////			k = *max_element(piles.begin(), piles.end());
////		else {
////			while (k)
////			{
////				int count = 0;
////				for (int i = 0; i < piles.size(); i++)
////				{
////					if (count > h)
////						break;
////					count += piles[i] / k;
////					if (piles[i] % k)
////						count += 1;
////				}
////				if (count <= h)
////					break;
////				k++;
////			}
////		}
////		return  k;
////	}
////};
//
//class Solution {
//public:
//
//	int GetTime(vector<int>& piles, int k)
//	{
//		int ti = 0;
//		for (auto e : piles)
//		{
//			ti += e / k;
//			if (e%k)
//				ti += 1;
//		}
//		return ti;
//	}
//
//	int minEatingSpeed(vector<int>& piles, int h) {
//		int left = 1, right = *max_element(piles.begin(), piles.end());
//		int ret = right;
//		while (left < right)
//		{
//			int mid = left + (right - left) / 2;
//			int ti = GetTime(piles, mid);
//			if (ti <= h) {
//				ret = mid;
//				right = mid;
//			}
//			else
//				left = mid + 1;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 30,11,23,4,20 };
//	int h = 5;
//	cout << Solution().minEatingSpeed(nums, h);
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	bool Palindrome(const string&str, int left, int right)
//	{
//		while (left < right)
//		{
//			if (str[left++] != str[right--])
//				return false;
//		}
//		return true;
//	}
//
//	vector<string>tmp;
//	void Backtracking(const string& s,int index,vector<vector<string>>& ret)
//	{
//		if (index == s.size()) {
//			ret.push_back(tmp);
//		}
//		for (int i = index; i < (int)s.size(); i++)
//		{
//			//判断当前子串是否是回文
//			if (Palindrome(s, index, i)) {
//				tmp.push_back(s.substr(index, i - index + 1));
//				Backtracking(s, i + 1, ret);
//			}
//			else
//				continue;
//			tmp.pop_back();
//		}
//	}
//
//	vector<vector<string>> partition(string s) {
//		vector<vector<string>>ret;
//		Backtracking(s, 0, ret);
//		return ret;
//	}
//};


//#include <iostream>
//#include <vector>
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
//class CBTInserter {
//public:
//	vector<TreeNode*>numb;
//	CBTInserter(TreeNode* root) {
//		queue<TreeNode*>q;
//		TreeNode* cur = nullptr;
//		q.push(root);
//		while (!q.empty())
//		{
//			int sz = q.size();
//			for (int i = 0; i < sz; i++)
//			{
//				cur = q.front();
//				q.pop();
//				numb.push_back(cur);
//				if (cur->left)
//					q.push(cur->left);
//				if (cur->right)
//					q.push(cur->right);
//			}
//		}
//	}
//
//	int insert(int v) {
//		TreeNode* newNode = new TreeNode(v);
//		numb.push_back(newNode);
//		int cur = numb.size() - 2;
//		int parent = cur / 2;
//		if (cur % 2)
//			numb[parent]->right = newNode;
//		else
//			numb[parent]->left = newNode;
//		return numb[parent]->val;
//	}
//
//	TreeNode* get_root() {
//		return numb[0];
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
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
//class Solution {
//public:
//	void InOrder(TreeNode* root, vector<int>& nums)
//	{
//		if (root == nullptr)
//			return;
//		InOrder(root->left, nums);
//		nums.push_back(root->val);
//		InOrder(root->right, nums);
//	}
//
//	bool isValidBST(TreeNode* root) {
//		vector<int>nums;
//		InOrder(root, nums);
//		for (int i = 1; i < (int)nums.size(); i++)
//		{
//			if(nums[i] == nums[i - 1] || nums[i] < nums[i - 1])
//				return false;
//		}
//		return true;
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
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
////class Solution {
////public:
////	TreeNode* pruneTree(TreeNode* root) {
////		if (root == nullptr)
////			return nullptr;
////		root->left = pruneTree(root->left);
////		root->right = pruneTree(root->right);
////		if (root->val == 0 && root->left == nullptr&&root->right == nullptr)
////			return nullptr;
////		return root;
////	}
////};
//
//class Solution {
//public:
//	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
//	{
//		stack<TreeNode*>s;
//		TreeNode* cur = root, *prev = nullptr;
//		while (!s.empty() || cur)
//		{
//			while (cur) {
//				s.push(cur);
//				cur = cur->left;
//			}
//			cur = s.top();
//			s.pop();
//			if (prev == p)
//				break;
//			prev = cur;
//			cur = cur->right;
//		}
//		return cur;
//	}
//};


//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//
//	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//
//		if (nums1.size() == 0 || nums2.size() == 0 || k == 0)
//			return{};
//
//		auto compar = [&](pair<int, int> x, pair<int, int> y)->bool {
//			return (nums1[x.first] + nums2[x.second]) > (nums1[y.first] + nums2[y.second]);
//		};
//		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compar)> q(compar);
//		for (int i = 0; i < min((int)nums1.size(), k); i++)
//		{
//			q.push({ i,0 });
//		}
//		vector<vector<int>>ret;
//		int i = 1;
//		while (k--)
//		{
//			pair<int, int>tmp = q.top();
//			ret.push_back({ nums1[tmp.first] ,nums2[tmp.second] });
//			q.pop();
//			if (tmp.second + 1 < (int)nums2.size())
//			{
//				q.push({ tmp.first,tmp.second + 1 });
//			}
//		}
//		return ret;
//	}
//};
//
//int  main()
//{
//	vector<int>nums1{ 1,7,11 };
//	vector<int>nums2{ 2,4,6 };
//	int k = 3;
//	Solution().kSmallestPairs(nums1, nums2, k);
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//int arr[100][100], ret[100][100];
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cin >> arr[i][j];
//	}
//	ret[0][0] = arr[0][0];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i == 0 && j != 0)
//				ret[i][j] = ret[i][j - 1] + arr[i][j];
//			else if (j == 0 && i != 0)
//				ret[i][j] = ret[i - 1][j] + arr[i][j];
//			else
//				ret[i][j] = min(ret[i - 1][j], ret[i][j - 1]) + arr[i][j];
//		}
//	}
//	cout << ret[n - 1][n - 1];
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int duplicateInArray(vector<int>& nums) {
//		if (nums.size() == 0)
//			return -1;
//		sort(nums.begin(), nums.end());
//		if (nums[0] < 0 || nums[nums.size() - 1] >= nums.size())
//			return -1;
//		for (int i = 1; i < (int)nums.size(); i++)
//		{
//			if (nums[i] == nums[i - 1])
//				return nums[i];
//		}
//		return -1;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 3, 1, -10, 1, 1, 4, 3, 10, 1, 1 };
//	cout << Solution().duplicateInArray(nums);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int minFlipsMonoIncr(string s) {
//		int n = s.size();
//		vector<int>sum(n + 1, 0);
//		for (int i = 0; i < n; i++)
//			sum[i + 1] = sum[i] + s[i] - '0';
//		int ret = INT_MAX;
//		for (int i = 0; i <= n; i++)
//		{
//			ret = min(ret, sum[i] + n - i - (sum[n] - sum[i]));
//		}
//		return ret;
//	}
//};

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	bool digitCount(string num) {
//		int arr[10] = { 0 };
//		for (int i = 0; i < (int)num.size(); i++)
//			arr[num[i] - '0']++;
//		for (int i = 0; i < (int)num.size(); i++)
//		{
//			if (arr[i] != num[i] - '0')
//				return false;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	string num = "030";
//	cout << Solution().digitCount(num);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//	string largestWordCount(vector<string>& messages, vector<string>& senders)
//	{
//		unordered_map<string, int>m;
//		for (int i = 0; i < (int)messages.size(); i++)
//		{
//			m[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
//		}
//		string ret = senders[0];
//		for (const auto& e : m)
//		{
//			if (e.second > m[ret])
//				ret = e.first;
//			else if (e.second == m[ret] && e.first > ret)
//				ret = e.first;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>messages{ "Hello userTwooo","Hi userThree"
//		,"Wonderful day Alice","Nice day userThree" };
//	vector<string>senders{ "Alice","userTwo","userThree","Alice" };
//	cout << Solution().largestWordCount(messages, senders);
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
	bool _isWord;
	vector<Node*>_child;
	Node()
		:_isWord(false)
		, _child(26, nullptr)
	{}
};

class Solution {
	Node* root = nullptr;
public:
	void CreateTree(const vector<string>& dictionary)
	{
		if (root == nullptr)
			root = new Node();
		for (int i = 0; i < (int)dictionary.size(); i++)
		{
			Node* tmp = root;
			for (auto e : dictionary[i]) {
				if (tmp->_child[e - 'a'] == nullptr)
					tmp->_child[e - 'a'] = new Node;
				tmp = tmp->_child[e - 'a'];
			}
			tmp->_isWord = true;
		}
	}

	string Find(const string& word)
	{
		Node* cur = root;
		string ret;
		for (auto e : word)
		{
			if (cur->_child[e - 'a']) {
				ret += e;
				cur = cur->_child[e - 'a'];
			}
			else
				return {};
			if (cur->_isWord)
				break;
		}
		return ret;
	}

	string replaceWords(vector<string>& dictionary, string sentence) {
		stringstream ss(sentence);
		CreateTree(dictionary);
		string tmp, ret;
		while (ss >> tmp)
		{
			string res = Find(tmp);
			if (res.size() == 0)
				ret += tmp;
			else
				ret += res;
			ret += " ";
		}
		return ret.substr(0, ret.size() - 1);
	}
};

int main()
{
	vector<string>dictionary{ "cat","bat","rat" };
	string sentence{ "the cattle was rattled by the battery" };
	Solution().replaceWords(dictionary, sentence);
	return 0;
}