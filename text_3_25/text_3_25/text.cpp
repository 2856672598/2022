//#include <unordered_set>
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	string longestWord(vector<string>& words) {
//		sort(words.begin(), words.end(), [](const string& x, const string y)
//		{
//			return x.size() != y.size() ? x.size() < y.size() : x > y;
//		});
//		unordered_set<string>s{ "" };
//		string ret;
//		for (const auto& e : words)
//		{
//			string tmp = e.substr(0, e.size() - 1);
//			if (s.find(tmp) != s.end()) {
//				s.insert(e);
//				ret = e;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>words{ "ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o" };
//	cout << Solution().longestWord(words);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<vector<int>>nums(m, vector<int>(n, 1));
//	int ret = 0;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (nums[i][j] == 1){
//				if (i + 2 < m)
//					nums[i + 2][j] = 0;
//				if (j + 2 < n)
//					nums[i][j+2] = 0;
//			}
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (nums[i][j] == 1)
//				ret++;
//		}
//	}
//	cout << ret;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	int StrToInt(string str) {
//		int flag = 1;
//		int i = 0;
//		long long ret = 0;
//		if (str[0] == '-' || str[0] == '+') {
//			if (str[0] == '-')
//				flag = -1;
//			i++;
//		}
//
//		for (i; i < (int)str.size(); i++)
//		{
//			if (isdigit(str[i]) == false)
//				return 0;
//			ret = ret * 10 + (str[i] - '0')*flag;
//			if (ret > INT_MAX || ret < INT_MIN) {
//				ret = 0;
//				break;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string str("-2147483649");
//	cout << Solution().StrToInt(str);
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int ret = 0;
//	for (int i = 0; i <= (int)s1.size(); i++)
//	{
//		string tmp = s1;
//		tmp.insert(i, s2);
//		int left = 0, right = tmp.size() - 1;
//		int flag = 1;
//		while (left < right)
//		{
//			if (tmp[left++] != tmp[right--]){
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//			ret++;
//	}
//	cout << ret << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>nums(n);
//	for (int i = 0; i < n; i++)
//		cin >> nums[i];
//	vector<long long>ret(n, 0);
//	ret[0] = nums[0];
//	for (int i = 1; i < n; i++)
//	{
//		ret[i] = max((long long)nums[i], ret[i - 1] + nums[i]);
//	}
//	cout << *max_element(ret.begin(), ret.end()) << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	bool checkAlmostEquivalent(string word1, string word2) {
//		vector<int>flag(26, 0);
//		for (int i = 0; i < (int)word1.size(); i++)
//		{
//			flag[word1[i] - 'a']++;
//			flag[word2[i] - 'a']--;
//		}
//		for (const auto& e : flag)
//		{
//			if (abs(e) > 3)
//				return false;
//		}
//		return true;
//	}
//};

////字典树
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Trie
//{
//public:
//	Trie()
//	{
//		_child.resize(26, nullptr);
//		_isend = false;
//	}
//
//	void insert(const string& word)
//	{
//		Trie* cur = this;
//		for (const char& e : word)
//		{
//			if (cur->_child[e - 'a'] == nullptr) {
//				cur->_child[e - 'a'] = new Trie;
//			}
//			cur = cur->_child[e - 'a'];
//		}
//		cur->_isend = true;
//	}
//
//	bool search(string word) {
//		Trie* cur = this;
//		for (const char& e : word)
//		{
//			if (cur->_child[e - 'a'] == nullptr)
//				return false;
//			cur = cur->_child[e - 'a'];
//		}
//		return cur->_isend == true ? true : false;
//	}
//
//	bool startsWith(string prefix)
//	{
//		Trie* cur = this;
//		for (const char& e : prefix)
//		{
//			if (cur->_child[e - 'a'] == nullptr)
//				return false;
//			cur = cur->_child[e - 'a'];
//		}
//		return true;
//	}
//private:
//	vector<Trie*>_child;
//	bool _isend;
//};
//
//int main()
//{
//	Trie trie;
//	trie.insert("hello");
//	trie.insert("helloworld");
//	cout << trie.search("hello") << endl;
//	cout << trie.search("helloworld") << endl;
//	cout << trie.startsWith("helli") << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class WordDictionary
//{
//	struct node
//	{
//		vector<node*>_child;
//		bool _isend;
//		node()
//			:_child(26, nullptr)
//			, _isend(false)
//		{}
//	};
//private:
//	node* _child;
//public:
//	WordDictionary()
//		:_child(new node)
//	{}
//
//	void addWord(string word)
//	{
//		node* cur = _child;
//		for (const char& ch : word)
//		{
//			if (cur->_child[ch - 'a'] == nullptr)
//				cur->_child[ch - 'a'] = new node;
//			cur = cur->_child[ch - 'a'];
//		}
//		cur->_isend = true;
//	}
//
//	bool backtracking(const string& word, node* cur, int index)
//	{
//		if (index == word.size())
//			return cur->_isend == true ? true : false;
//		if (word[index] == '.') {
//			node* next = nullptr;
//			for (int i = 0; i < (int)cur->_child.size(); i++)
//			{
//				next = cur->_child[i];
//				if (next != nullptr&&backtracking(word, next, index + 1))
//					return true;
//			}
//		}
//		else {
//			node* next = cur->_child[word[index] - 'a'];
//			if (next != nullptr&&backtracking(word, next, index + 1))
//				return true;
//		}
//		return false;
//	}
//
//	bool search(string word)
//	{
//		return backtracking(word, _child, 0);
//	}
//};


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Trie
//{
//	struct Node
//	{
//		vector<Node*>_child;
//		bool _isend;
//		Node()
//			:_child(26, nullptr)
//			, _isend(false)
//		{}
//	};
//
//public:
//	Trie()
//		:_root(new Node)
//	{}
//	void insert(const string& word)
//	{
//		Node* cur = _root;
//		for (const auto& e : word)
//		{
//			if (cur->_child[e - 'a'] == nullptr)
//				cur->_child[e - 'a'] = new Node;
//			cur = cur->_child[e - 'a'];
//		}
//		cur->_isend = true;
//	}
//
//	bool check(const string& word)
//	{
//		Node* cur = _root;
//		for (const auto& e : word)
//		{
//			if (cur->_child[e - 'a'] == nullptr)
//				return false;
//			if (cur->_child[e - 'a']->_isend == false)
//				return false;
//			cur = cur->_child[e - 'a'];
//		}
//		return true;
//	}
//private:
//	Node* _root;
//};
//
//class Solution
//{
//public:
//	string longestWord(vector<string>& words) {
//		Trie root;
//		for (const string &e : words)
//		{
//			root.insert(e);
//		}
//		string ret = "";
//		for (const string &e : words)
//		{
//			if (root.check(e)) {
//				if (ret.size() < e.size() || (ret.size() == e.size() && ret > e))
//					ret = e;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>words{ "a", "banana", "app", "appl", "ap", "apply", "apple" };
//	cout << Solution().longestWord(words);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
////class Solution {
////public:
////	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
////		unordered_set<int>flag1, flag2;
////		for (auto e : nums1)
////			flag1.insert(e);
////		for (auto e : nums2)
////			flag2.insert(e);
////
////		vector<vector<int>>ret;
////		vector<int>tmp;
////		for (auto e : flag1)
////		{
////			if (flag2.find(e) == flag2.end())
////				tmp.push_back(e);
////		}
////		ret.push_back(tmp);
////		tmp.resize(0);
////		for (auto e : flag2)
////		{
////			if (flag1.find(e) == flag1.end())
////				tmp.push_back(e);
////		}
////		ret.push_back(tmp);
////		return ret;
////	}
////};
//
////class Solution {
////public:
////	int minDeletion(vector<int>& nums) {
////		stack<int> s;
////		s.push(nums[0]);
////		int i = 1;
////		while (i < (int)nums.size())
////		{
////			while (i < (int)nums.size() && (s.size() - 1) % 2 == 0 && s.top() == nums[i])
////				i++;
////			if (i < (int)nums.size())
////				s.push(nums[i]);
////			i++;
////		}
////		if (s.size() % 2)
////			s.pop();
////		return nums.size() - s.size();
////	}
////};
////int main()
////{
////	vector<int>nums{ 1,1,2,2,3,3 };
////	cout << Solution().minDeletion(nums);
////	return 0;
////}
//
//class Solution {
//public:
//	vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
//		vector<long long>nums;
//		for (long long i = (long long)pow(10, intLength - 1); i < (long long)pow(10, intLength); i++)
//		{
//			string tmp = to_string(i);
//			int left = 0, right = tmp.size() - 1;
//			int flag = 1;
//			while (left < right)
//			{
//				if (tmp[left++] != tmp[right--]) {
//					flag = 0;
//					break;
//				}
//			}
//			if (flag)
//				nums.push_back(i);
//		}
//		vector<long long>ret(queries.size(), -1);
//		for (int i = 0; i < (int)queries.size(); i++)
//		{
//			if (queries[i] - 1 < nums.size())
//				ret[i] = nums[queries[i] - 1];
//		}
//		return ret;
//	}
//};


//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <sstream>
//using namespace std;
//
//class Solution {
//public:
//	vector<string> uncommonFromSentences(string s1, string s2) {
//		unordered_map<string, int>m;
//		auto insert = [&](const string& s)
//		{
//			stringstream tmp(s);
//			string word;
//			while (tmp >> word)
//			{
//				++m[word];
//			}
//		};
//		insert(s1);
//		insert(s2);
//		vector<string>ret;
//		for (const auto&e : m)
//		{
//			if (e.second == 1)
//				ret.push_back(e.first);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string s1 = "this apple is sweet";
//	string s2 = "this apple is sour";
//	Solution().uncommonFromSentences(s1, s2);
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	long long arr[2] = { 0,1 };
//	long long cur = 0;
//	while (cur < n)
//	{
//		cur = arr[0] + arr[1];
//		arr[0] = arr[1];
//		arr[1] = cur;
//	}
//	cout << min(n - arr[0], cur - n) << endl;
//	return 0;
//}

//#include <stack>
//#include <string>
//#include <iostream>
//using namespace std;
//
//class Parenthesis
//{
//public:
//	bool chkParenthesis(string A, int n)
//	{
//		if (n % 2)
//			return false;
//		stack<char>s;
//		int i = 0;
//		while (i < n)
//		{
//			if (!(A[i] == '(' || A[i] == ')'))
//				return false;
//			if (s.empty()) {
//				if (A[i] != '(')
//					return false;
//				s.push(A[i]);
//			}
//			else {
//				if (s.top() == A[i])
//					s.push(A[i]);
//				else
//					s.pop();
//			}
//			i++;
//		}
//		return s.empty();
//	}
//};
//
//int main()
//{
//	string str = "(()())";
//	int n = 6;
//	cout << Parenthesis().chkParenthesis(str, n);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <unordered_map>
//#include <functional>
//using namespace std;
//
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int>s;
//		int i = 0;
//		unordered_map<string, function<void()>>flag{
//			{"+",[&]() {int num = s.top(); s.pop(); s.top() += num; }},
//			{"-",[&]() {int num = s.top(); s.pop(); s.top() -= num; }},
//			{"*",[&]() {int num = s.top(); s.pop(); s.top() *= num; }},
//			{"/",[&]() {int num = s.top(); s.pop(); s.top() /= num; }}
//
//		};
//		while (i < (int)tokens.size())
//		{
//			if (flag.find(tokens[i]) != flag.end()) {
//				flag[tokens[i]]();
//			}
//			else
//				s.push(stoi(tokens[i]));
//			i++;
//		}
//		return s.top();
//	}
//};
//
//int main()
//{
//	vector<string>tokens{ "2","1","+","3","*" };
//	cout << Solution().evalRPN(tokens);
//	return 0;
//}


//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		stack<int>s;
//		int i = 0, j = 0;
//		while (i < pushV.size())
//		{
//			s.push(pushV[i]);
//			while (!s.empty() && s.top() == popV[j])
//			{
//				s.pop();
//				j++;
//			}
//			i++;
//		}
//		return !s.empty() || j < popV.size() ? false : true;
//	}
//};

//#include <iostream>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
//class MinStack {
//private:
//	stack<pair<int, int>>s;
//public:
//	MinStack() {
//
//	}
//
//	void push(int val) {
//		int tmp = 0;
//		if (s.empty())
//			tmp = val;
//		else
//			tmp = s.top().second;
//		tmp = min(tmp, val);
//		s.push({ val,tmp });
//	}
//
//	void pop() {
//		s.pop();
//	}
//
//	int top() {
//		return s.top().first;
//	}
//
//	int getMin() {
//		return s.top().second;
//	}
//};


//#include <iostream>
//#include <memory>
//#include <string>
//#include <functional>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	~Date()
//	{
//		cout << "~Date" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//shared_ptr<Date> p(new Date[10]);
//	function<void(Date*)> del = [](Date* ptr) {delete[] ptr; };
//	//传入自己的删除器。
//	shared_ptr<Date> p(new Date[10], del);
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n) {
		unsigned int tmp = n;
		vector<int>nums;
		while (n)
		{
			nums.push_back(n & 1);
			n >>= 1;
		}
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1])
				return false;
		}
		return true;
	}
}; 