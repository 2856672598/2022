//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//		int ret = 0;
//		int  prev = timeSeries[0] + duration;
//		for (int i = 1; i < timeSeries.size(); i++)
//		{
//			int right = timeSeries[i] + duration;//右区间
//			if (prev >= timeSeries[i]) {
//				ret += right - prev;
//			}
//			else {
//				ret += duration;
//			}
//			prev = right;
//		}
//		return ret + duration;
//	}
//};
//
//int main()
//{
//	vector<int>timeSeries{ 1,4,6,9,10 };
//	int duration = 2;
//	cout << Solution().findPoisonedDuration(timeSeries, duration);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	int findLHS(vector<int>& nums) {
//		unordered_map<int, int>m;
//		for (const auto&e : nums)
//			m[e]++;
//		int ret = 0;
//		for (const auto& e : m)
//		{
//			int tmp = 0;
//			auto it = m.find(e.first + 1);
//			if (it != m.end())
//				tmp = it->second;
//			it = m.find(e.first - 1);
//			if (it != m.end())
//				tmp = max(tmp, it->second);
//			if (tmp != 0)
//				ret = max(ret, tmp + e.second);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
////class Solution {
////public:
////	vector<int> buildArray(vector<int>& nums) {
////		vector<int>ret(nums.size(), 0);
////		for (int i = 0; i < (int)nums.size(); i++)
////		{
////			ret[i] = nums[nums[i]];
////		}
////		return ret;
////	}
////
////};
//
//
////class Solution {
////public:
////	bool Check(const string& s1, const string& s2)
////	{
////		int arr[26] = { 0 };
////		for (auto e : s1)
////			arr[e - 'a']++;
////		for (auto e : s2)
////		{
////			if (arr[e - 'a'])
////				return false;
////		}
////		return true;
////	}
////
////	int maxProduct(vector<string>& words) {
////		int ret = 0;
////		for (int i = 0; i < (int)words.size(); i++)
////		{
////			for (int j = i + 1; j < (int)words.size(); j++)
////			{
////				if (Check(words[i], words[j]))
////					ret = max((size_t)ret, words[i].size()*words[j].size());
////			}
////		}
////		return ret;
////	}
////};
//
//class Solution {
//public:
//	int maxProduct(vector<string>& words) {
//		vector<int>nums(words.size(), 0);
//		for (size_t i = 0; i < words.size(); i++)
//		{
//			int tmp = 0;
//			for (size_t j = 0; j < words[i].size(); j++)
//			{
//				int flag = words[i][j] - 'a';
//				tmp |= 1 << flag;
//			}
//			nums[i] = tmp;
//		}
//		int ret = 0;
//		for (size_t i = 0; i < words.size(); i++)
//		{
//			for (size_t j = i + 1; j < words.size(); j++)
//			{
//				//当等于0时说明没有公共字母
//				if ((nums[i] & nums[j]) == 0)
//					ret = max(ret, (int)(words[i].size()*words[j].size()));
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>words{ "abcw","baz","foo","bar","xtfn","abcdef" };
//	cout << Solution().maxProduct(words);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	bool Check(string s1, string s2)
//	{
//		int arr[2] = { 0 };
//		int index = 0;
//		for (int i = 0; i < (int)s1.size(); i++)
//		{
//			if (s1[i] != s2[i]) {
//				arr[index++] = i;
//			}
//			if (index == 2)
//				break;
//		}
//		char ch = s1[arr[0]];
//		s1[arr[0]] = s1[arr[1]];
//		s1[arr[1]] = ch;
//		return s1 == s2;
//	}
//
//	int numSimilarGroups(vector<string>& strs) {
//		int  ret = 0;
//		for (int i = 0; i < (int)strs.size(); i++)
//		{
//			for (int j = i + 1; j < (int)strs.size(); j++)
//			{
//				if (Check(strs[i], strs[j]))
//					ret++;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>strs{ "blw","bwl","wlb" };
//	cout << Solution().numSimilarGroups(strs);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
//class Solution {
//public:
//	ListNode* Reverse(ListNode* head)
//	{
//		ListNode newhead;
//		newhead.next = nullptr;
//		ListNode* prev = &newhead, *next = nullptr;
//		while (head)
//		{
//			next = head->next;
//			head->next = prev;
//			prev = head;
//			head = next;
//		}
//		return prev;
//	}
//
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode newhead;
//		newhead.next = head;
//		ListNode* prev = &newhead, *cur = head;
//		int cnt = 0;
//		while (head)
//		{
//			cnt++;
//			if (cnt == k)
//			{
//				ListNode* next = head->next;
//				head->next = nullptr;
//				ListNode* tmp = prev->next;
//				//翻转
//				prev->next = Reverse(prev->next);
//				prev = tmp;
//				head = prev;
//				prev->next = next;
//				cnt = 0;
//			}
//			head = head->next;
//		}
//		if (cnt == k)
//			prev->next = Reverse(prev->next);
//		return newhead.next;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
////class Solution {
////public:
////	int countHillValley(vector<int>& nums) {
////		int ret = 0;
////		for (int i = 1; i < (int)nums.size() - 1; i++)
////		{
////			if (nums[i] == nums[i - 1])
////				continue;
////			int left = i - 1, right = i + 1;
////			//在左边找不相等的第一个
////			while (left >= 0)
////			{
////				if (nums[left] != nums[i])
////					break;
////				left--;
////			}
////			while (right < nums.size())
////			{
////				if (nums[right] != nums[i])
////					break;
////				right++;
////			}
////			if (left >= 0 && right < nums.size()) {
////				if ((nums[left] < nums[i] && nums[right] < nums[i]) ||
////					(nums[left] > nums[i] && nums[right] > nums[i]) ||
////					(nums[left] == nums[right]))
////					ret++;
////			}
////		}
////		return ret;
////	}
////};
//
//
//class Solution {
//public:
//	int countCollisions(string directions) {
//		int ret = 0;
//		stack<char>s;
//		for (int i = 0; i < (int)directions.size(); i++)
//		{
//			if (s.empty()) {
//				s.push(directions[i]);
//				continue;
//			}
//			if (directions[i] == 'L'&&s.top() == 'S') {
//				ret++;
//			}
//			else if (directions[i] == 'L'&&s.top() == 'R') {
//				s.pop();
//				ret += 2;
//				while (!s.empty())
//				{
//					if (s.top() != 'R')
//						break;
//					s.pop();
//					ret += 1;
//				}
//				s.push('S');
//			}
//			else if (directions[i] == 'S') {
//				while (!s.empty())
//				{
//					if (s.top() != 'R')
//						break;
//					ret++;
//					s.pop();
//				}
//				s.push('S');
//			}
//			else
//				s.push(directions[i]);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string nums{ "LLRLRLLSLRLLSLSSSS" };
//	cout << Solution().countCollisions(nums);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution {
//public:
//	bool divideArray(vector<int>& nums) {
//		unordered_map<int, int>m;
//		for (const auto& e : nums) {
//			m[e]++;
//		}
//		for (const auto e : m) {
//			if (e.second % 2)
//				return false;
//		}
//		return true;
//	}
//};


//#include <iostream>
//using namespace std;
//
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
//class Solution {
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		if (head == nullptr)
//			return head;
//		ListNode* prev = head, *cur = head->next;
//		while (cur)
//		{
//			if (cur->val != prev->val) {
//				prev->next = cur;
//				prev = cur;
//			}
//			cur = cur->next;
//		}
//		prev->next = nullptr;
//		return head;
//	}
//};

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	string convertToTitle(int columnNumber) {
//		string ret;
//		while (columnNumber)
//		{
//			columnNumber--;
//			ret += (columnNumber % 26) + 'A';
//			columnNumber /= 26;
//		}
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};

//#include <iostream>
//#include <queue>
//using namespace std;
//
//class MedianFinder {
//private:
//	priority_queue<int>max_queue;
//	priority_queue<int, vector<int>, greater<int>>min_queue;
//public:
//	/** initialize your data structure here. */
//	MedianFinder() {
//
//	}
//
//	void addNum(int num) {
//		if (max_queue.size() == min_queue.size()){
//			max_queue.push(num);
//			min_queue.push(max_queue.top());
//			max_queue.pop();
//		}
//		else {
//			min_queue.push(num); 
//			max_queue.push(min_queue.top());
//			min_queue.pop();
//		}
//	}
//
//	double findMedian() {
//		int size = min_queue.size() + max_queue.size();
//		if (size % 2 == 0)
//			return (min_queue.top() + max_queue.top()) / 2.0;
//		return min_queue.top();
//	}
//};


//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//#include <atomic>
//using namespace std;
//mutex mlock;
//void fun(int n)
//{
//	mlock.lock();
//	for (int i = 0; i < n; i++)
//	{
//		cout << i << endl;
//	}
//	mlock.unlock();
//}
//
////void fun(int n)
////{
////	static int i = 1;
////	while (true)
////	{
////		mlock.lock();
////		if (i <= n) {
////			cout << i << endl;
////			i++;
////			mlock.unlock();
////		}
////		else {
////			mlock.unlock();
////			break;
////		}
////	}
////}
//
//
////通过原子性操作
//atomic<int> sum(0);
//void fun(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		sum++;
//	}
//}

//int main()
//{
//	vector<thread>vthread;
//	int n = 0;
//	cin >> n;
//	vthread.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		vthread[i] = thread(fun, 100);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		vthread[i].join();
//	}
//	cout << sum;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//using namespace std;
//mutex mlock;
//void fun(int n)
//{
//	lock_guard<mutex>_lock(mlock);
//	for (int i = 0; i < n; i++)
//	{
//		if (i == n / 2)
//		{
//			cout << this_thread::get_id << "退出" << endl;
//			return;
//		}
//		cout << i << endl;
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<thread>vthread;
//	vthread.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		vthread[i] = thread(fun, 100);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		vthread[i].join();
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<long long>nums;
//	nums.resize(n * 3);
//	for (int i = 0; i < 3 * n; i++)
//	{
//		cin >> nums[i];
//	}
//	sort(nums.begin(), nums.end());
//	int left = 0, right = nums.size() - 1;
//	int mid = right - 1;
//	long long ret = 0;
//	while (left < mid)
//	{
//		ret += nums[mid];
//		left++;
//		right -= 2;
//		mid = right - 1;
//	}
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <unordered_set>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	unordered_set<char>s;
//	getline(cin, s1);
//	getline(cin, s2);
//
//	for (auto e : s2)
//		s.insert(e);
//	string ret;
//	for (auto e : s1) {
//		if (s.find(e) == s.end())
//			ret += e;
//	}
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
////class Solution {
////public:
////	bool checkIfPangram(string sentence) {
////		vector<int>flag(26, 0);
////		for (auto e : sentence)
////		{
////			flag[e - 'a']++;
////		}
////		return count(flag.begin(), flag.end(), 0) == 0 ? true : false;
////	}
////};
//
////class Solution {
////public:
////	int numJewelsInStones(string jewels, string stones) {
////		vector<int>flag(65, 0);
////		for (auto e : jewels)
////			flag[e - 'A'] = 1;
////		int ret = 0;
////		for (auto e : stones)
////		{
////			if (flag[e - 'A'])
////				ret++;
////		}
////		return ret;
////	}
////};
//
//
////class Solution {
////public:
////	string destCity(vector<vector<string>>& paths) {
////		unordered_set<string>s;
////		for (const auto e : paths)
////			s.insert(e[0]);
////		for (const auto e : paths)
////		{
////			if (s.find(e[1]) == s.end())
////				return e[1];
////		}
////	}
////};
//
//class Solution {
//public:
//	vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
//		unordered_map<int, unordered_set<int>>flag;
//		for (const auto& e : logs)
//		{
//			flag[e[0]].insert(e[1]);
//		}
//		vector<int>ret(k, 0);
//		for (auto& e : flag)
//		{
//			ret[e.second.size() - 1]++;
//		}
//		return ret;
//	}
//};

//#include <iostream>
//#include <mutex>
//#include <thread>
//#include <condition_variable>
//using namespace std;
//
//int main()
//{
//	//两个线程交替打印奇数偶数
//	mutex mtx;
//	condition_variable v;
//	bool flag = false;
//	thread p1([&]() {
//		int i = 1;
//		unique_lock<mutex> lock(mtx);
//		while (i < 100)
//		{
//			v.wait(lock, [&]()->bool {return !flag; });
//			cout << this_thread::get_id() << " : " << i << endl;
//			i += 2;
//			flag = true;
//			v.notify_one();
//		}
//	});
//
//	thread p2([&]() {
//		int j = 2;
//		unique_lock<mutex>  lock(mtx);
//		while (j < 100)
//		{
//			v.wait(lock, [&]()->bool {return flag; });
//			cout << this_thread::get_id() << " : " << j << endl;
//			j += 2;
//			flag = false;
//			v.notify_one();
//		}
//	});
//	p1.join();
//	p2.join();
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <unordered_set>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	int countPoints(string rings) {
//		unordered_map<int, unordered_set<char>>m;
//		int ret = 0;
//		for (int i = 1; i < (int)rings.size(); i += 2)
//		{
//			m[rings[i]].insert(rings[i - 1]);
//		}
//		for (const auto& e : m)
//		{
//			if (e.second.size() == 3)
//				ret++;
//		}
//		return ret;
//	}
//};


//#include <iostream>
//#include <unordered_set>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//private:
//	unordered_set<int>s;
//public:
//	void prevorder(TreeNode* head)
//	{
//		if (head == nullptr)
//			return;
//		s.insert(head->val);
//		prevorder(head->left);
//		prevorder(head->right);
//	}
//
//	int numColor(TreeNode* root) {
//		prevorder(root);
//		return s.size();
//	}
//};

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	string sortString(string s) {
//		vector<int>flag(26, 0);
//		for (auto e : s)
//			flag[e - 'a']++;
//		string ret;
//		int size = s.size();
//		int cur = 0;
//		while (size > 0)
//		{
//			for (int i = 0; i < 26; i++)
//			{
//				if (flag[i]){
//					ret += i + 'a';
//					flag[i]--;
//					size--;
//				}
//			}
//			for (int i = 25; i>=0; i--)
//			{
//				if (flag[i]) {
//					ret += i + 'a';
//					flag[i]--;
//					size--;
//				}
//			}
//		}
//		return ret;
//	}
//};

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int>m;
		for (const auto & e : s)
		{
			m[e]++;
		}
		vector<pair<char, int>>flag;
		for (const auto& e : m)
		{
			flag.push_back(e);
		}
		sort(flag.begin(), flag.end(), [](const pair<char, int>&x, const pair<char, int>&y)->bool
		{
			return x.second > y.second;
		});
		string ret;
		for (const auto& e : flag)
			ret.insert(ret.end(), e.second, e.first);
		return ret;
	}
};

int main()
{
	string s = "tree";
	cout << Solution().frequencySort(s);
	return 0;
}
