//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int singleNonDuplicate(vector<int>& nums) {
//		int ret = 0;
//		for (auto e : nums)
//		{
//			ret ^= e;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	static bool Comp(const vector<int>& nums1, const vector<int>& nums2)
//	{
//		return nums1[0] < nums2[0];
//	}
//	vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		if (intervals.size() == 0)
//			return intervals;
//		sort(intervals.begin(), intervals.end(), Comp);
//		vector<vector<int>>ret;
//		vector<int>prev(intervals[0]);
//		int i = 1;
//		while (i < intervals.size())
//		{
//			if (intervals[i][0] <= prev[1])
//			{
//				prev[1] = max(intervals[i][1], prev[1]);
//			}
//			else
//			{
//				ret.push_back(prev);
//				prev = intervals[i];
//			}
//			i++;
//		}
//		ret.push_back(prev);
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>nums{ {{1,4},{0,2},{3,5}} };
//	Solution().merge(nums);
//	return 0;
//}

////剑指 Offer II 076. 数组中的第 k 大的数字
//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	static bool Comp(int x, int y)
//	{
//		return x > y;
//	}
//	int findKthLargest(vector<int>& nums, int k)
//	{
//		if (nums.size() < k)
//			return 0;
//		sort(nums.begin(), nums.end(), Comp);
//		int ret = 0;
//		for (auto e : nums)
//		{
//			k--;
//			if (k == 0)
//			{
//				ret = e;
//				break;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 3,2,3,1,2,4,5,5,6 };
//	int k = 4;
//	cout << Solution().findKthLargest(nums, k);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
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
//	ListNode* sortList(ListNode* head) {
//		vector<int>nums;
//		ListNode* cur = head;
//		while (cur)
//		{
//			nums.push_back(cur->val);
//			cur = cur->next;
//		}
//		sort(nums.begin(), nums.end());
//		ListNode* newhead = new ListNode;
//		cur = newhead;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			cur->next = new ListNode(nums[i]);
//			cur = cur->next;
//		}
//		cur = newhead->next;
//		delete newhead;
//		return cur;
//	} 
//};
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int lenLongestFibSubseq(vector<int>& arr) {
//
//		int ret = 0;
//		for (int i = 0; i < arr.size() - 1; i++)
//		{
//			for (int j = i + 1; j < arr.size(); j++)
//			{
//				int prev = arr[i], cur = arr[j];
//				if ((prev + cur) <= arr[arr.size() - 1])
//				{
//					int count = 2;
//					while (true)
//					{
//						if (find(arr.begin(), arr.end(), (prev + cur)) != arr.end())
//						{
//							int tmp = prev + cur;
//							prev = cur;
//							cur = tmp;
//							count++;
//						}
//						else
//							break;
//					}
//					ret = max(ret, count);
//				}
//			}
//		}
//		return ret == 2 ? 0 : ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 2,4,7,8,9,10,14,15,18,23,32 };
//	cout << Solution().lenLongestFibSubseq(nums);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	//中心拓展
//	int countSubstrings(string s)
//	{
//		int count = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				int left = i, right = i + j;
//				while (left >= 0 && right < s.size())
//				{
//					if (s[left--] != s[right++])
//						break;
//					count++;
//				}
//			}
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	string s{ "aaaaa" };
//	cout << Solution().countSubstrings(s);
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		string ret;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int left = i, right = i + j;
				int count = 0;
				while (left >= 0 && right < s.size())
				{
					if (s[left] != s[right])
						break;
					count = right - left + 1;
					left--;
					right++;
				}
				if (left + 1 < s.size() && count > ret.size())
				{
					ret.resize(0);
					ret = s.substr(left + 1, count);
				}
				count = 1;
			}
		}
		return ret;
	}
};

int main()
{
	string s{ "babad" };
	cout << Solution().longestPalindrome(s) << endl;
	return 0;
}