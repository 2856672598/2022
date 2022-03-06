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
////	//根左右
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

//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	int mostFrequent(vector<int>& nums, int key) {
//		unordered_map<int, int>flag;
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			if (nums[i] == key && i + 1 < nums.size())
//				flag[nums[i + 1]]++;
//		}
//		int ret = flag.begin()->first;
//		for (auto e : flag)
//		{
//			if (e.second > flag[ret])
//				ret = e.first;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,100,200,1,100 };
//	int key = 1;
//	cout << Solution().mostFrequent(nums, key);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
//	{
//		map<int, vector<int>>flag;
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			string tmp = to_string(nums[i]);
//			int newnum = 0;
//			for (int j = 0; j < tmp.size(); j++)
//			{
//				newnum = newnum * 10 + mapping[tmp[j] - '0'];
//			}
//			flag[newnum].push_back(nums[i]);
//		}
//		vector<int>ret;
//		for (auto e : flag)
//		{
//			for (auto y : e.second)
//			{
//				ret.push_back(y);
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>mapping{ 8, 9, 4, 0, 2, 1, 3, 5, 7, 6 };
//	vector<int> nums{ 991,338,38 };
//	Solution().sortJumbled(mapping, nums);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution
//{
//public:
//	vector<string>ret;
//	void BackTracking(string& digits, string* arr, int index, string& tmp)
//	{
//		if (index == digits.size())
//		{
//			ret.push_back(tmp);
//			return;
//		}
//
//		for (int i = 0; i < arr[digits[index] - '0'].size(); i++)
//		{
//			tmp.push_back(arr[digits[index] - '0'][i]);
//			BackTracking(digits, arr, index + 1, tmp);
//			tmp.pop_back();
//		}
//	}
//
//	vector<string> letterCombinations(string digits)
//	{
//		if (digits.size() == 0)
//			return{};
//		string arr[10] = { " "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//		string tmp;
//		BackTracking(digits, arr, 0, tmp);
//		return ret;
//	}
//};


//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution
//{
//public:
//	int Check(const vector<int>&nums)
//	{
//		int result = 0;
//		for (auto& e : nums)
//		{
//			result ^= e;
//		}
//		return result;
//	}
//	vector<int> singleNumber(vector<int>& nums)
//	{
//		int tmp = Check(nums);
//		//找到二进制中第一个1的位置
//		unsigned flag = 1;
//		while ((tmp&flag) == 0)
//			flag = flag << 1;
//		vector<int>nums1, nums2;
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			if (nums[i] & flag)
//				nums1.push_back(nums[i]);
//			else
//				nums2.push_back(nums[i]);
//		}
//		return { Check(nums1),Check(nums2) };
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,2,1,3,2,5 };
//	Solution().singleNumber(nums);
//	return 0;
//}

//
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;

//class Solution {
//public:
//	vector<string> cellsInRange(string s)
//	{
//		int row = s[1] - '0';
//		vector<string>ret;
//		for (int i = s[0] - 'a'; i <= s[3] - 'a'; i++)
//		{
//			for (int j = row; j <= s[4] - '0'; j++)
//			{
//				string tmp;
//				tmp.push_back(i+'a');
//				tmp.push_back(j + '0');
//				ret.push_back(tmp);
//			}
//		}
//		return ret;
//	}
//};

//#include<unordered_set>
//class Solution {
//public:
//	long long minimalKSum(vector<int>& nums, int k) {
//		unordered_set<int>flag;
//		for (auto e : nums)
//		{
//			flag.insert(e);
//		}
//		long long sum = 0;
//		for (int i = 1; i <= 1e10; i++)
//		{
//			if (k == 0)
//				break;
//			if (flag.find(i) == flag.end())
//			{
//				k--;
//				sum += i;
//			}
//		}
//		return sum;
//	}
//};


//class Solution {
//public:
//	int gcd(int a, int b) {
//		if (a%b == 0) {
//			return b;
//		}
//		return gcd(b, a%b);
//	}
//
//	//vector<int> replaceNonCoprimes(vector<int>& nums)
//	//{
//	//	int begin = 1;
//	//	vector<int>ret;
//	//	while (begin < nums.size())
//	//	{
//	//		int tmp = gcd(nums[begin], nums[begin - 1]);
//	//		if (tmp > 1)
//	//		{
//	//			nums[begin] = nums[begin-1] / tmp * nums[begin];
//	//			begin++;
//	//		}
//	//		else
//	//		{
//	//			ret.push_back(nums[begin - 1]);
//	//			begin++;
//	//		}
//	//	}
//	//	ret.push_back(nums[nums.size() - 1]);
//	//	vector<int>target;
//	//	if (ret.size() != nums.size())
//	//	{
//	//		target = replaceNonCoprimes(ret);
//	//	}
//	//	return ret.size() == nums.size() ? ret : target;
//	//}
//
//	vector<int> replaceNonCoprimes(vector<int>& nums)
//	{
//		vector<int> ret(nums[0]);
//		for (int i = 1; i < nums.size(); i++)
//		{
//			while (ret.size() > 0 && gcd(nums[i], ret.back()) > 1)
//			{
//				nums[i] = nums[i - 1] / gcd(nums[i], nums[i - 1])*nums[i];
//				ret.pop_back();
//			}
//			ret.push_back(nums[i]);
//		}
//		return ret;
//	}
//};

//class Solution
//{
//public:
//	int gcd(int a, int b)
//	{
//		if (a%b == 0) {
//			return b;
//		}
//		return gcd(b, a%b);
//	}
//
//	vector<int> replaceNonCoprimes(vector<int>& nums)
//	{
//		vector<int> ret;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			while (ret.size() > 0 && gcd(nums[i], ret.back()) > 1)
//			{
//				nums[i] = nums[i] / gcd(nums[i], ret.back())*ret.back();
//				ret.pop_back();
//			}
//			ret.push_back(nums[i]);
//		}
//		return ret;
//	}
//};
//
