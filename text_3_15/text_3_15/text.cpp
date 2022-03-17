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
//		int index = 0;//arr1�Ĳ���λ��
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

////239. �����������ֵ
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
//	cout << "��ֵ����" << endl;
//}
//
//void Print(Date&& x)
//{
//	cout << "��ֵ����" << endl;
//}
//
////��������
//template<class T>
//void Fun(T&& x)//һ���βζ�����ֵ
//{
//	Print(forward<T>(x));
//}
//
//int main()
//{
//	Date d(2022, 1, 12);
//	Fun(d);
//	Fun(move(d));//��ֵ
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//void Print(int & x)
//{
//	cout << "��ֵ" << x << endl;
//}
//
//void Print(int && x)
//{
//	cout << "��ֵ" << x << endl;
//}
//
//template<class T>
//void Fun(T&& x)
//{
//	//��Ϊ���к������βζ�����ֵ
//
//	//Print(x);
//	Print(forward<T>(x));//ʹ������ת�������
//}
//
//int main()
//{
//	int a = 10;
//	Fun(a);//��ֵ
//	Fun(20);//��ֵ
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
//		void push_back(T&&);//���ﲢ����һ����������
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
////	//����������еĲ�������
////	cout << sizeof...(args) << endl;
////}
//
////�������������еĲ�����
////��ֹ����
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
////���ű��ʽ��ʽ
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
//	//��׽�б� �����б� ����ֵ���� ������
//	auto tmp = [](int x, int y)->int { return x + y; };
//	cout << tmp(10, 10) << endl;
//
//	//Ҳ�����ò�׽�б�
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
//				//�жϵ�ǰλ�õ������ж���λ��С�ڵ�ǰֵ��
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
//				//�жϵ�ǰλ�õ��������ж���λ��С�ڵ�ǰֵ��
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

#include <iostream>
#include <vector>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
	ListNode* Merge(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode head;
		ListNode* prev = &head;
		while (l1&&l2)
		{
			if (l1->val < l2->val){
				prev->next = l1;
				prev = l1;
				l1 = l1->next;
			}
			else {
				prev->next = l2;
				prev = l2;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr)
			prev->next = l1;
		if (l2 != nullptr)
			prev->next = l2;
		return head.next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.size() == 0)
			return nullptr;
		for (int i = 1; i < (int)lists.size(); i++)
		{
			lists[i] = Merge(lists[i], lists[i - 1]);
		}
		return lists[lists.size() - 1];
	}
};
