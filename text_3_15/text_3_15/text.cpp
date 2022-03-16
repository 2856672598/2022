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

#include<iostream>
using namespace std;

namespace wkn
{
	template<class T>
	class vector
	{
	public:
		void push_back(T&&);//这里并不是一个万能引用
	};
}

int main()
{
	return 0;
}