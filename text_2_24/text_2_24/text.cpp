//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums)
//	{
//		vector<int>dp(nums.size(), 1);
//		for (int i = 1; i < nums.size(); i++)
//		{
//			for (int j = i - 1; j >= 0; j--)
//			{
//				if (nums[j] < nums[i])
//					dp[i] = max(dp[j] + 1, dp[i]);
//			}
//		}
//		return *max_element(dp.begin(), dp.end());
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 10,9,2,5,3,7,101,18 };
//	cout << Solution().lengthOfLIS(nums);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<list>
//using namespace std;
//int Find(list<int>&nums, int x)
//{
//	list<int>::iterator prev, cur;
//	auto it = nums.begin();
//	int ret = x;
//	if (nums.size() == 2)
//	{
//		int tmp1 = *it;
//		int tmp2 = *(++it);
//		int tmp = max(tmp1, tmp2);
//		return ret = tmp * tmp*x;
//	}
//	if (*it == x)
//	{
//		ret *= nums.back();
//		cur = it;
//		ret *= *(++it);
//	}
//	else
//	{
//		prev = it;
//		while (it != nums.end())
//		{
//			if (*it == x)
//				break;
//			prev = it;
//			it++;
//		}
//		cur = it;
//		if (++it == nums.end())
//			it = nums.begin();
//		ret = (*cur)*(*prev)*(*it);
//	}
//	nums.erase(cur);
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int>flag(n);
//	list<int>nums;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> flag[i];
//		nums.push_back(flag[i]);
//	}
//	sort(flag.begin(), flag.end());
//	int ret = 0;
//	for (int i = 0; i < n -1; i++)
//	{
//		ret += Find(nums, flag[i]);
//	}
//	cout << ret << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		vector<int>dp(nums.size(), 0);
//		dp[0] = nums[0];
//		for (int i = 1; i < nums.size(); i++)
//		{
//			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//		}
//		return *max_element(dp.begin(), dp.end());
//	}
//};
//
//int main()
//{
//	vector<int>nums{ -2,1,-3,4,-1,2,1,-5,4 };
//	cout << Solution().maxSubArray(nums);
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//class Solution
//{
//public:
//	int flag = 1000000007;
//	int waysToStep(int n)
//	{
//		if (n < 3)
//			return n;
//		vector<int>dp(n, 0);
//		dp[0] = 1;
//		dp[1] = 2;
//		dp[2] = 4;
//		for (int i = 3; i < n; i++)
//		{
//			dp[i] = ((dp[i - 1] + dp[i - 2]) % flag + dp[i - 3]) % flag;
//		}
//		return dp[n - 1];
//	}
//};
//
//int main()
//{
//	int n = 5;
//	cout << Solution().waysToStep(n);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int minPathSum(vector<vector<int>>& grid)
//	{
//		vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), 0));
//		for (int i = 0; i < grid[0].size(); i++)
//		{
//			dp[0][i] = grid[0][i];
//			if (i != 0)
//				dp[0][i] += dp[0][i - 1];
//		}
//		for (int i = 0; i < grid.size(); i++)
//		{
//			dp[i][0] = grid[i][0];
//			if (i != 0)
//				dp[i][0] += dp[i - 1][0];
//		}
//
//		for (int i = 1; i < grid.size(); i++)
//		{
//			for (int j = 1; j < grid[i].size(); j++)
//			{
//				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//			}
//		}
//		return dp[grid.size() - 1][grid[0].size() - 1];
//	}
//};
//
//int main()
//{
//	vector<vector<int>>nums{ {1, 3, 1}, { 1, 5, 1 }, { 4, 2, 1 } };
//	cout << Solution().minPathSum(nums);
//	return 0;
//}

////23. 合并K个升序链表
//#include<iostream>
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
//class Solution {
//public:
//	ListNode* merge(ListNode* l1, ListNode* l2)
//	{
//		ListNode* head = new ListNode;
//		ListNode* cur1 = l1, *cur2 = l2, *cur = head;
//		while (cur1&&cur2)
//		{
//			if (cur1->val < cur2->val)
//			{
//				cur->next = cur1;
//				cur1 = cur1->next;
//			}
//			else
//			{
//				cur->next = cur2;
//				cur2 = cur2->next;
//			}
//			cur = cur->next;
//		}
//		if (cur1 == nullptr)
//			cur->next = cur2;
//		else
//			cur->next = cur1;
//		ListNode* ret = head->next;
//		delete  head;
//		return ret;
//	}
//
//	ListNode* mergeKLists(vector<ListNode*>& lists)
//	{
//		if (lists.size() == 0)
//			return nullptr;
//		ListNode* prev = lists[0];
//		for (int i = 1; i < lists.size(); i++)
//		{
//			prev = merge(prev, lists[i]);
//		}
//		return prev;
//	}
//};


//#include<iostream>
//#include<string>
//#include<unordered_set>
//using namespace std;
//
//int main()
//{
//	unordered_set<int>m;
//	m.insert(1);
//	m.insert(1);
//	string ret;
//	int n;
//	cin >> n;
//	int prev1 = 1, prev2 = 0;
//	while (prev1 <= 1000)
//	{
//		m.insert(prev1 + prev2);
//		int tmp = prev1 + prev2;
//		prev2 = prev1;
//		prev1 = tmp;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (m.find(i) != m.end())
//			ret.push_back('O');
//		else
//			ret.push_back('o');
//	}
//	cout << ret << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>>& triangle) {
//		if (triangle.size() == 0)
//			return 0;
//		int n = triangle.size();
//		vector<vector<int>>dp(n, vector<int>(triangle[n - 1].size()));
//		dp[0][0] = triangle[0][0];
//		for (int i = 1; i < n; i++)
//		{
//			dp[i][0] = triangle[i][0] + dp[i - 1][0];
//			dp[i][i] += triangle[i][i] + dp[i - 1][i - 1];
//		}
//
//		for (int i = 2; i < n; i++)
//		{
//			for (int j = 1; j < triangle[i].size() - 1; j++)
//			{
//				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
//			}
//		}
//		return *min_element(dp[n - 1].begin(), dp[n - 1].end());
//	}
//};
//
//int main()
//{
//	vector<vector<int>>nums{ {2},{3,4}, {6, 5, 7},{4, 1, 8, 3} };
//	cout << Solution().minimumTotal(nums);
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int maxProduct(vector<int>& nums) {
//		vector <int> maxS(nums), minS(nums);
//		for (int i = 1; i < nums.size(); ++i) {
//			maxS[i] = max(maxS[i - 1] * nums[i], max(nums[i], minS[i - 1] * nums[i]));
//			minS[i] = min(minS[i - 1] * nums[i], min(nums[i], maxS[i - 1] * nums[i]));
//		}
//		return *max_element(maxS.begin(), maxS.end());
//	}
//};
//int main()
//{
//	vector<int>nums{ -2,0,-1 };
//	cout << Solution().maxProduct(nums);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	int prefixCount(vector<string>& words, string pref)
//	{
//		int ret = 0;
//		for (int i = 0; i < words.size(); i++)
//		{
//			if (words[i].find(pref) == 0)
//				ret++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>words{ "leetcode","win","loops","success" };
//	string pref("code");
//	cout << Solution().prefixCount(words, pref);
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int minSteps(string s, string t) {
//		vector<int> flag(26, 0);
//		for (int i = 0; i < s.size(); i++)
//		{
//			flag[s[i] - 'a']++;
//		}
//		for (int i = 0; i < t.size(); i++)
//		{
//			flag[t[i] - 'a']--;
//		}
//		int ret = 0;
//		for (auto e : flag)
//			ret += abs(e);
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
//#include<map>
//using namespace std;
//class Solution {
//public:
//	long long minimumTime(vector<int>& time, int totalTrips) {
//		long long left = 0, right = 1e16;
//		long long mid = 0,count = 0;
//		while (left <= right)
//		{
//			mid = left + (right - left) / 2;
//			count = 0;
//			for (int i = 0; i < time.size(); i++)
//			{
//				count += mid / time[i];
//				if (count > totalTrips)
//					break;
//			}
//
//			if (count >= totalTrips)
//				right = mid - 1;
//			else
//				left = mid + 1;
//		}
//		return  count < totalTrips ? mid + 1 : mid;
//	}
//};
//
//
//int main()
//{
//	vector<int>time{ 5,10,10 };
//	int totalTrips = 9;
//	cout << Solution().minimumTime(time, totalTrips);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
////class Solution {
////public:
////	int maxScoreSightseeingPair(vector<int>& values) {
////		int ret = 0;
////		for (int i = 0; i < values.size(); i++)
////		{
////			for (int j = 0; j < i; j++)
////			{
////				ret = max(values[j] + values[i] + (j - i), ret);
////			}
////		}
////		return ret;
////	}
////};
//
//class Solution {
//public:
//	int maxScoreSightseeingPair(vector<int>& values) {
//		int prevmax = values[0], ret = 0;
//		for (int i = 1; i < values.size(); i++)
//		{
//			ret = max(prevmax + values[i] - i, ret);
//			prevmax = max(prevmax, values[i] + i);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>values{ 8,1,5,2,6 };
//	cout << Solution().maxScoreSightseeingPair(values);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int prevmin = prices[0], ret = 0;
//		for (int i = 1; i < prices.size(); i++)
//		{
//			ret = max(ret, prices[i] - prevmin);
//			prevmin = min(prevmin, prices[i]);
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
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	size_t pos = s.rfind(' ');
//	if (pos == string::npos)
//		cout << s.size() << endl;
//	else
//		cout << s.size() - pos - 1 << endl;
//	return 0;
//}

//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		vector<int>flag(26, 0);
//		for (auto e : s)
//			flag[e - 'a']++;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (flag[s[i] - 'a'] == 1)
//				return i;
//		}
//		return -1;
//	}
//};
//
//int main()
//{
//	string s("hello world");
//	cout << Solution().firstUniqChar(s);
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		string ret;
//		int begin1 = num1.size() - 1, begin2 = num2.size() - 1;
//		int tmp1, tmp2, flag = 0;
//		while (begin1 >= 0 || begin2 >= 0)
//		{
//			tmp1 = begin1 < 0 ? '0' : num1[begin1--];
//			tmp2 = begin2 < 0 ? '0' : num2[begin2--];
//
//			int sum = tmp1 + tmp2 + flag - 2 * '0';
//			if (sum > 9)
//			{
//				flag = sum / 10;
//				sum %= 10;
//			}
//			else
//				flag = 0;
//			ret += sum + '0';
//		}
//		if (flag > 0)
//			ret += 1 + '0';
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};
//
//int main()
//{
//	string num1("11");
//	string num2("123");
//	cout << Solution().addStrings(num1, num2);
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//	int StrToInt(string str) {
//		int ret = 0;
//		int i = 0;
//		if (str[0] == '-' || str[0] == '+')
//			i++;
//		for (i; i < str.size(); i++)
//		{
//			if (!isdigit(str[i]) || ret > INT_MAX)
//			{
//				ret = 0;
//				break;
//			}
//			ret = ret * 10 + str[i] - '0';
//		}
//		if (str[0] == '-')
//		{
//			if (ret > INT_MAX - 1)
//				return 0;
//			ret *= -1;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string str("+2147483647");
//	cout << Solution().StrToInt(str);
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {

		string ret;
		int begin1 = 0, begin2 = 0;
		int tmp1, tmp2, flag = 0;
		while (begin1 < num1.size() || begin2 < num2.size())
		{
			tmp1 = begin1 >= num1.size() ? '0' : num1[begin1++];
			tmp2 = begin2 >= num2.size() ? '0' : num2[begin2++];

			int sum = tmp1 - '0' + tmp2 - '0' + flag;
			if (sum > 9)
			{
				flag = sum / 10;
				sum %= 10;
			}
			else
				flag = 0;
			ret += sum + '0';
		}
		if (flag > 0)
			ret += 1 + '0';
		return ret;
	}

	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		string ret;
		for (int i = num2.size() - 1; i >= 0; i--)
		{
			string tmp(num2.size() - i - 1, '0');
			int flag = 0;
			for (int j = num1.size() - 1; j >= 0; j--)
			{
				int sum = (num1[j] - '0') * (num2[i] - '0') + flag;
				if (sum > 9)
				{
					flag = sum / 10;
					sum %= 10;
				}
				else
					flag = 0;
				tmp += sum + '0';
			}
			if (flag > 0)
				tmp += flag + '0';
			ret = addStrings(ret, tmp);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	string num1 = "123", num2 = "456";
	cout << Solution().multiply(num1, num2);
	return 0;
}