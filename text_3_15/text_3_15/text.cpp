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

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		unordered_set<int>flag;
		for (const auto& e : nums)
			flag.insert(e);
		for (int i = 1; i <= INT_MAX; i++)
		{
			if (flag.find(i) == flag.end())
				return i;
		}
		return -1;
	}
};
