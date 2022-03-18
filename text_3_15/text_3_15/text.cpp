//#include <iostream>
//#include<unordered_set>
//#include<vector>
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
////class Solution {
////public:
////	ListNode* reverseList(ListNode* head) {
////		ListNode* prev = nullptr, *next = nullptr;
////		while (head)
////		{
////			next = head->next;
////			head->next = prev;
////			prev = head;
////			head = next;
////		}
////		return prev;
////	}
////};
//
////class Solution {
////public:
////	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
////	{
////		if (headA == nullptr || headB == nullptr)
////			return nullptr;
////		unordered_set<ListNode*>s;
////		while (headA)
////		{
////			s.insert(headA);
////			headA = headA->next;
////		}
////		while (headB)
////		{
////			if (s.find(headB) != s.end())
////				return headB;
////			headB = headB->next;
////		}
////		return nullptr;
////	}
////};
//
//class Solution {
//public:
//	bool isPalindrome(ListNode* head) {
//		vector<int>nums;
//		while (head)
//		{
//			nums.push_back(head->val);
//			head = head->next;
//		}
//		int begin = 0, end = nums.size() - 1;
//		while (begin < end)
//		{
//			if (nums[begin++] != nums[end--])
//				return false;
//		}
//		return true;
//	}
//};

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	bool isAnagram(string s, string t) {
//		if (s == t)
//			return false;
//		sort(s.begin(), s.end());
//		sort(t.begin(), t.end());
//		return s == t;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//		map<int, int>m;
//		for (const auto& e : nums)
//		{
//			m[e]++;
//		}
//		multimap<int, int, greater<int>>mm;
//		for (auto& e : m)
//		{
//			mm.insert(make_pair(e.second, e.first));
//		}
//		vector<int>ret;
//		for (auto& e : mm)
//		{
//			if (k == 0)
//				break;
//			ret.push_back(e.second);
//			k--;
//		}
//		return ret;
//	}
//};

//#include <iostream>
//#include <unordered_set>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//		unordered_set<int>flag;
//		for (const auto& e : nums)
//			flag.insert(e);
//		for (int i = 1; i <= INT_MAX; i++)
//		{
//			if (flag.find(i) == flag.end())
//				return i;
//		}
//		return -1;
//	}
//};


//#include <iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//		vector<int>flag(1001, 0);
//		for (const auto e : arr1)
//		{
//			flag[e]++;
//		}
//		auto it = arr2.begin();
//		int index = 0;//arr1的插入位置
//		while (it != arr2.end())
//		{
//			while (flag[*it] > 0)
//			{
//				arr1[index++] = *it;
//				flag[*it]--;
//			}
//			++it;
//		}
//
//		for (int i = 0; i < 1001; i++)
//		{
//			while (flag[i] > 0)
//			{
//				arr1[index++] = i;
//				flag[i]--;
//			}
//		}
//		return arr1;
//	}
//};
//
//int main()
//{
//	vector<int>arr1{ 2,3,1,3,2,4,6,7,9,2,19 };
//	vector<int>arr2{ 2,1,4,3,9,6 };
//	Solution().relativeSortArray(arr1, arr2);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class MovingAverage {
//public:
//	MovingAverage(int size)
//		: size(size)
//	{}
//
//	double next(int val) {
//		nums.push_back(val);
//		if (nums.size() != 1)
//			nums[nums.size() - 1] += nums[nums.size() - 2];
//		double ret = 0;
//		if (nums.size() > size){
//			ret = (nums[nums.size() - 1] - nums[nums.size() - size - 1])*1.0 / size;
//			return ret;
//		}
//		else{
//			ret = nums[nums.size() - 1] * 1.0 / nums.size();
//		}
//		return ret;
//	}
//	vector<int>nums;
//	int size;
//};
//
//int main()
//{
//	MovingAverage m(4);
//	m.next(1);
//	m.next(10);
//	m.next(3);
//	cout << m.next(5) << endl;
//
//	return 0;
//}


//#include<iostream>
//#include<queue>
//using namespace std;
//
//class KthLargest {
//public:
//	KthLargest(int k, vector<int>& nums) {
//		this->k = k;
//		for (const auto& e : nums)
//			add(e);
//	}
//
//	int add(int val) {
//		pq.push(val);
//		if (pq.size() > k)
//			pq.pop();
//		return pq.top();
//	}
//private:
//	priority_queue<int, vector<int>, greater<int>>pq;
//	int k;
//};


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int ret = 1E9;
//	void Backtracking(const vector<int>&nums, int layers, int index, int sum, const int& target)
//	{
//		if (layers == 3) {
//			ret = abs(sum - target) > abs(ret - target) ? ret : sum;
//			return;
//		}
//		for (int i = index; i < (int)nums.size(); i++)
//		{
//			Backtracking(nums, layers + 1, i + 1, sum + nums[i], target);
//		}
//	}
//
//	int threeSumClosest(vector<int>& nums, int target) {
//		Backtracking(nums, 0, 0, 0, target);
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ -1, 2, 1, -4 };
//	int target = 1;
//	cout << Solution().threeSumClosest(nums, target);
//	return 0;
//}

////239. 滑动窗口最大值
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//		priority_queue<pair<int, int>>pq;
//		for (int i = 0; i < k; i++)
//		{
//			pq.push(make_pair(nums[i], i));
//		}
//		vector<int>ret;
//		for (int i = 0; i <= (int)nums.size() - k; i++)
//		{
//			while (pq.top().second < i)
//			{
//				pq.pop();
//			}
//			ret.push_back(pq.top().first);
//			if (k + i < nums.size())
//				pq.push(make_pair(nums[k + i], k + i));
//		}
//		return ret;
//	}
//};
//
//int  main()
//{
//	vector<int>nums{ 1, 3, -1, -3, 5, 3, 6, 7 };
//	int k = 3;
//	Solution().maxSlidingWindow(nums, k);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//void Print(const Date& x)
//{
//	cout << "左值引用" << endl;
//}
//
//void Print(Date&& x)
//{
//	cout << "右值引用" << endl;
//}
//
////万能引用
//template<class T>
//void Fun(T&& x)//一切形参都是左值
//{
//	Print(forward<T>(x));
//}
//
//int main()
//{
//	Date d(2022, 1, 12);
//	Fun(d);
//	Fun(move(d));//右值
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//void Print(int & x)
//{
//	cout << "左值" << x << endl;
//}
//
//void Print(int && x)
//{
//	cout << "右值" << x << endl;
//}
//
//template<class T>
//void Fun(T&& x)
//{
//	//因为所有函数的形参都是左值
//
//	//Print(x);
//	Print(forward<T>(x));//使用完美转发解决。
//}
//
//int main()
//{
//	int a = 10;
//	Fun(a);//左值
//	Fun(20);//右值
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//namespace wkn
//{
//	template<class T>
//	class vector
//	{
//	public:
//		void push_back(T&&);//这里并不是一个万能引用
//	};
//}
//
//int main()
//{
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
////template<class ... Args>
////void Fun(Args... args)
////{
////	//计算参数包中的参数个数
////	cout << sizeof...(args) << endl;
////}
//
////如何输出参数包中的参数呢
////终止函数
////void Print()
////{
////	cout << endl;
////}
////
////template<class T,class ...Args>
////void Print(T t, Args... args)
////{
////	cout << t << " ";
////	Print(args...);
////}
//
//
////逗号表达式方式
//template<class T>
//void Print(T t)
//{
//	cout << t << " ";
//}
//
//template<class ...Args>
//void Print(Args... args)
//{
//	int arr[] = { (Print(args),0)... };
//	cout << endl;
//}
//
//int main()
//{
//	Print(1, 2, 3, 4);
//	Print(1, "abc", 'B');
//	return 0;
//}


//lambda
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int x = 10, y = 20;
//	//捕捉列表 参数列表 返回值类型 函数体
//	auto tmp = [](int x, int y)->int { return x + y; };
//	cout << tmp(10, 10) << endl;
//
//	//也可以用捕捉列表
//	auto tmp1 = [x, y]()->int { return x + y; };
//	cout << tmp1() << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int x = 10, y = 20;
//	//auto swap = [](int& x, int& y) {int tmp = x; x = y; y = tmp; };
//	auto swap = [&x, &y]
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	//swap(x, y);
//	swap();
//	cout << "x:" << x << " y:" << y;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
//class Solution {
//private:
//	ListNode* begin;
//public:
//	bool Check(ListNode* cur)
//	{
//		if (cur < begin)
//			return true;
//		if (cur != nullptr)
//		{
//			if (!Check(cur->next))
//				return false;
//			if (cur->val != begin->val)
//				return false;
//			begin = begin->next;
//		}
//		return true;
//	}
//
//	bool isPalindrome(ListNode* head)
//	{
//		begin = head;
//		return Check(head);
//	}
//};

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int numTeams(vector<int>& rating) {
//		vector<vector<int>>flag = { rating.size(),vector<int>(4,0) };
//		for (int i = 1; i < (int)rating.size(); i++)
//		{
//			for (int j = 0; j < i; j++)
//			{
//				//判断当前位置的左面有多少位置小于当前值。
//				if (rating[i] > rating[j])
//					flag[i][0]++;
//				if (rating[i] < rating[j])
//					flag[i][1]++;
//			}
//		}
//
//		for (int i = 1; i < (int)rating.size(); i++)
//		{
//			for (int j = i + 1; j < (int)rating.size(); j++)
//			{
//				//判断当前位置的右面面有多少位置小于当前值。
//				if (rating[i] > rating[j])
//					flag[i][2]++;
//				if (rating[i] < rating[j])
//					flag[i][3]++;
//			}
//		}
//		int ret = 0;
//		for (int i = 1; i < (int)rating.size() - 1; i++)
//		{
//			ret += flag[i][1] * flag[i][2] + flag[i][0] * flag[i][3];
//		}
//		return ret;
//	}
//};
//
//
//int main()
//{
//	vector<int>nums{ 2,5,3,4,1 };
//	cout << Solution().numTeams(nums);
//	return 0;
//}

//#include <iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int countKDifference(vector<int>& nums, int k) {
//		int ret = 0;
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			int target = 0;
//			target = abs(nums[i]) + k;
//			if (nums[i] < 0)
//				target *= -1;
//			ret += count(nums.begin() + i, nums.end(), target);
//			ret += count(nums.begin() + i, nums.end(), nums[i] - k);
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
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//	int numIdenticalPairs(vector<int>& nums) {
//		unordered_map<int, int>m;
//		for (const auto& e : nums)
//		{
//			m[e]++;
//		}
//		int ret = 0;
//		for (const auto& e : m)
//		{
//			ret += e.second*(e.second - 1) / 2;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,2,3,1,1,3 };
//	cout << Solution().numIdenticalPairs(nums);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
// 
//class Solution {
//public:
//	ListNode* Merge(ListNode* l1, ListNode* l2)
//	{
//		if (l1 == nullptr)
//			return l2;
//		if (l2 == nullptr)
//			return l1;
//		ListNode head;
//		ListNode* prev = &head;
//		while (l1&&l2)
//		{
//			if (l1->val < l2->val){
//				prev->next = l1;
//				prev = l1;
//				l1 = l1->next;
//			}
//			else {
//				prev->next = l2;
//				prev = l2;
//				l2 = l2->next;
//			}
//		}
//		if (l1 != nullptr)
//			prev->next = l1;
//		if (l2 != nullptr)
//			prev->next = l2;
//		return head.next;
//	}
//
//	ListNode* mergeKLists(vector<ListNode*>& lists)
//	{
//		if (lists.size() == 0)
//			return nullptr;
//		for (int i = 1; i < (int)lists.size(); i++)
//		{
//			lists[i] = Merge(lists[i], lists[i - 1]);
//		}
//		return lists[lists.size() - 1];
//	}
//};


////包装器
//#include <iostream>
//#include <functional>
//using namespace std;
//
//template<class F, class T>
//void Fun(F f, T t)
//{
//	static int count = 0;
//	count++;
//	cout << count << endl;
//	f(t);//通过包装器包装了函数，这个函数模板只被实例化一份。
//}
//
//void Print(int x)
//{
//	cout << x << endl;
//}
//
//class OutPut
//{
//public:
//	void operator()(int x)
//	{
//		cout << x << endl;
//	}
//};
//
//class Solution
//{
//public:
//	void Print(int x)
//	{
//		cout << x << endl;
//	}
//
//	static void Print1(int x)
//	{
//		cout << x << endl;
//	}
//};
//
//int main()
//{
//	function<void(int)>f1 = Print;
//	Fun(f1, 10);
//	//仿函数
//	function<void(int)>f2 = OutPut();
//	Fun(f2, 100);
//	//lamda表达式
//	function<void(int)>f3 = [](int x)->void {cout << x << endl; };
//	Fun(f3, 200);
//	//绑定一个成员函数
//	function<void(int)> f4 = bind(&Solution::Print, Solution(), placeholders::_1);
//	Fun(f4, 400);
//	//绑定一个普通函数
//	function<void(int)> f5 = bind(Print, placeholders::_1);
//	f5(123);
//	function<void(Solution, int)>f6 = &Solution::Print;//非静态成员函数的函数地址要加上&
//	f6(Solution(), 999);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> getRow(int rowIndex) {
//		vector<int>prev(1, 1);
//		vector<int>ret(rowIndex + 1, 1);
//		for (int i = 0; i <= rowIndex; i++)
//		{
//			vector<int>ret(i + 1, 1);
//			for (int j = 1; j < i; j++)
//			{
//				ret[j] = prev[j - 1] + prev[j];
//			}
//			prev = ret;
//		}
//		return prev;
//	}
//};
//
//int main()
//{
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int countConsistentStrings(string allowed, vector<string>& words) {
//		int arr[26] = { 0 };
//		for (const auto& e : allowed)
//			arr[e - 'a']++;
//		int ret = 0;
//		for (const auto & e : words)
//		{
//			int flag = 1;
//			for (int i = 0; i < (int)e.size(); i++)
//			{
//				if (arr[e[i] - 'a'] == 0) {
//					flag = 0;
//					break;
//				}
//			}
//			if (flag == 1)
//				ret++;
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
//#include <unordered_map>
//using namespace std;
//class Solution {
//public:
//	int countBalls(int lowLimit, int highLimit) {
//		unordered_map<int, int>m;
//		int sum = 0;
//		for (int i = lowLimit; i <= highLimit; i++)
//		{
//			int tmp = 0;
//			tmp = i;
//			sum = 0;
//			while (tmp)
//			{
//				sum += tmp % 10;
//				tmp /= 10;
//			}
//			m[sum]++;
//		}
//		int ret = INT_MIN;
//		for (const auto& e : m)
//		{
//			if (e.second > ret)
//				ret = e.second;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	int left = 1, right = 10;
//	cout << Solution().countBalls(left, right);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
////class Solution {
////public:
////	vector<int> findDuplicates(vector<int>& nums) {
////		vector<int>ret;
////		unordered_set<int>m;
////		for (auto e : nums)
////		{
////			if (m.insert(e).second == false)
////				ret.push_back(e);
////		}
////		return ret;
////	}
////};
//
//class Solution {
//public:
//	vector<int> findDuplicates(vector<int>& nums) {
//		vector<int>flag(nums.size() + 1, 0);
//		vector<int>ret;
//		for (auto e : nums)
//		{
//			if (flag[e] == 1)
//				ret.push_back(e);
//			else
//				flag[e]++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 4,3,2,7,8,2,3,1 };
//	Solution().findDuplicates(nums);
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool Check(const vector<int>&arr)
	{
		for (const int& e:arr)
		{
			//arr中只有字符串t中字符会小于0，小于0说明当前窗口中无法匹配t
			if (e < 0)
				return false;
		}
		return true;
	}

	string minWindow(string s, string t) {
		if (s.size() < t.size())
			return "";
		vector<int>flag(60, 0);
		for (int i = 0; i < t.size(); i++)
		{
			flag[s[i] - 'A']++;
			flag[t[i] - 'A']--;
		}
		if (Check(flag))
			return s.substr(0, t.size());
		int left = 0;
		string ret(s.size() + 1, 'a');
		for (int i = t.size(); i < s.size(); i++)
		{
			flag[s[i] - 'A']++;
			while (Check(flag))
			{
				flag[s[left] - 'A']--;
				ret = i - left + 1 < ret.size() ? s.substr(left, i - left + 1) : ret;
				left++;
			}
			if (ret.size() == s.size())
				break;
		}
		return ret.size() > s.size() ? "" : ret;
	}
};

int main()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout << Solution().minWindow(s, t);
	return 0;
}