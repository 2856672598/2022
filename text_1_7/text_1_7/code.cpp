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


//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//class Solution {
//public:
//	int longestPalindrome(vector<string>& words)
//	{
//		unordered_map<string, int>m;
//		for (auto e : words)
//			m[e]++;
//		int ret = 0;
//		int sigMax = 0;
//		for (auto& e : m)
//		{
//			string tmp = e.first;
//			reverse(tmp.begin(), tmp.end());
//			auto it = m.find(tmp);
//			if (it != m.end() && e.first == (*it).first)
//			{
//				//aa bb
//				ret += e.second*e.first.size();
//				if (e.second % 2)
//				{
//					ret -= e.first.size();
//					sigMax = max(sigMax, (int)e.first.size());
//				}
//			}
//			else if (it != m.end())
//			{
//				ret += 2 * min(e.second, (*it).second)*e.first.size();
//				int dev = min(e.second, (*it).second);
//				e.second -= dev;
//				(*it).second -= dev;
//			}
//		}
//		return ret += sigMax;
//	}
//};
//
//int main()
//{
//	vector<string>words{ "mt","lt","tt","lt","mt","tl","mm","lt","tt","mt","ml","mm" };
//	cout << Solution().longestPalindrome(words) << endl;
//	return 0;
//}


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


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	static bool compare(const vector<int>&x, const vector<int>&y)
//	{
//		return x[0] < y[0];
//	}
//
//	int findMinArrowShots(vector<vector<int>>& points)
//	{
//		sort(points.begin(), points.end(), compare);
//		int count = 1;
//		int prev = points[0][1];
//		for (int i = 1; i < points.size(); i++)
//		{
//			if (points[i][0] > prev)
//			{
//				count++;
//				prev = points[i][1];
//			}
//			else
//			{
//				prev = min(prev, points[i][1]);
//			}
//		}
//		return count;
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
//	static bool compare(const vector<int>&x, const vector<int>&y)
//	{
//		return x[1] < y[1];
//	}
//
//	int eraseOverlapIntervals(vector<vector<int>>& intervals)
//	{
//		sort(intervals.begin(), intervals.end(), compare);
//		int count = 0;
//		int prev = intervals[0][1];
//		for (int i = 1; i < intervals.size(); i++)
//		{
//			if (intervals[i][0] < prev)
//			{
//				count++;
//			}
//			else
//				prev = intervals[i][1];
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>intervals{{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95}
//		,{-31,49},{66,98},{-63,2},{30,47},{-40,-26} };
//	cout << Solution().eraseOverlapIntervals(intervals);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	static bool compar(const vector<int>& x, const vector<int>&y)
//	{
//		return x[0] < y[0];
//	}
//	
//	vector<vector<int>> merge(vector<vector<int>>& intervals)
//	{
//		sort(intervals.begin(), intervals.end(), compar);
//		vector<vector<int>>ret;
//		int prev = 0;
//		for (int i = 1; i < intervals.size(); i++)
//		{
//			if (intervals[i][0] <= intervals[prev][1])
//			{
//				if (intervals[i][1] > intervals[prev][1])
//					intervals[prev][1] = intervals[i][1];
//			}
//			else
//			{
//				ret.push_back(intervals[prev]);
//				prev = i;
//			}
//		}
//		if (prev != intervals.size())
//			ret.push_back(intervals[prev]);
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>intervals{ {2,3},{3,4},{1,5} };
//	Solution().merge(intervals);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	int monotoneIncreasingDigits(int n)
//	{
//		string nums = to_string(n);
//		int flag = nums.size();
//		for (int i = nums.size() - 1; i > 0; i--)
//		{
//			if (nums[i] < nums[i - 1])
//			{
//				nums[i - 1] -= 1;
//				flag = i;
//			}
//		}
//		while (flag < nums.size())
//		{
//			nums[flag++] = '9';
//		}
//		return stoi(nums);
//	}
//};
//int main()
//{
//	int n = 332643;
//	cout << Solution().monotoneIncreasingDigits(n) << endl;
//	return  0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost)
//	{
//		vector<int>dp(cost.size());
//		dp[0] = cost[0], dp[1] = cost[1];
//		for (int i = 2; i < (int)cost.size(); i++)
//		{
//			dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//		}
//		for (auto e : dp)
//			cout << e << " ";
//		return min(dp[cost.size() - 1], dp[cost.size() - 2]);
//	}
//};
//
//int main()
//{
//	vector<int>cost{ 1,100,1,1,1,100,1,1,100,1 };
//	cout << Solution().minCostClimbingStairs(cost) << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution
//{
//public:
//	int uniquePaths(int m, int n)
//	{
//		vector<vector<int>>ret;
//		for (int i = 0; i < m; i++)
//		{
//			vector<int>tmp;
//			for (int j = 0; j < n; j++)
//			{
//				tmp.push_back(1);
//			}
//			ret.push_back(tmp);
//		}
//		for (int i = 1; i < m; i++)
//		{
//			for (int j = 1; j < n; j++)
//			{
//				ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
//			}
//		}
//		return ret[m - 1][n - 1];
//	}
//};
//
//int main()
//{
//	int m = 3, n = 7;
//	cout << Solution().uniquePaths(m, n);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
//	{
//		int row = obstacleGrid.size(), col = obstacleGrid[0].size();
//		vector<vector<int>>dp(row, vector<int>(col, 0));
//		for (int i = 0; i < col&&obstacleGrid[0][i] != 1; i++)
//			dp[0][i] = 1;
//		for (int i = 0; i < row&&obstacleGrid[i][0] != 1; i++)
//			dp[i][0] = 1;
//
//		for (int i = 1; i < row; i++)
//		{
//			for (int j = 1; j < col; j++)
//			{
//				if (obstacleGrid[i][j] == 1)
//					continue;
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//			}
//		}
//		return dp[row - 1][col - 1];
//	}
//};
//
//int main()
//{
//	vector<vector<int>>obstacleGrid{ {0, 1},{0, 0} };
//	cout << Solution().uniquePathsWithObstacles(obstacleGrid);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	int integerBreak(int n)
//	{
//		vector<int>dp(n + 1, 0);
//		for (int i = 2; i <= n; i++)
//		{
//			int tmp = 0;
//			for (int j = 1; j <= i / 2; j++)
//			{
//				tmp = j * max((i - j), dp[i - j]);
//				dp[i] = max(tmp, dp[i]);
//			}
//		}
//		return dp[n];
//	}
//};
//
//int main()
//{
//	int n = 10;
//	cout << Solution().integerBreak(n) << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int numTrees(int n)
//	{
//		vector<int>dp(n + 1, 0);
//		dp[0] = 1;
//		dp[1] = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			int left = 0;
//			for (int j = i - 1; j >= 0; j--)
//			{
//				dp[i] += dp[left] * dp[j];
//				left++;
//			}
//		}
//		return dp[n];
//	}
//};
//
//int main()
//{
//	int n = 3;
//	cout << Solution().numTrees(n);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> groupThePeople(vector<int>& groupSizes)
//	{
//		unordered_map<int, vector<int>>m;
//		unordered_set<int>s;
//		for (int i = 0; i < groupSizes.size(); i++)
//		{
//			m[groupSizes[i]].push_back(i);
//			s.insert(groupSizes[i]);
//		}
//		vector<vector<int>>ret;
//		for (auto e : s)
//		{
//			auto it = m.find(e);
//			vector<int>tmp;
//			int count = 0;
//			for (int i = 0; i < (*it).second.size(); i++)
//			{
//				tmp.push_back((*it).second[i]);
//				count++;
//				if (count == e)
//				{
//					ret.push_back(tmp);
//					tmp.clear();
//					count = 0;
//				}
//			}
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
using namespace std;

class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> res;
		for (int i = 0; i < words.size(); i++) {
			if (check(words[i], pattern))
				res.push_back(words[i]);
		}
		return res;
	}
	bool check(string word, string pattern) {
		if (word.length() != pattern.length())
			return false;
		for (int i = 0; i < pattern.length(); i++)
		{
			int pos1 = word.find(word[i]);
			int pos2 = pattern.find(pattern[i]);
			if (word.find(word[i]) != pattern.find(pattern[i]))
				return false;
		}
		return true;
	}
};

int main()
{
	vector<string>words{ "abc","deq","mee","aqq","dkd","ccc" };
	string pattren = "abb";
	Solution().findAndReplacePattern(words, pattren);
	return 0;
}
