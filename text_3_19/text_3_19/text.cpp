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

