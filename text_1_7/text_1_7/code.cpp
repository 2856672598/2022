//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	int minProductSum(vector<int>& nums1, vector<int>& nums2)
//	{
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		int sum = 0;
//		int begin = 0, end = nums2.size() - 1;
//		while (end >= 0)
//		{
//			sum += nums1[begin] * nums2[end];
//			begin++;
//			end--;
//		}
//		return sum;
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
//	int numRescueBoats(vector<int>& people, int limit)
//	{
//		sort(people.begin(), people.end());
//		int begin = 0, end = people.size() - 1;
//		int count = 0;
//		while (begin <= end)
//		{
//			int sum = people[end] + people[begin];
//			if (sum <= limit)
//			{
//				begin++;
//				end--;
//			}
//			else
//				end--;
//			count++;
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	vector<int>people{ 5,1,4,2 };
//	int limit = 6;
//	cout << Solution().numRescueBoats(people, limit) << endl;
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//class Solution
//{
//public:
//	static bool comp(const vector<int>x, const vector<int>y)
//	{
//		if (x[0] == y[0])
//			return  x[1] < y[1];
//		return x[0] > y[0];
//	}
//
//	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
//	{
//		sort(people.begin(), people.end(), comp);
//		vector<vector<int>>ret;
//		for (int i = 0; i < (int)people.size(); i++)
//		{
//			int pos = people[i][1];
//			ret.insert(ret.begin() + pos, people[i]);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>people{ {7,0},{4,4},{7,1},{5,0},{6,1},{5,2 } };
//	Solution().reconstructQueue(people);
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	string removeDuplicateLetters(string s)
//	{
//		bool arr[26] = { 0 };
//		for (auto e : s)
//		{
//			arr[e - 'a'] = 1;
//		}
//		string ret;
//		for (int i = 0; i < 26; i++)
//		{
//			if (arr[i])
//				ret.push_back(i + 'a');
//		}
//		return ret;
//	}
//};
//int main()
//{
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	string capitalizeTitle(string title)
//	{
//		int cur = 0, prev = 0;
//		while (cur < title.size())
//		{
//			if (title[cur] != ' ')
//			{
//				if (title[cur] >= 'A'&&title[cur] <= 'Z')
//					title[cur] += 32;
//				cur++;
//			}
//			else
//			{
//				if (cur - prev > 2)
//				{
//					title[prev] -= 32;
//				}
//				cur++;
//				prev = cur;
//			}
//		}
//		if (cur - prev > 2)
//			title[prev] -= 32;
//		return title;
//	}
//};
//
//int main()
//{
//	string s = "i lOve leetcode";
//	cout << Solution().capitalizeTitle(s) << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//
//struct ListNode
//{
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
////class Solution {
////public:
////	int pairSum(ListNode* head)
////	{
////		ListNode* fast = head, *slow = head;
////
////		if (fast == nullptr)
////			return 0;
////		while (fast->next != nullptr&&fast->next->next != nullptr)
////		{
////			fast = fast->next->next;
////			slow = slow->next;
////		}
////		ListNode* curR = slow->next;
////		//反转单链表。
////		ListNode* prev = nullptr, *tmp = nullptr;
////		while (curR != nullptr)
////		{
////			tmp = curR->next;
////			curR->next = prev;
////			prev = curR;
////			curR = tmp;
////		}
////
////		ListNode* cur1 = head, *cur2 = prev;
////		int ret = 0;
////		while (cur2 != nullptr)
////		{
////			ret = max(ret, cur1->val + cur2->val);
////			cur1 = cur1->next;
////			cur2 = cur2->next;
////		}
////		return ret;
////	}
////};
//
//
//class Solution {
//public:
//	int pairSum(ListNode* head)
//	{
//		ListNode* cur = head;
//		vector<int>arr;
//		while (cur)
//		{
//			arr.push_back(cur->val);
//			cur = cur->next;
//		}
//
//		int left = 0, right = arr.size() - 1;
//		int ret = 0;
//		while (left < right)
//		{
//			ret = max(ret, arr[left] + arr[right]);
//			left++;
//			right--;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	return 0;
//}


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int longestPalindrome(vector<string>& words)
	{
		unordered_map<string, int>m;
		for (auto e : words)
			m[e]++;
		int ret = 0;
		int sigMax = 0;
		for (auto& e : m)
		{
			string tmp = e.first;
			reverse(tmp.begin(), tmp.end());
			auto it = m.find(tmp);
			if (it != m.end() && e.first == (*it).first)
			{
				//aa bb
				ret += e.second*e.first.size();
				if (e.second % 2)
				{
					ret -= e.first.size();
					sigMax = max(sigMax, (int)e.first.size());
				}
			}
			else if (it != m.end())
			{
				ret += 2 * min(e.second, (*it).second)*e.first.size();
				int dev = min(e.second, (*it).second);
				e.second -= dev;
				(*it).second -= dev;
			}
		}
		return ret += sigMax;
	}
};

int main()
{
	vector<string>words{ "mt","lt","tt","lt","mt","tl","mm","lt","tt","mt","ml","mm" };
	cout << Solution().longestPalindrome(words) << endl;
	return 0;
}


//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	bool checkValid(vector<vector<int>>& matrix)
//	{
//		unordered_map<int,int> row;
//		unordered_map<int,int> col;
//		for (int i = 0; i < matrix.size(); i++)
//		{
//			for (int j = 0; j < matrix[i].size(); j++)
//			{
//				if (row[matrix[i][j]] == 1)
//					return false;
//				if (col[matrix[j][i]] == 1)
//					return false;
//				row[matrix[i][j]]++;
//				col[matrix[j][i]]++;
//			}
//			row.clear();
//			col.clear();
//		}
//		return true;
//	}
//};
//int main()
//{
//	vector<vector<int>>max{ {2,2,2},{2,2,2}, {2, 2, 2} };
//	cout << Solution().checkValid(max);
//	return 0;
//}
