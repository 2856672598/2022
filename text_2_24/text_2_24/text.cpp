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

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector <int> maxS(nums), minS(nums);
		for (int i = 1; i < nums.size(); ++i) {
			maxS[i] = max(maxS[i - 1] * nums[i], max(nums[i], minS[i - 1] * nums[i]));
			minS[i] = min(minS[i - 1] * nums[i], min(nums[i], maxS[i - 1] * nums[i]));
		}
		return *max_element(maxS.begin(), maxS.end());
	}
};
int main()
{
	vector<int>nums{ -2,0,-1 };
	cout << Solution().maxProduct(nums);
	return 0;
}